"""
Invoke task definitions for the RISC-V CPU simulation flow.

Usage examples
--------------
  inv build                               # compile default TOPLEVEL (rv_cpu)
  inv build --toplevel rv_cpu             # explicit toplevel

  inv sim  --testbench tb_r_type          # R-type ALU tests
  inv sim  --testbench tb_store           # SW / SH / SB tests
  inv sim  --testbench tb_load            # LW / LH / LB / LHU / LBU + roundtrip tests
  inv sim  --testbench tb_r_type --toplevel rv_cpu

  inv run  --testbench tb_r_type          # build + sim in one step
  inv sim_all                             # build once, run every testbench

  inv clean                               # remove sim_build/ and __pycache__/
  inv clean --src                         # also remove symlinked .py / .include

Filelist convention
-------------------
  Each DUT top-level has exactly one filelist:
      src/verif/include/{toplevel}.include
  The testbench Python files live in:
      src/verif/testbench/{testbench}.py
"""

import os
import shutil
from pathlib import Path

from invoke import task
from cocotb_tools.runner import get_runner
from invoke_tools import force_symlink, parse_verilog_include

# Resolved at import time so it stays accurate regardless of later os.chdir calls
SIM_DIR = Path(__file__).parent.resolve()


# ---------------------------------------------------------------------------
# Internal helpers
# ---------------------------------------------------------------------------

def _toplevel(c, toplevel):
    """Return the effective top-level name, falling back to config default."""
    return toplevel or c.SIM_SETUP.TOPLEVEL


def _enter_build_dir(tl: str) -> None:
    """
    Change into the per-DUT build directory, creating it if necessary.

    Always resets to SIM_DIR first so that this function is idempotent
    and safe to call multiple times within the same process (e.g. from run()).
    """
    os.chdir(SIM_DIR)
    build_dir = SIM_DIR / tl
    build_dir.mkdir(exist_ok=True)
    os.chdir(build_dir)


def _remove(path: Path) -> None:
    """Remove a file, symlink, or directory tree."""
    if path.is_symlink() or path.is_file():
        path.unlink()
    elif path.is_dir():
        shutil.rmtree(path)


# ---------------------------------------------------------------------------
# Tasks
# ---------------------------------------------------------------------------

@task
def build(c, toplevel=None):
    """
    Compile the RTL for the given top-level DUT.

    Reads the filelist  src/verif/include/{toplevel}.include  and runs
    Verilator to produce a compiled simulation object in
    sim/{toplevel}/sim_build/.

    This step only needs to be re-run when the RTL changes.  Multiple
    testbenches can be run against the same compiled build.
    """
    tl = _toplevel(c, toplevel)
    _enter_build_dir(tl)

    # Symlink the filelist (named after the toplevel DUT)
    inc_file = f'{tl}.include'
    force_symlink(
        f'{c.SIM_ENV.SRC_VERIF}/include/{inc_file}',
        inc_file,
    )

    sources = parse_verilog_include(c.SIM_ENV.SRC_RTL, inc_file)

    runner = get_runner(c.SIM_SETUP.SIMULATOR)
    runner.build(
        sources=sources,
        hdl_toplevel=tl,
        defines=c.VERILOG_DEFINES,
        build_args=c.BUILD_ARGS,
        timescale=('1ns', '10ps'),
        waves=True,
    )


@task
def sim(c, testbench, toplevel=None):
    """
    Run a cocotb testbench against the pre-built DUT.

    The testbench Python file is taken from
    src/verif/testbench/{testbench}.py and symlinked into the build
    directory automatically.

    The RTL must have been compiled with `inv build` beforehand.
    """
    tl = _toplevel(c, toplevel)
    _enter_build_dir(tl)

    # Symlink ALL Python files from the testbench directory into the build
    # directory. This ensures that shared helpers (e.g. tb_helpers.py) are
    # always present alongside the requested testbench module.
    tb_dir = Path(c.SIM_ENV.SRC_VERIF) / 'testbench'
    for py_file in sorted(tb_dir.glob('*.py')):
        force_symlink(py_file, py_file.name)

    runner = get_runner(c.SIM_SETUP.SIMULATOR)
    runner.test(
        hdl_toplevel=tl,
        hdl_toplevel_lang="verilog",   # Verilator only supports "verilog" (.sv counts as verilog)
        test_module=f'{tl}.{testbench}',
        waves=True,
    )


@task
def run(c, testbench, toplevel=None):
    """
    Compile the RTL and run a testbench in a single step.

    Equivalent to:
        inv build [--toplevel TL]
        inv sim   --testbench TB [--toplevel TL]
    """
    build(c, toplevel=toplevel)
    sim(c, testbench=testbench, toplevel=toplevel)


@task
def sim_all(c, toplevel=None):
    """
    Build the RTL once, then run every discovered testbench.

    Testbenches are auto-discovered by scanning
    src/verif/testbench/ for .py files that contain @cocotb.test().
    Helper-only files (e.g. tb_helpers.py) are automatically excluded.

    A PASS / FAIL summary table is printed at the end.
    Exits with code 1 if any testbench failed.
    """
    # Discover testbenches before entering any build directory
    tb_src_dir = Path('../src/verif/testbench')
    testbenches = sorted(
        p.stem
        for p in tb_src_dir.glob('*.py')
        if '@cocotb.test()' in p.read_text()
    )

    if not testbenches:
        print('No testbenches found.')
        return

    print(f'Discovered {len(testbenches)} testbench(es): {", ".join(testbenches)}')

    # Compile RTL once
    build(c, toplevel=toplevel)

    # Run each testbench and collect pass/fail
    results = {}
    for tb in testbenches:
        sep = '=' * 60
        print(f'\n{sep}\nRunning {tb}\n{sep}')
        try:
            sim(c, testbench=tb, toplevel=toplevel)
            results[tb] = True
        except Exception:
            results[tb] = False

    # Print summary table
    sep = '=' * 60
    print(f'\n{sep}\nsim_all summary\n{sep}')
    col = max(len(tb) for tb in results) + 2
    for tb, passed in results.items():
        print(f'  {tb:<{col}} {"PASS" if passed else "FAIL"}')
    n_fail = sum(1 for v in results.values() if not v)
    n_pass = len(results) - n_fail
    print(f'{sep}\n  {n_pass} passed, {n_fail} failed')

    if n_fail:
        raise SystemExit(1)


@task
def clean(c, toplevel=None, src=False):
    """
    Remove build artifacts for the given top-level.

    By default removes sim_build/ and __pycache__/ only.
    Pass --src to also remove symlinked .py and .include files.
    """
    tl = _toplevel(c, toplevel)
    os.chdir(SIM_DIR)
    build_dir = SIM_DIR / tl

    if not build_dir.exists():
        print(f'Nothing to clean: {build_dir} does not exist')
        return

    # Always remove build outputs
    for name in ('sim_build', '__pycache__'):
        p = build_dir / name
        if p.exists():
            _remove(p)
            print(f'Removed {p}')

    # Optionally remove symlinked source files
    if src:
        for pattern in ('*.py', '*.include'):
            for p in build_dir.glob(pattern):
                _remove(p)
                print(f'Removed {p}')

    print(f'Cleaned sim/{tl}')
