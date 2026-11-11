# grimace

A CMake toolchain for Windows CE programs and DLLs. It uses clang and lld, then `tools/mkpe.py` turns the linked ELF into a CE PE.

| Target | `GRIMACE_ARCH` | `GRIMACE_CE_VERSION` | Export lists | `GRIMACE_DEVICE` |
| --- | --- | --- | --- | --- |
| MIPS CE 1.0 and 2.0 (Philips Velo 1) | `mips` | `1`, `2` | the Velo 1's ROMs (`exports/velo1-ce1`, `velo1-ce2`) | `velo1` |
| SH3 CE 1.0, 1.01 and 2.0 | `sh3` | `1`, `1.01`, `2` | Microsoft's SH3 SDK import libraries (`exports/sh3-sdk-ce1`, `ce101`, `ce2`) | |
| x86 CE 2.x (Clarion Joyride) | `x86` | `2` | a Joyride ROM (`exports/joyride-ce2`) | `joyride` |
| ARM CE 3.0, Handheld PC 2000 (HP Jornada 720) | `arm` | `3` | the Jornada 720's ROM (`exports/jornada720-ce3`) | `jornada720` |
| ARM CE 6.0 (Sharp Brain) | `arm` | `6` | PW-SH2 and PW-A7300 ROMs (`exports/brain-sh2-ce6`, `brain-a7300-ce6`) | `pwsh2`, `pwsb1`, `pwsh4`, `pwa7300`, `pwg5300` |

## LLVM

MIPS and x86 work with any LLVM that has those backends, such as Homebrew's (`brew install llvm lld cmake`) or Ubuntu's (`apt install clang lld llvm cmake`). Apple's clang has neither.

SH3 needs the `sh3el-unknown-none-wince` target and ARM the `armv4-unknown-none-wince` target, which no LLVM release has. Download [llvm-builds](https://github.com/grimace-sdk/llvm-builds/releases) v3, which has ARM, MIPS and SuperH and the C++ standard library. The macOS binaries aren't notarized: if a browser downloaded the tarball, run `xattr -dr com.apple.quarantine` on the unpacked folder.

The toolchain uses, in order: `GRIMACE_LLVM_ROOT` (a CMake setting or environment variable), `llvm` in this folder (a link to the unpacked release), Homebrew's LLVM, then the `clang` on `PATH`.

## Usage

```cmake
cmake_minimum_required(VERSION 3.20)
project(myapp C)
include(Grimace)

grimace_add_executable(myapp main.c ICON myapp.ico RESOURCES myapp.rc resource.h)
target_link_libraries(myapp PRIVATE grimace::commctrl)

grimace_add_library(mylib mylib.c EXPORTS Add Greeting=greeting_impl)
```

```sh
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/path/to/grimace/cmake/toolchain.cmake -DGRIMACE_ARCH=mips -DGRIMACE_CE_VERSION=2
cmake --build build
```

This gives `build/myapp.exe` and `build/mylib.dll`, with the linked `.elf` beside each.

- `grimace_add_executable(target [EXCLUDE_FROM_ALL] [OUTPUT file.exe] [ICON file.ico] [TEXT_ADDRESS address] [RESOURCES files...] sources...)`: entry point `WinMain`. `TEXT_ADDRESS` links the code at another address than `0x11000`, a multiple of `0x1000`. The image base stays `0x10000`, so the image covers the space between.
- `grimace_add_library(target [EXCLUDE_FROM_ALL] [OUTPUT file.dll] [RESOURCES files...] EXPORTS name[=symbol]... | EXPORTS_FILE file sources...)`: entry point `DllMain`, or one that returns `TRUE` if the library has none. `EXPORTS_FILE` has one export per line.
- `GRIMACE_ARCH`: `mips` (default), `sh3`, `x86` or `arm`. `GRIMACE_CE_VERSION`, the oldest version the program runs on, defaults to `3` for `arm` and `1` otherwise. `_WIN32_WCE` is `100`, `101`, `200`, `300` or `600`.
- `GRIMACE_DEVICE` pins the target to one device's ROM, and `GRIMACE_PLATFORM` (`hpc`, `hpc2000`, `autopc`, `brain`) to one platform's devices. See [Imports](#imports).
- `RESOURCES`: `.rc` files are compiled with `llvm-rc` and linked into `.rsrc` with the icon. Other files listed are dependencies. Set `GRIMACE_RC_INCLUDES` to a list of folders to search for headers too. CE has no `DialogBoxParamW`: use `FindResource`, `LoadResource` and `DialogBoxIndirectParamW`.
- `llvm-rc` needs the comma after a control's text or name (`LTEXT "Text", -1, 5, 5, 50, 12`), and keeps the leading spaces of a line continued with `\`. Microsoft's rc does neither.
- The PE has subsystem 9 (Windows CE GUI) with the CE version, as Microsoft's linkers write. CE 2.0 treats a program marked 1.0 as a CE 1.0 program, with another system font for client-area text.
- `CMAKE_BUILD_TYPE` defaults to `MinSizeRel` (`-Os`, plus `-fomit-frame-pointer` on ARM). `Debug` gives `-O0 -g`.
- `examples/CMakePresets.json` has a Debug preset for each target.

## Imports

Each folder in `exports/` is a ROM's or SDK's export lists, one `<dll>.txt` per DLL, with a `MANIFEST` giving its architecture, CE version, platform, devices and source. Devices with identical lists share a folder. `python3 tools/manifests.py` lists them.

A target imports from the lists of its architecture at its CE version and later, since the program may run on any of those devices, but only those of the platforms with lists at its own version: ARM CE 3.0 programs don't import from the Brain's CE 6.0 lists.

- A function all of them export is a direct import, which the loader binds.
- A function only some of them export is a lazy import. Its first call loads the DLL and looks the function up with `GetProcAddressW`, also trying the name with or without a trailing `W` (CE 1.0 exports `FindResource`, CE 2.0 `FindResourceW`). If the device lacks it, the call sets `ERROR_CALL_NOT_IMPLEMENTED` and returns 0.
- A function none of them export is a compile error, as before.

`ce_has(function)` says whether the device has a function: always true for a direct import, and for a lazy one it binds it and says whether that worked. Use it before calling a lazy import where 0 isn't a failure, or to fall back to something else:

```c
if (ce_has(GetModuleFileNameW)) {
    GetModuleFileNameW(NULL, path, MAX_PATH);
}
```

With `GRIMACE_DEVICE` the target imports exactly what that device's ROM exports at its CE version, all direct, and anything else is a compile error. With `GRIMACE_PLATFORM`, only that platform's lists count. Configuring prints how many direct and lazy imports the target gets.

`grimace::<dll>` links a DLL's import library, and `grimace::coredll` is always linked. Each is a set of weak stubs, so only the functions a program calls end up in it, and a program's own definition of a name overrides the import. A direct import's stub jumps through a slot in `.iat.<DLL>.<name>`. A lazy one's jumps through a pointer that starts at a thunk calling `__grimace_lazy_bind` (`runtime/lazy.c`), which stores what it found there.

`tests/lazy` calls a few lazy imports and reports what it found. `make check-lazy` builds it for every target. Run on the devices, the MIPS CE 1.0 build binds on CE 2.0 and reports missing functions on CE 1.0, and the SH3 CE 1.0 build binds on an HP 620LX (CE 2.0).

## Packages

`grimace_package()` packages programs as a CAB, which wceload installs on CE 2.0 and later, and a zip of the same files:

```cmake
grimace_package("My App" PROVIDER "Me"
    TARGETS myapp mylib
    FILES readme.txt
    SHORTCUTS myapp "My App")
```

`cmake --build build --target packages` writes `build/packages/MyApp-<target>.cab` and `.zip`, where `<target>` is the architecture and version (`mips-ce2`), plus the platform or device if set.

- `DIRECTORY`: where they go, default `%CE1%\<name>` (`\Program Files\<name>`). wceload on the Handheld PC 2000 asks first, starting there.
- `SHORTCUTS`: pairs of a target and the name of its shortcut in the Start menu's Programs (`%CE11%`).
- `FORMATS`: `cab`, `zip` or both (the default).
- CE 1.0 has no CAB installer, so copy the zip's files across, or install velo-ce1-cab's CE 2.0 wceload first.

`tools/cab.py` writes uncompressed cabinets with the setup file (`.000`) wceload reads. The examples' CAB installs with the Jornada 720's own wceload, with its files and shortcuts.

### Every target at once

A toolchain file builds for one target, so `cmake/GrimaceMatrix.cmake` builds a project for several, each in its own folder, and gathers their packages:

```cmake
cmake_minimum_required(VERSION 3.20)
project(myapp_all NONE)
include(/path/to/grimace/cmake/GrimaceMatrix.cmake)

grimace_matrix(NAME "My App" SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/app PACKAGE
    TARGETS mips-ce1 sh3-ce1 x86-ce2 arm-ce3)
```

- Targets are `<arch>-ce<version>`, with `ce101` for 1.01, and an optional `-<device>`: `mips-ce1-velo1`.
- `GRIMACE_MIPS_LLVM`, `GRIMACE_SH3_LLVM`, `GRIMACE_X86_LLVM` and `GRIMACE_ARM_LLVM` (settings or environment variables) choose each architecture's LLVM. `CMAKE_ARGS` passes more settings to every build.
- With `PACKAGE`, `build/packages` gets every target's CAB and zip, and `<NAME>.ini` for the desktop Application Manager. It lists one CAB per processor, the build for the lowest version, which runs on later ones too.

`make packages` builds `examples/matrix`, the examples for every target.

## Headers and runtime

The Win32 headers are CeGCC's w32api (public domain) in `include/w32api`, patched to match the Windows CE 1.0, 2.0 and 3.0 SDKs. `include/w32api/VENDOR.md` lists the patches. `include/` wraps them:

- `#include <windows.h>` gives the API as the target has it. `UNICODE` is defined, and it brings in the C runtime headers and the object store database (`windbase.h`).
- Calling a function the target's ROM doesn't export is a compile error, e.g. `'GetModuleFileNameW' is unavailable: not in Windows CE 1.0`.
- On CE 3.0, declarations generated from the Handheld PC 2000 SDK (`include/grimace/sdk`) add COM and OLE, the shell, WinInet, crypto and security, the address book and mail store, and others. Define `GRIMACE_NO_SDK` to leave them out. CE 1.0 and 2.0 don't get them.
- `STRICT` is on, so handle types are distinct. Define `NO_STRICT` for SDK code that mixes them.
- CE exports some wide functions without the `W` (`FindResource`, `GetVersionEx`, `GetClassLong`, the `Ras` and `acm` functions): either name works.
- Every function the ROMs export has a docstring and named parameters, from `docs/api`, with the versions that have it where they differ.
- `windowsx.h` has the SDK's message crackers. Include it yourself, except on CE 1.01, whose `windows.h` includes it.

`grimace::runtime` is always linked, and a program only gets the parts it calls:

- compiler-rt builtins (soft float, 64-bit division), `memcpy`, `memmove`, `memset` and `memcmp`.
- `runtime/libc`: the C library CE 3.0's coredll exports, for the targets whose coredll lacks it. A function is built from here unless every device the target covers exports it, so CE 1.0 and 2.0 programs get stdio, `printf` and `scanf`, `malloc`, the string, `ctype` and `stdlib` functions, maths and `setjmp`. CE 3.0 programs use the ROM's. The maths is musl's (MIT, `runtime/libc/math/README`). Microsoft's Bessel functions (`_j0` and so on) aren't there, so they're unavailable below CE 3.0.
- `runtime/c99`: the C99 functions libc++ needs that Microsoft's C library lacks, over whichever one the target has: `snprintf`, `strtoll`, `float` and `long double` maths, `errno`, `wmemcpy` and others. `swprintf` keeps Microsoft's form; define `GRIMACE_C99_SWPRINTF` for C99's.

`runtime/libc` behaves as CE 3.0's coredll does where they differ from C99, so a program prints and reads the same on every version: `printf` writes three exponent digits (`1e+006`), `1.#INF` and `1.#QNAN`, and rounds halfway decimals away from zero, from the exact binary value. `strtod` and `scanf` round correctly. Files open in text mode unless the mode has `b`, with `\r\n` on disk for `\n`. `stdout` and `stderr` go to the debug output a line at a time, and `stdin` is always at its end. Narrow file names and strings in wide functions are Latin-1.

`tests/libc/host.c` (`make check-libc-host`) checks the formatting, `strtod` and `scanf` engines against this computer's C library. `tests/libc/device` (`make check-libc`) checks the C library on a device: it passes on the Velo's CE 1.0 and 2.0 ROMs, an HP 620LX (SH3 CE 2.0) and the Jornada 720, whose ROM's C library it also checks.

## C++

`.cpp` files are compiled as C++20 with `-fno-exceptions -fno-rtti -fno-threadsafe-statics`. `project(myapp C)` is enough: `Grimace` enables C++ itself.

- A target linked as C++ gets `grimace::cxx_runtime`: global constructors and destructors, `operator new` and `delete` on `LocalAlloc`, `__cxa_atexit` and `__cxa_pure_virtual`. Its entry point runs the constructors, calls `WinMain` or `DllMain`, then the destructors.
- The headers' functions have C linkage in C++. Functions a DLL exports need `extern "C"`.
- `include/grimace/cxx` is a header-only C++ layer: RAII handles, results instead of exceptions, a checked `format`, and a window base. See [its README](include/grimace/cxx/README.md).
- On CE 3.0 with llvm-builds v3, the C++ standard library works: strings, containers, `<algorithm>`, `optional`, `variant`, smart pointers, `std::function`, ranges and `std::format`, without threads, locales, iostreams, filesystem or exceptions. See `examples/stl-text` and `examples/stl-collections`. Elsewhere, `include/new` and `include/initializer_list` are the only standard library headers.

## debugmgr

`debugmgr.exe` runs on the device and lets `tools/grimace-debug` copy files, list folders and start and stop programs. The protocol is in `debugmgr/PROTOCOL.md`.

- CE 3.0 (`debugmgr/*.cpp`): over TCP, port 2100, or an emulator's host mailbox when started with `mailbox`. Set `GRIMACE_DEVICE` to the device's address, or `GRIMACE_AGENT` to an emulator's agent socket.
- CE 1.0 and 2.0 (`debugmgr/debugmgr.c`): over an emulator's host mailbox only, on MIPS and SH3. On SH3 it's `grimace-debugmgr.exe`, so the ROM's `debugmgr.exe` doesn't shadow it. There's no x86 build.

Anything that can reach the TCP port can copy files to the device and run programs, so only leave it running on a network you trust.

## Notes

- CE 1.0 has no `GetModuleFileNameW`, and `LoadLibraryW` doesn't search the program's folder. DLLs normally go in `\Windows`, or pass a full path (see `examples/dll`).
- A DLL's import tables go in a 0x200 byte space before its IAT. `mkpe.py` says if a DLL needs more: `target_link_options(mylib PRIVATE --defsym=GRIMACE_IMPORT_RESERVE=0x400)`.
- `tools/grimace-cc` filters clang's "MIPS-I support is experimental" warning on MIPS.
- Zero-initialised data takes no space in the file: `.data`'s virtual size covers it, as Microsoft's linker does.
- Programs and DLLs have no `.pdata`, so CE can't unwind their frames: `__try` doesn't work in them, and a fault inside a window procedure ends the process.
- The ARM target follows Microsoft's CE ARM calling standard as eVC3 compiles it; `make check-abi` checks it.
- ARM CE 6.0 targets ARMV4I: code is built for ARMv4T and returns with `bx`, as do the import stubs, so Thumb code in the ROM can call it and be called.
- `ceddk.h`, `msgqueue.h` and `pm.h` declare what CE 6.0 drivers use, checked against Platform Builder 6.0. `tests/ce6` builds a program, a control panel applet and a stream driver DLL.

## Make

| Target | |
| --- | --- |
| `examples-<target>`, `debugmgr-<target>` | build into `build/<target>` and `build/debugmgr/<target>`, for `mips-ce1`, `mips-ce2`, `sh3-ce1`, `sh3-ce101`, `sh3-ce2`, `x86-ce2`, `arm-ce3` and `arm-ce6` |
| `examples`, `debugmgr` | all targets, but no x86 debugmgr |
| `packages-<target>`, `packages` | package the examples for a target, or build and package them for every target (`examples/matrix`) |
| `check-cxx-headers-<arch>` | the headers declare C functions with C linkage in C++, and the C++ layer compiles, for each CE version of `mips`, `sh3`, `x86` or `arm` |
| `check-headers` | compare the headers with each SDK's (`GRIMACE_REFERENCE`, a folder with `include/ce100`, `ce101`, `ce200` and `ce300`) |
| `check-abi`, `check-stdlib`, `check-debugmgr` | the ARM calling standard, the C++ standard library on CE 3.0, and debugmgr with `grimace-debug` on this computer |
| `check-lazy`, `check-lazy-<target>` | build `tests/lazy` |
| `check-libc`, `check-libc-<target>`, `check-libc-host` | build `tests/libc/device`, and run `tests/libc/host.c` here |
| `check-ce6` | build `tests/ce6` for ARM CE 6.0 and each Brain, and check with `tests/check-imports.py` that every import is in the device's lists |
| `check` | `check-abi`, `check-cxx-headers`, `check-stdlib`, `check-debugmgr`, `check-lazy`, `check-libc`, `check-ce6`, `examples` and `debugmgr` |
| `headers` | regenerate `include/` from a CeGCC checkout's w32api (`GRIMACE_W32API`) and the SDKs (`GRIMACE_REFERENCE`) |
| `docstrings` | rewrite the docstrings from `docs/api` |
| `exports` | read `exports/jornada720-ce3` from a Jornada 720 ROM image (`GRIMACE_ROM`). `tools/cerom.py` also reads CE 6.0 ROMs |

Set `GRIMACE_MIPS_LLVM`, `GRIMACE_SH3_LLVM`, `GRIMACE_X86_LLVM` or `GRIMACE_ARM_LLVM` to choose an LLVM for that architecture's targets and checks. Set `DEVICE` or `PLATFORM` to build for one device or platform, into `build/<target>-<device>`: `make examples-mips-ce1 DEVICE=velo1`.

`make headers` runs, in order:

- `tools/vendor-w32api.py`: copies and patches w32api.
- `tools/mksdk.py`: writes `include/grimace/sdk` from the Handheld PC 2000 SDK, for the functions the Jornada 720 exports that w32api lacks.
- `tools/mkheaders.py`: writes the wrappers, `grimace/aliases.h`, `grimace/unavailable.h` and `grimace/lazy-imports.h` from `exports/`, with a section for each architecture and version, platform and device.
- `tools/mkconstants.py` and `tools/mksdkconstants.py`: write `grimace/constants.h` and `grimace/types.h` (CE 1.0, 1.01 and 2.0) and `grimace/constants-sdk.h` (CE 3.0), with the SDK constants, macros and types the headers lack.
- `tools/mkdocs.py`: writes the docstrings from `docs/api` above each declaration and names its parameters. Entries in `docs/api/sdk` fill in macros, messages and structures `docs/api` doesn't cover.

## Licence

MIT, see `LICENSE`. `include/w32api` is public domain (`README.w32api`), and `runtime/compiler-rt` is LLVM's, under Apache 2.0 with LLVM exceptions (`LICENSE.TXT`).
