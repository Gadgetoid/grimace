# grimace

A CMake toolchain for Windows CE programs and DLLs. It uses clang and lld, then `tools/mkpe.py` turns the linked ELF into a CE PE.

| Target | `GRIMACE_ARCH` | `GRIMACE_CE_VERSION` | Import libraries from |
| --- | --- | --- | --- |
| MIPS CE 1.0 and 2.0 (Philips Velo 1) | `mips` | `1`, `2` | the Velo 1's ROMs (`exports/ce1`, `exports/ce2`) |
| SH3 CE 1.0, 1.01 and 2.0 | `sh3` | `1`, `1.01`, `2` | Microsoft's SH3 SDK import libraries (`exports/ce1-sh3`, `ce101-sh3`, `ce2-sh3`) |
| x86 CE 2.x (Clarion Joyride) | `x86` | `2` | a Joyride ROM (`exports/ce2-x86`) |
| ARM CE 3.0, Handheld PC 2000 (HP Jornada 720) | `arm` | `3` | the Jornada 720's ROM (`exports/ce3-arm`) |

## LLVM

MIPS and x86 work with any LLVM that has those backends, such as Homebrew's (`brew install llvm lld cmake`) or Ubuntu's (`apt install clang lld llvm cmake`). Apple's clang has neither.

SH3 needs the `sh3el-unknown-none-wince` target and ARM the `armv4-unknown-none-wince` target, which no LLVM release has. Download [velo-llvm-builds](https://github.com/Gadgetoid/velo-llvm-builds/releases) v3, which has ARM, MIPS and SuperH and the C++ standard library. The macOS binaries aren't notarized: if a browser downloaded the tarball, run `xattr -dr com.apple.quarantine` on the unpacked folder.

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

- `grimace_add_executable(target [EXCLUDE_FROM_ALL] [OUTPUT file.exe] [ICON file.ico] [RESOURCES files...] sources...)`: entry point `WinMain`.
- `grimace_add_library(target [EXCLUDE_FROM_ALL] [OUTPUT file.dll] [RESOURCES files...] EXPORTS name[=symbol]... | EXPORTS_FILE file sources...)`: entry point `DllMain`. `EXPORTS_FILE` has one export per line.
- `GRIMACE_ARCH`: `mips` (default), `sh3`, `x86` or `arm`. `GRIMACE_CE_VERSION` defaults to `3` for `arm` and `1` otherwise. `_WIN32_WCE` is `100`, `101`, `200` or `300`.
- `RESOURCES`: `.rc` files are compiled with `llvm-rc` and linked into `.rsrc` with the icon. Other files listed are dependencies. Set `GRIMACE_RC_INCLUDES` to a list of folders to search for headers too. CE has no `DialogBoxParamW`: use `FindResource`, `LoadResource` and `DialogBoxIndirectParamW`.
- `llvm-rc` needs the comma after a control's text or name (`LTEXT "Text", -1, 5, 5, 50, 12`), and keeps the leading spaces of a line continued with `\`. Microsoft's rc does neither.
- The PE has subsystem 9 (Windows CE GUI) with the CE version, as Microsoft's linkers write. CE 2.0 treats a program marked 1.0 as a CE 1.0 program, with another system font for client-area text.
- `CMAKE_BUILD_TYPE` defaults to `MinSizeRel` (`-Os`, plus `-fomit-frame-pointer` on ARM). `Debug` gives `-O0 -g`.
- `examples/CMakePresets.json` has a Debug preset for each target.

## Import libraries

`grimace::<dll>` links against a DLL from the target's export lists. `grimace::coredll` is always linked. Only the functions a program calls end up in its import table.

Each import library is a set of weak stubs with a 4-byte slot per function in `.iat.<DLL>.<name>`, so unused stubs are dropped by `--gc-sections` and a program's own definition of a name overrides the import.

## Headers and runtime

The Win32 headers are CeGCC's w32api (public domain) in `include/w32api`, patched to match the Windows CE 1.0, 2.0 and 3.0 SDKs. `include/w32api/VENDOR.md` lists the patches. `include/` wraps them:

- `#include <windows.h>` gives the API as the target has it. `UNICODE` is defined, and it brings in the C runtime headers and the object store database (`windbase.h`).
- Calling a function the target's ROM doesn't export is a compile error, e.g. `'GetModuleFileNameW' is unavailable: not in Windows CE 1.0`.
- On CE 3.0, declarations generated from the Handheld PC 2000 SDK (`include/grimace/sdk`) add COM and OLE, the shell, WinInet, crypto and security, the address book and mail store, and others. Define `GRIMACE_NO_SDK` to leave them out. CE 1.0 and 2.0 don't get them.
- `STRICT` is on, so handle types are distinct. Define `NO_STRICT` for SDK code that mixes them.
- CE exports some wide functions without the `W` (`FindResource`, `GetVersionEx`, `GetClassLong`, the `Ras` and `acm` functions): either name works.
- Every function the ROMs export has a docstring and named parameters, from `docs/api`, with the versions that have it where they differ.
- `windowsx.h` has the SDK's message crackers. Include it yourself, except on CE 1.01, whose `windows.h` includes it.

`grimace::runtime` is always linked: compiler-rt builtins (soft float, 64-bit division), `memcpy`, `memmove`, `memset` and `memcmp`, then:

- CE 1.0 and 2.0 (`runtime/nocrt`): `swprintf` and `vswprintf` over coredll's `wsprintfW`, which has no floating point and writes at most 1023 characters. Coredll has no other C library, so the stdio, maths and allocation functions are unavailable: use `LocalAlloc`, `wsprintfW` and your own maths.
- CE 3.0 (`runtime/crt`): coredll has the C runtime (stdio, maths, `malloc`, `printf`, `setjmp`). The runtime adds the C99 functions libc++ needs that coredll lacks: `snprintf`, `strtoll`, `float` and `long double` maths, `errno`, `wmemcpy` and others. `swprintf` keeps Microsoft's form; define `GRIMACE_C99_SWPRINTF` for C99's.

## C++

`.cpp` files are compiled as C++20 with `-fno-exceptions -fno-rtti -fno-threadsafe-statics`. `project(myapp C)` is enough: `Grimace` enables C++ itself.

- A target linked as C++ gets `grimace::cxx_runtime`: global constructors and destructors, `operator new` and `delete` on `LocalAlloc`, `__cxa_atexit` and `__cxa_pure_virtual`. Its entry point runs the constructors, calls `WinMain` or `DllMain`, then the destructors.
- The headers' functions have C linkage in C++. Functions a DLL exports need `extern "C"`.
- `include/grimace/cxx` is a header-only C++ layer: RAII handles, results instead of exceptions, a checked `format`, and a window base. See [its README](include/grimace/cxx/README.md).
- On CE 3.0 with velo-llvm-builds v3, the C++ standard library works: strings, containers, `<algorithm>`, `optional`, `variant`, smart pointers, `std::function`, ranges and `std::format`, without threads, locales, iostreams, filesystem or exceptions. See `examples/stl-text` and `examples/stl-collections`. Elsewhere, `include/new` and `include/initializer_list` are the only standard library headers.

## debugmgr

`debugmgr.exe` runs on the device and lets `tools/grimace-debug` copy files, list folders and start and stop programs. The protocol is in `debugmgr/PROTOCOL.md`.

- CE 3.0 (`debugmgr/*.cpp`): over TCP, port 2100, or an emulator's host mailbox when started with `mailbox`. Set `GRIMACE_DEVICE` to the device's address, or `GRIMACE_AGENT` to an emulator's agent socket.
- CE 1.0 and 2.0 (`debugmgr/debugmgr.c`): over an emulator's host mailbox only. On SH3 it's `grimace-debugmgr.exe`, so the ROM's `debugmgr.exe` doesn't shadow it.

Anything that can reach the TCP port can copy files to the device and run programs, so only leave it running on a network you trust.

## Notes

- CE 1.0 has no `GetModuleFileNameW`, and `LoadLibraryW` doesn't search the program's folder. DLLs normally go in `\Windows`, or pass a full path (see `examples/dll`).
- A DLL's import tables go in a 0x200 byte space before its IAT. `mkpe.py` says if a DLL needs more: `target_link_options(mylib PRIVATE --defsym=GRIMACE_IMPORT_RESERVE=0x400)`.
- `tools/grimace-cc` filters clang's "MIPS-I support is experimental" warning on MIPS.
- Programs and DLLs have no `.pdata`, so CE can't unwind their frames: `__try` doesn't work in them, and a fault inside a window procedure ends the process.
- The ARM target follows Microsoft's CE ARM calling standard as eVC3 compiles it; `make check-abi` checks it.

## Make

| Target | |
| --- | --- |
| `examples-<target>`, `debugmgr-<target>` | build into `build/<target>` and `build/debugmgr/<target>`, for `mips-ce1`, `mips-ce2`, `sh3-ce1`, `sh3-ce101`, `sh3-ce2`, `x86-ce2` and `arm-ce3` |
| `examples`, `debugmgr` | all targets |
| `check-cxx-headers-<arch>` | the headers declare C functions with C linkage in C++, and the C++ layer compiles, for each CE version of `mips`, `sh3`, `x86` or `arm` |
| `check-headers` | compare the headers with each SDK's (`GRIMACE_REFERENCE`, a folder with `include/ce100`, `ce101`, `ce200` and `ce300`) |
| `check-abi`, `check-stdlib`, `check-debugmgr` | the ARM calling standard, the C++ standard library on CE 3.0, and debugmgr with `grimace-debug` on this computer |
| `check` | `check-abi`, `check-cxx-headers`, `check-stdlib`, `check-debugmgr`, `examples` and `debugmgr` |
| `headers` | regenerate `include/` from a CeGCC checkout's w32api (`GRIMACE_W32API`) and the SDKs (`GRIMACE_REFERENCE`) |
| `docstrings` | rewrite the docstrings from `docs/api` |
| `exports` | read `exports/ce3-arm` from a Jornada 720 ROM image (`GRIMACE_ROM`) |

Set `GRIMACE_MIPS_LLVM`, `GRIMACE_SH3_LLVM`, `GRIMACE_X86_LLVM` or `GRIMACE_ARM_LLVM` to choose an LLVM for that architecture's targets and checks.

`make headers` runs, in order:

- `tools/vendor-w32api.py`: copies and patches w32api.
- `tools/mksdk.py`: writes `include/grimace/sdk` from the Handheld PC 2000 SDK, for the functions the Jornada 720 exports that w32api lacks.
- `tools/mkheaders.py`: writes the wrappers, `grimace/aliases.h` and `grimace/unavailable.h` from `exports/`.
- `tools/mkconstants.py` and `tools/mksdkconstants.py`: write `grimace/constants.h` and `grimace/types.h` (CE 1.0, 1.01 and 2.0) and `grimace/constants-sdk.h` (CE 3.0), with the SDK constants, macros and types the headers lack.
- `tools/mkdocs.py`: writes the docstrings from `docs/api` above each declaration and names its parameters. Entries in `docs/api/sdk` fill in macros, messages and structures `docs/api` doesn't cover.

## Licence

MIT, see `LICENSE`. `include/w32api` is public domain (`README.w32api`), and `runtime/compiler-rt` is LLVM's, under Apache 2.0 with LLVM exceptions (`LICENSE.TXT`).
