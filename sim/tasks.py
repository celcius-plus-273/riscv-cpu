from invoke import task
from cocotb_tools.runner import get_runner
from invoke_tools import *
import os
import shutil
from pathlib import Path

@task
def link(c):
    """
    Link source directories (Equivalent to 'make link').
    Note: Modify this task if your directory structure is different
    """
    stage = c.SIM_SETUP.STAGE or "behav"
    try:
        os.chdir(stage)
    except:
        print(f"Error: Simulation stage directory '{stage}' does not exist")
        return

    # Define your paths (fetch from env or defaults)
    rtl_folder  = c.SIM_ENV.SRC_RTL or "../../src/rtl"
    src_verif   = c.SIM_ENV.SRC_VERIF or "../../src/verif"
    src_scan   = c.SIM_ENV.SRC_SCAN or "../../src/scan"
    testbench   = src_verif + "/testbench" + f"/{c.SIM_SETUP.TESTBENCH}.py"

    # 1. ln -s -f $(RTL_FOLDER) .
    # When linking a folder to '.', the link name is the folder name
    # force_symlink(rtl_folder, "rtl")

    # 2. ln -s -f $(TB_FOLDER) .
    # force_symlink(tb_folder, Path(tb_folder).name)
    force_symlink(testbench, Path(testbench).name)

    # 3. ln -s -f $(SRC_VERIF)/scripts .
    force_symlink(f"{src_verif}/scripts", "scripts")
    force_symlink(f"{src_verif}/cocotb_tasks", "cocotb_tasks")

    # 4. ln -s -f $(SRC_SCAN) .
    # force_symlink(src_scan, "scan")

    # 4. ln -s -f $(SRC_VERIF)/include/$(TESTBENCH).include .
    include_file = f"{c.SIM_SETUP.TESTBENCH}.include"
    force_symlink(f"{src_verif}/include/{include_file}", include_file)

@task
def vcs(c):
    """
    Run the cocotb testbench using Synopsys VCS.
    """
    # Change to corresponding simulation directory based on stage (behav, syn. apr)
    stage = c.SIM_SETUP.STAGE or "behav"
    try:
        os.chdir(stage)
    except:
        print(f"Error: Simulation stage directory '{stage}' does not exist")
        return

    # Parse Configuration and Build Flags
    src_dir = c.SIM_ENV.PRJ_DIR + "/src"
    sources = parse_verilog_include(src_dir, f"{c.SIM_SETUP.TESTBENCH}.include")     # verilog sources from .include file
    vcs_build_args = c.BUILD_ARGS                                           # VCS arguments
    # sim_plusargs = c.SIM_PLUSARGS                                           # plusargs (TODO: not needed for python cocotb)
    compile_defines = c.VERILOG_DEFINES                                     # +defines for VCS
    # module_params = c.RTL_PARAMS                                            # top level module parameters
    testbench = f'{c.SIM_SETUP.STAGE}.{c.SIM_SETUP.TESTBENCH}'    # cocotb testbench (without the .py)

    # Include directories (e.g. Synopsys DesignWare)
    include_dirs = []
    SYNOPSYS_HOME = c.SIM_ENV.SYNOPSYS_HOME
    if SYNOPSYS_HOME:
        include_dirs.append(f"{SYNOPSYS_HOME}/syn/latest/dw/sim_ver")
    else:
        print("Warning: $SYNOPSYS env var not set. DesignWare includes may fail.")

    # Cocotb Sim Runner
    runner = get_runner(c.SIM_SETUP.SIMULATOR)

    # Build (Compile)
    runner.build(
        sources=sources,
        hdl_toplevel=c.SIM_SETUP.TOPLEVEL,
        includes=include_dirs,      # VCS includedir
        defines=compile_defines,
        build_args=vcs_build_args,
        # parameters=module_params,
        # timescale=("1ns", "10ps"), # THIS DOES NOT WORK... SPECIFY TIMESCALE ON YOUR TOP LEVEL MODULE
        always=True,
        # waves=True
    )

    # Run (Simulate)
    runner.test(
        hdl_toplevel=c.SIM_SETUP.TOPLEVEL,
        test_module=testbench,
        # plusargs=sim_plusargs,
        waves=True
    )

@task
def run_testbench(c):
    pass

@task
def clean(c, src=False):
    """
    Clean up build artifacts
    """

    # Define paths to clean up (sim artifacts/outputs)
    clean_paths = [
        "sim_build",
        "__pycache__",
        "csrc",
        "simv.daidir",
        "ucli.key",
        "simv",
        "sim_build"
    ]

    # Sources to be cleaned if 'src' flag is set
    src_paths = [
        "rtl",
        "testbench",
        "scripts",
        "cocotb_tasks",
        "scan",
    ]

    wildcard_names = [
        "tb_*.include",
        "tb_*.py"
    ]

    if src:
        clean_paths.extend(src_paths) # extenc vs append?

    for path in clean_paths:
        full_path = f'{c.SIM_SETUP.STAGE}/{path}'
        if os.path.exists(full_path):
            if os.path.islink(full_path):
                os.unlink(full_path)
            elif os.path.isdir(full_path):
                shutil.rmtree(full_path)
            else:
                os.remove(full_path)
            print(f"Removed {full_path}")

    for name in wildcard_names:
        for path in Path(c.SIM_SETUP.STAGE).glob(name):
            os.remove(path)
            print(f"Removed {path}")

    print(f"{c.SIM_SETUP.STAGE} has been cleaned")
