const assert = require('assert');
const fs = require('fs');
const os = require('os');
const path = require('path');
const test = require('node:test');
const { tokenize, parseCommand, findCommand } = require('../lib/build-flags');
const symbols = require('../lib/symbols');
const diagnostics = require('../lib/diagnostics');

function project() {
    const root = fs.mkdtempSync(path.join(os.tmpdir(), 'rc-language-'));
    fs.cpSync(path.join(__dirname, 'fixtures', 'project'), root, { recursive: true });
    const template = path.join(root, 'build-fixture', 'CMakeFiles', 'app.dir', 'build.make.in');
    fs.writeFileSync(template.replace(/\.in$/, ''), fs.readFileSync(template, 'utf8').replaceAll('${ROOT}', root));
    return root;
}

test('tokenize handles quotes and escaped spaces', () => {
    assert.deepStrictEqual(tokenize('llvm-rc -I "a b" -I c\\ d -- "x.rc"'), ['llvm-rc', '-I', 'a b', '-I', 'c d', '--', 'x.rc']);
});

test('parseCommand reads includes, defines and the script', () => {
    const command = parseCommand('cd /x && /opt/bin/llvm-rc -D A=1 -DB -I /inc -I/other -FO out.res -- /x/app.rc');
    assert.strictEqual(command.llvmRc, '/opt/bin/llvm-rc');
    assert.deepStrictEqual(command.defines, ['A=1', 'B']);
    assert.deepStrictEqual(command.includes, ['/inc', '/other']);
    assert.strictEqual(command.script, '/x/app.rc');
});

test('findCommand finds the build command for a script', () => {
    const root = project();
    const command = findCommand(root, path.join(root, 'app.rc'));
    assert.strictEqual(command.llvmRc, '/opt/llvm/bin/llvm-rc');
    assert.deepStrictEqual(command.includes, [path.join(root, 'include', 'wrap'), path.join(root, 'include', 'real')]);
    assert.deepStrictEqual(command.defines, ['_WIN32_WCE=200', 'SH3']);
    assert.strictEqual(findCommand(root, path.join(root, 'other.rc')), null);
});

test('index follows includes, include_next and keeps documentation', () => {
    const root = project();
    const script = path.join(root, 'app.rc');
    const includes = [path.join(root, 'include', 'wrap'), path.join(root, 'include', 'real')];
    const result = symbols.index(script, fs.readFileSync(script, 'latin1'), includes);
    assert.strictEqual(result.symbols.get('IDS_NAME').value, '101');
    assert.strictEqual(result.symbols.get('WRAPPED').value, '1');
    assert.strictEqual(result.symbols.get('WS_CHILD').doc, 'Creates a child window.');
    assert.strictEqual(result.symbols.get('TRAILING').doc, 'trailing comment');
    assert.strictEqual(result.symbols.get('SPLIT_VALUE').value, '1 + 2');
    assert.strictEqual(symbols.evaluate('NESTED', result.symbols), 0x40000000);
    assert.deepStrictEqual(result.includes.map((include) => include.target), [path.join(root, 'resource.h'), path.join(root, 'include', 'wrap', 'outer.h')]);
});

test('parse locates preprocessor, statement and parsing errors', () => {
    const root = project();
    const script = path.join(root, 'app.rc');
    const text = fs.readFileSync(script, 'latin1');
    const lines = text.split(/\r?\n/);
    const known = symbols.index(script, text, [path.join(root, 'include', 'wrap'), path.join(root, 'include', 'real')]).symbols;
    const output = [
        `${script}:2:10: fatal error: 'outer.h' file not found`,
        'llvm-rc: Error in ICON statement (ID 1): ',
        'error : file not found : app.ico',
        'llvm-rc: Error parsing file: expected \'-\', \'~\', integer or \'(\', got IDS_NAME',
        'llvm-rc: Preprocessing failed.',
    ].join('\n');
    const found = diagnostics.parse(output, script, lines, known);
    assert.strictEqual(found.length, 3);
    assert.deepStrictEqual(found[0], { line: 1, start: 9, end: 18, severity: 'error', message: "'outer.h' file not found" });
    assert.deepStrictEqual(found[1], { line: 3, start: 14, end: 21, severity: 'error', message: 'ICON 1: file not found: app.ico' });
    assert.deepStrictEqual(found[2].line, 7);
    assert.strictEqual(diagnostics.findStatement(lines, 'ICON', '1', known).line, 3);
});
