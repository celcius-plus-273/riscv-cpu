from pathlib import Path

def force_symlink(target, link_name):
    """
    Python equivalent of 'ln -s -f target link_name'
    Removes the link_name if it exists before creating the link.
    """
    target = Path(target)
    link_name = Path(link_name)

    # 1. Clean up existing link/file if it exists (The "-f" part)
    if link_name.exists() or link_name.is_symlink():
        # unlink() removes both files and symbolic links
        link_name.unlink()

    # 2. Create the link
    # note: symlink_to arguments are reversed compared to os.symlink
    # link_name.symlink_to(target)
    link_name.symlink_to(target)
    print(f"Linked {link_name} -> {target}")

"""Parses a verilog filelist and returns a list of source files."""
def parse_verilog_include(src_dir, filelist_path):
    sources = []
    with open(filelist_path, 'r') as f:
        for line in f:
            line = line.strip()
            # ignore comments and empty lines
            if line and not line.startswith('//') and not line.startswith('#'):
                sources.append(src_dir + '/' + line)
                print(f"Added source file: {line}")
    return sources
