# Resource Script (RC) for VS Code

Syntax highlighting and language features for Windows resource scripts (`.rc`, `.rc2`), as `rc.exe` and `llvm-rc` accept them, including the Windows CE subset.

It highlights:

- the C preprocessor: `#include`, `#define`, `#if`/`#ifdef`/`#ifndef`/`#elif`/`#else`/`#endif`, `#undef`, `#pragma`, `#error`
- `//` and `/* */` comments
- strings, with escapes, `""` quotes, `\` line continuations and `L"..."` wide strings
- decimal and hex numbers, with `L` and `U` suffixes
- resource types, statements, controls, and memory, menu, accelerator and `VERSIONINFO` options, in any case
- common constants: `WS_*`, `DS_*`, `ES_*`, `BS_*`, `SS_*`, `LBS_*`, `CBS_*`, `SBS_*`, `VK_*`, `LANG_*`, `VS_*` and `IDOK`-style IDs

Strings end at the end of a line unless it ends with `\`, so an unclosed string doesn't run on into the rest of the file.

## Language features

- **Errors**: when a script is opened or saved, it's compiled with `llvm-rc` and the errors are shown in place. Preprocessor errors have their exact position; resource errors, which `llvm-rc` reports by statement and ID, go on that statement, or on the missing file's name.
- **Hover** on a macro shows its `#define`, its value worked out where it's a number, its documentation comment, and where it's defined.
- **Go to Definition** on a macro opens its `#define`.
- **Links**: `#include` names and resource file names, such as `"app.ico"`, open the file.
- **Completion** of resource types, statements, controls, memory options and the macros the script's headers define, and of file names inside strings.

The `#include` folders, macros and `llvm-rc` are the ones the CMake build uses for the script: they're read from `build*/build.ninja` and `build*/CMakeFiles/*/build.make` in the workspace folder, and one folder deeper, such as `build/ce2-sh3`, so configure the project first. Without a build, the script's own folder is searched, and these settings add to it:

- `rcLanguage.includePaths`: more `#include` folders; `${workspaceFolder}` is replaced
- `rcLanguage.defines`: more macros, as `NAME` or `NAME=VALUE`
- `rcLanguage.llvmRc`: the `llvm-rc` to use; otherwise the build's, then `$GRIMACE_LLVM_ROOT/bin/llvm-rc`, then the one on the `PATH`
- `rcLanguage.checkOnSave`: turns the `llvm-rc` check off

## Install

Either symlink this folder into VS Code's extensions folder and restart VS Code:

```sh
ln -s "$PWD" ~/.vscode/extensions/grimace.rc-language
```

or package it and install the `.vsix`:

```sh
npx @vscode/vsce package
code --install-extension rc-language-0.1.0.vsix
```

## Test

```sh
npm install
npm test
```

`test/lib.test.js` tests reading the build's command, indexing macros through `#include` and `#include_next`, and placing `llvm-rc`'s errors, against `test/fixtures/project`. `test/constructs.test.rc` is a [vscode-tmgrammar-test](https://github.com/PanAeon/vscode-tmgrammar-test) fixture asserting the scopes of each construct. `test/check-files.js` tokenizes every `.rc` file in this repository, or the files and folders given as arguments, and fails if a string, comment or directive is left open at the end of a line or file, or a `BEGIN`/`END` line isn't scoped as a block.

## Licence

MIT. The preprocessor rules and scope names follow VS Code's C grammar (`extensions/cpp/syntaxes/c.tmLanguage.json`, from [jeff-hykin/better-c-syntax](https://github.com/jeff-hykin/better-c-syntax)), which is MIT licensed.
