"""
Package a program for Windows CE from a JSON description, written by grimace_package():

    {"name": "Hello", "provider": "Example", "arch": "mips", "label": "mips-ce2",
     "directory": "%CE1%\\\\Hello", "files": [{"path": "/build/hello.exe", "name": "hello.exe"}],
     "shortcuts": [{"file": "hello.exe", "name": "Hello", "directory": "%CE11%"}],
     "registry": [{"root": "HKLM", "key": "Software\\\\Example", "name": "Installed", "value": 1}],
     "output": "/build/packages", "formats": ["cab", "zip", "exe"], "installer": "/build/ceinstall.exe"}

The CAB installs the files with wceload, on CE 2.0 and later. The zip holds the same files, in a folder named after the
program, for copying by hand. The exe is a self-installer (installer/ceinstall.c with the files appended, written by
selfinstall.py), which also installs on CE 1.0; running it again removes the program.

With --collect, gather the CABs and zips from several build folders into one, with a CEAppMgr .ini listing a CAB per
processor, so the desktop Application Manager installs the one for the connected device. That's the build for the lowest
version, which runs on later ones too.
"""
import argparse
import glob
import json
import os
import re
import shutil
import sys
import zipfile

import cab
import selfinstall


def package_name(description):
    return "%s-%s" % ("".join(character for character in description["name"] if character.isalnum() or character in "-_") or "package",
                      description["label"])


def write_cab(description, path):
    package = cab.Package(description["name"], description.get("provider", ""), architecture=cab.ARCHITECTURES[description["arch"]])
    setup = package.setup
    directory = description["directory"]
    setup.directory(directory)
    identifiers = {}
    for item in description["files"]:
        target = item.get("directory", directory)
        setup.directory(target)
        with open(item["path"], "rb") as source:
            identifiers[item["name"].lower()] = package.add_file(target, item["name"], source.read())
    for shortcut in description.get("shortcuts", []):
        name = shortcut["name"] if shortcut["name"].lower().endswith(".lnk") else shortcut["name"] + ".lnk"
        setup.shortcut(shortcut.get("directory", "%CE11%"), name, identifiers[shortcut["file"].lower()])
    for value in description.get("registry", []):
        setup.value(value["root"], value["key"], value["name"], value["value"])
    with open(path, "wb") as output:
        output.write(package.build())


def write_zip(description, path):
    folder = description["name"]
    with zipfile.ZipFile(path, "w", zipfile.ZIP_DEFLATED) as archive:
        for item in description["files"]:
            archive.write(item["path"], "%s/%s" % (folder, item["name"]))


def write_exe(description, path):
    with open(description["installer"], "rb") as stub:
        installer = selfinstall.plan_from_description(description).build(stub.read())
    with open(path, "wb") as output:
        output.write(installer)


def build(description_path):
    with open(description_path) as source:
        description = json.load(source)
    os.makedirs(description["output"], exist_ok=True)
    base = os.path.join(description["output"], package_name(description))
    written = []
    if "cab" in description["formats"]:
        write_cab(description, base + ".cab")
        written.append(base + ".cab")
    if "zip" in description["formats"]:
        write_zip(description, base + ".zip")
        written.append(base + ".zip")
    if "exe" in description["formats"]:
        write_exe(description, base + "-setup.exe")
        written.append(base + "-setup.exe")
    return written


VERSION_ORDER = {"1": 0, "101": 1, "2": 2, "3": 3, "6": 4}
LABEL = re.compile(r"-(mips|sh3|x86|arm)-ce(1|101|2|3|6)(-[^.]+)?\.cab$")


def choose_cabs(names):
    """One CAB per processor for the Application Manager: the lowest version's, preferring a build for any device."""
    chosen = {}
    for name in names:
        match = LABEL.search(name)
        if not match:
            continue
        rank = (bool(match.group(3)), VERSION_ORDER[match.group(2)])
        if match.group(1) not in chosen or rank < chosen[match.group(1)][0]:
            chosen[match.group(1)] = (rank, name)
    return [name for _, name in sorted(chosen.values(), key=lambda item: item[1])]


def collect(folders, output, name):
    os.makedirs(output, exist_ok=True)
    copied = []
    for folder in folders:
        for path in sorted(glob.glob(os.path.join(folder, "*.cab")) + glob.glob(os.path.join(folder, "*.zip")) + glob.glob(os.path.join(folder, "*.exe"))):
            shutil.copyfile(path, os.path.join(output, os.path.basename(path)))
            copied.append(os.path.basename(path))
    cabs = choose_cabs(copied)
    if cabs:
        component = name or os.path.basename(cabs[0]).split("-", 1)[0]
        with open(os.path.join(output, component + ".ini"), "w", newline="\r\n") as ini:
            ini.write("[CEAppManager]\nVersion = 1.0\nComponent = %s\n\n[%s]\nDescription = %s\nCabFiles = %s\n" %
                      (component, component, component, ",".join(cabs)))
    return cabs


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Package a Windows CE program as a CAB, a zip and a self-installer, or collect packages from several builds")
    parser.add_argument("description", nargs="?", help="JSON description from grimace_package()")
    parser.add_argument("--collect", nargs="+", metavar="FOLDER", help="package folders to gather")
    parser.add_argument("--output", help="folder to gather them into, with --collect")
    parser.add_argument("--name", help="Application Manager component name, with --collect")
    arguments = parser.parse_args()
    if arguments.collect:
        if not arguments.output:
            sys.exit("mkpackage: --collect needs --output")
        print("mkpackage: %d CABs in %s" % (len(collect(arguments.collect, arguments.output, arguments.name)), arguments.output))
    elif arguments.description:
        for path in build(arguments.description):
            print("mkpackage: wrote %s" % path)
    else:
        parser.error("give a description or --collect")
