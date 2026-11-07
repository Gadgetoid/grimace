const fs = require('fs');
const path = require('path');
const vsctm = require('vscode-textmate');
const oniguruma = require('vscode-oniguruma');

const extensionRoot = path.join(__dirname, '..');
const repositoryRoot = path.join(extensionRoot, '..', '..');
const skippedDirectories = new Set(['node_modules', 'build', '.git']);

function findResourceScripts(directory, found) {
    for (const entry of fs.readdirSync(directory, { withFileTypes: true })) {
        const entryPath = path.join(directory, entry.name);
        if (entry.isDirectory()) {
            if (!skippedDirectories.has(entry.name) && !entry.name.startsWith('build-')) {
                findResourceScripts(entryPath, found);
            }
        } else if (/\.rc2?$/i.test(entry.name) && !entry.name.endsWith('.test.rc')) {
            found.push(entryPath);
        }
    }
    return found;
}

function readSource(filePath) {
    const bytes = fs.readFileSync(filePath);
    if (bytes[0] === 0xff && bytes[1] === 0xfe) {
        return bytes.subarray(2).toString('utf16le');
    }
    if (bytes[0] === 0xef && bytes[1] === 0xbb && bytes[2] === 0xbf) {
        return bytes.subarray(3).toString('utf8');
    }
    return bytes.toString('latin1');
}

async function loadGrammar() {
    const wasm = fs.readFileSync(require.resolve('vscode-oniguruma/release/onig.wasm'));
    await oniguruma.loadWASM(wasm.buffer.slice(wasm.byteOffset, wasm.byteOffset + wasm.byteLength));
    const registry = new vsctm.Registry({
        onigLib: Promise.resolve({
            createOnigScanner: (patterns) => new oniguruma.OnigScanner(patterns),
            createOnigString: (text) => new oniguruma.OnigString(text),
        }),
        loadGrammar: async () => {
            const grammarPath = path.join(extensionRoot, 'syntaxes', 'rc.tmLanguage.json');
            return vsctm.parseRawGrammar(fs.readFileSync(grammarPath, 'utf8'), grammarPath);
        },
    });
    return registry.loadGrammar('source.rc');
}

const blockLine = /^\s*(BEGIN|END|\{|\})\s*(?:\/\/.*)?$/i;

function checkFile(grammar, filePath) {
    const problems = [];
    const lines = readSource(filePath).split(/\r?\n/);
    let ruleStack = vsctm.INITIAL;
    lines.forEach((line, index) => {
        const lineNumber = index + 1;
        const startedAtRoot = ruleStack.depth === vsctm.INITIAL.depth;
        const { tokens, ruleStack: nextStack } = grammar.tokenizeLine(line, ruleStack);
        ruleStack = nextStack;

        for (const token of tokens) {
            if (token.scopes.some((scope) => scope.startsWith('invalid'))) {
                problems.push(`${lineNumber}: invalid token "${line.slice(token.startIndex, token.endIndex)}"`);
            }
        }

        const block = blockLine.exec(line);
        if (block && startedAtRoot) {
            const column = line.indexOf(block[1]);
            const token = tokens.find((candidate) => candidate.startIndex <= column && column < candidate.endIndex);
            const scopes = token ? token.scopes.join(' ') : '';
            if (!/keyword\.control\.block|punctuation\.section\.block/.test(scopes)) {
                problems.push(`${lineNumber}: "${block[1]}" scoped as "${scopes}"`);
            }
        }

        const lastToken = tokens[tokens.length - 1];
        const inBlockComment = lastToken && lastToken.scopes.includes('comment.block.rc') && !line.trimEnd().endsWith('*/');
        const continued = line.endsWith('\\');
        if (ruleStack.depth !== vsctm.INITIAL.depth && !inBlockComment && !continued) {
            problems.push(`${lineNumber}: region left open at end of line: ${lastToken ? lastToken.scopes.join(' ') : ''}`);
        }
    });
    if (ruleStack.depth !== vsctm.INITIAL.depth) {
        problems.push(`end of file: region left open`);
    }
    return problems;
}

async function main() {
    const targets = process.argv.slice(2);
    const files = [];
    for (const target of targets.length ? targets : [repositoryRoot]) {
        if (fs.statSync(target).isDirectory()) {
            findResourceScripts(target, files);
        } else {
            files.push(target);
        }
    }
    if (files.length === 0) {
        console.error('No resource scripts found');
        process.exit(1);
    }

    const grammar = await loadGrammar();
    let failed = 0;
    for (const file of files) {
        const problems = checkFile(grammar, file);
        const name = path.relative(process.cwd(), file);
        if (problems.length) {
            failed++;
            console.log(`FAIL ${name}`);
            problems.slice(0, 20).forEach((problem) => console.log(`  ${problem}`));
        } else {
            console.log(`ok   ${name}`);
        }
    }
    console.log(`${files.length - failed}/${files.length} files passed`);
    process.exit(failed ? 1 : 0);
}

main().catch((error) => {
    console.error(error);
    process.exit(1);
});
