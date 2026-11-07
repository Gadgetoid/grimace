const vscode = require('vscode');
const childProcess = require('child_process');
const fs = require('fs');
const os = require('os');
const path = require('path');
const { findCommand } = require('./lib/build-flags');
const symbols = require('./lib/symbols');
const diagnostics = require('./lib/diagnostics');
const keywords = require('./lib/keywords');

const LANGUAGE = 'rc';
const indexes = new Map();
const running = new Map();
let collection;

function settings(document) {
    return vscode.workspace.getConfiguration('rcLanguage', document.uri);
}

function workspaceRoot(document) {
    const folder = vscode.workspace.getWorkspaceFolder(document.uri);
    return folder ? folder.uri.fsPath : path.dirname(document.uri.fsPath);
}

function expand(value, root) {
    return value.replace(/\$\{workspaceFolder\}/g, root).replace(/^~(?=$|[\\/])/, os.homedir());
}

function context(document) {
    const root = workspaceRoot(document);
    const config = settings(document);
    const command = findCommand(root, document.uri.fsPath);
    const configured = config.get('llvmRc', '');
    const llvmRoot = process.env.GRIMACE_LLVM_ROOT ? path.join(process.env.GRIMACE_LLVM_ROOT, 'bin', 'llvm-rc') : null;
    const llvmRc = configured ? expand(configured, root) : command ? command.llvmRc : llvmRoot && fs.existsSync(llvmRoot) ? llvmRoot : 'llvm-rc';
    const includes = [
        ...(command ? command.includes : []),
        ...config.get('includePaths', []).map((folder) => path.resolve(root, expand(folder, root))),
    ];
    if (!includes.some((folder) => path.resolve(folder) === path.dirname(document.uri.fsPath))) {
        includes.push(path.dirname(document.uri.fsPath));
    }
    const defines = [...(command ? command.defines : []), ...config.get('defines', [])];
    return { llvmRc, includes, defines, command };
}

function indexFor(document) {
    const key = document.uri.toString();
    const cached = indexes.get(key);
    if (cached && cached.version === document.version) {
        return cached.index;
    }
    const index = symbols.index(document.uri.fsPath, document.getText(), context(document).includes);
    indexes.set(key, { version: document.version, index });
    return index;
}

function wordAt(document, position) {
    const range = document.getWordRangeAtPosition(position, /[A-Za-z_]\w*/);
    return range ? { range, word: document.getText(range) } : null;
}

function provideHover(document, position) {
    const found = wordAt(document, position);
    if (!found) {
        return null;
    }
    const index = indexFor(document);
    const symbol = index.symbols.get(found.word);
    if (!symbol) {
        return null;
    }
    const markdown = new vscode.MarkdownString();
    markdown.appendCodeblock(`#define ${symbol.name}${symbol.parameters} ${symbol.value}`.trimEnd(), 'c');
    const value = symbols.evaluate(symbol.name, index.symbols);
    if (value !== null && String(value) !== symbol.value) {
        markdown.appendMarkdown(`= ${value} (0x${value.toString(16).toUpperCase()})\n\n`);
    }
    if (symbol.doc) {
        markdown.appendText(symbol.doc);
        markdown.appendMarkdown('\n\n');
    }
    const location = vscode.Uri.file(symbol.file).with({ fragment: `L${symbol.line + 1}` });
    markdown.appendMarkdown(`[${path.basename(symbol.file)}:${symbol.line + 1}](${location.toString()})`);
    return new vscode.Hover(markdown, found.range);
}

function provideDefinition(document, position) {
    const found = wordAt(document, position);
    const symbol = found && indexFor(document).symbols.get(found.word);
    if (!symbol) {
        return null;
    }
    return new vscode.Location(vscode.Uri.file(symbol.file), new vscode.Range(symbol.line, symbol.start, symbol.line, symbol.end));
}

function resourceFile(name, document, includes) {
    const candidates = [path.dirname(document.uri.fsPath), ...includes].map((folder) => path.resolve(folder, name));
    return candidates.find((candidate) => {
        try {
            return fs.statSync(candidate).isFile();
        } catch {
            return false;
        }
    });
}

function provideDocumentLinks(document) {
    const index = indexFor(document);
    const links = [];
    for (const include of index.includes) {
        if (include.target) {
            links.push(new vscode.DocumentLink(new vscode.Range(include.line, include.start, include.line, include.end), vscode.Uri.file(include.target)));
        }
    }
    const includes = context(document).includes;
    for (let line = 0; line < document.lineCount; line++) {
        const text = document.lineAt(line).text;
        if (/^\s*#\s*include/.test(text)) {
            continue;
        }
        for (const match of text.matchAll(/"([^"\\]+\.[A-Za-z0-9]{1,5})"/g)) {
            const target = resourceFile(match[1], document, includes);
            if (target) {
                const start = match.index + 1;
                links.push(new vscode.DocumentLink(new vscode.Range(line, start, line, start + match[1].length), vscode.Uri.file(target)));
            }
        }
    }
    return links;
}

function insideString(text) {
    let inside = false;
    for (let index = 0; index < text.length; index++) {
        if (text[index] === '"') {
            if (inside && text[index + 1] === '"') {
                index++;
            } else {
                inside = !inside;
            }
        }
    }
    return inside;
}

function provideCompletionItems(document, position) {
    const before = document.lineAt(position.line).text.slice(0, position.character);
    if (insideString(before)) {
        const typed = before.slice(before.lastIndexOf('"') + 1);
        const folder = path.resolve(path.dirname(document.uri.fsPath), path.dirname(typed));
        let entries = [];
        try {
            entries = fs.readdirSync(folder, { withFileTypes: true });
        } catch {
            return [];
        }
        return entries.filter((entry) => !entry.name.startsWith('.')).map((entry) => {
            const item = new vscode.CompletionItem(entry.name, entry.isDirectory() ? vscode.CompletionItemKind.Folder : vscode.CompletionItemKind.File);
            if (entry.isDirectory()) {
                item.insertText = entry.name + '/';
            }
            return item;
        });
    }
    if (/^\s*#\s*include\s*[<"][^>"]*$/.test(before)) {
        return [];
    }
    const items = [];
    const add = (names, kind, detail) => {
        for (const name of names) {
            const item = new vscode.CompletionItem(name, kind);
            item.detail = detail;
            items.push(item);
        }
    };
    add(keywords.resourceTypes, vscode.CompletionItemKind.Class, 'resource type');
    add(keywords.statements, vscode.CompletionItemKind.Keyword, 'statement');
    add(keywords.controls, vscode.CompletionItemKind.Struct, 'control');
    add(keywords.memoryOptions, vscode.CompletionItemKind.Keyword, 'memory option');
    for (const symbol of indexFor(document).symbols.values()) {
        const item = new vscode.CompletionItem(symbol.name, symbol.parameters ? vscode.CompletionItemKind.Function : vscode.CompletionItemKind.Constant);
        item.detail = `${symbol.name}${symbol.parameters} ${symbol.value}`.trim();
        if (symbol.doc) {
            item.documentation = symbol.doc;
        }
        items.push(item);
    }
    return items;
}

function check(document) {
    if (document.languageId !== LANGUAGE || document.uri.scheme !== 'file' || !settings(document).get('checkOnSave', true)) {
        return;
    }
    const key = document.uri.toString();
    const previous = running.get(key);
    if (previous) {
        previous.kill();
    }
    const { llvmRc, includes, defines } = context(document);
    const output = path.join(os.tmpdir(), `rc-language-${process.pid}-${Date.now()}.res`);
    const args = [
        ...defines.flatMap((define) => ['-D', define]),
        ...includes.flatMap((folder) => ['-I', folder]),
        '-FO', output, '--', document.uri.fsPath,
    ];
    const child = childProcess.execFile(llvmRc, args, { cwd: path.dirname(document.uri.fsPath), timeout: 30000 }, (error, stdout, stderr) => {
        if (running.get(key) === child) {
            running.delete(key);
        }
        fs.rm(output, { force: true }, () => {});
        if (error && error.code === 'ENOENT') {
            collection.set(document.uri, [new vscode.Diagnostic(new vscode.Range(0, 0, 0, 1),
                `llvm-rc not found (${llvmRc}): configure the project with grimace, or set rcLanguage.llvmRc`, vscode.DiagnosticSeverity.Information)]);
            return;
        }
        if (error && error.killed) {
            return;
        }
        const lines = document.getText().split(/\r?\n/);
        const found = diagnostics.parse(`${stdout}\n${stderr}`, document.uri.fsPath, lines, indexFor(document).symbols);
        collection.set(document.uri, found.map((item) => {
            const diagnostic = new vscode.Diagnostic(new vscode.Range(item.line, item.start, item.line, item.end), item.message,
                item.severity === 'warning' ? vscode.DiagnosticSeverity.Warning : vscode.DiagnosticSeverity.Error);
            diagnostic.source = 'llvm-rc';
            return diagnostic;
        }));
    });
    running.set(key, child);
}

function activate(extensionContext) {
    collection = vscode.languages.createDiagnosticCollection(LANGUAGE);
    const selector = { language: LANGUAGE, scheme: 'file' };
    extensionContext.subscriptions.push(
        collection,
        vscode.languages.registerHoverProvider(selector, { provideHover }),
        vscode.languages.registerDefinitionProvider(selector, { provideDefinition }),
        vscode.languages.registerDocumentLinkProvider(selector, { provideDocumentLinks }),
        vscode.languages.registerCompletionItemProvider(selector, { provideCompletionItems }, '"', '/'),
        vscode.workspace.onDidOpenTextDocument(check),
        vscode.workspace.onDidSaveTextDocument((document) => {
            symbols.clearCaches();
            check(document);
        }),
        vscode.workspace.onDidCloseTextDocument((document) => {
            collection.delete(document.uri);
            indexes.delete(document.uri.toString());
        }),
    );
    vscode.workspace.textDocuments.forEach(check);
}

function deactivate() {
    for (const child of running.values()) {
        child.kill();
    }
}

module.exports = { activate, deactivate };
