# Compiler Course Project (Variant 25) - AI Coding Guide

## Project Overview

This is a **compiler-compiler** system for a custom programming language (variant 25). The project generates lexers (DFA), parsers (DPDA/LL(2)), and a full compiler pipeline from formal language specifications.

**Key Architecture:**
- **Language Spec** ([variant_specification/](variant_specification/)): Defines the source language via regex patterns and EBNF grammar
- **Generator Tools**: Create automata and parsers from specs → outputs to `built_src/` and `built_doc/`
- **Main Compiler** ([cw_sp2__2025_2026/](cw_sp2__2025_2026/)): Consumes generated files to compile `.k03` programs
- **Test Programs**: [base_test_programs_2025/](base_test_programs_2025/) contains `.k03` sample programs

## Language Specification (Variant 25)

**Identifiers:** `[A-Z][A-Z][0-9]` (e.g., `AA0`, `XY9` - exactly 2 uppercase + 1 digit)  
**Keywords:** `program`, `start`, `end`, `var`, `int32`, `read`, `write`, `if`, `else`, `while`, `break`, `continue`  
**Assignment:** `:>` (left-to-right, e.g., `expr :> variable`)  
**Operators:** `add`, `-`, `mul`, `/`, `%`, `==`, `!=`, `lt`, `gt`, `not`, `and`, `or`  
**Comments:** `/* ... */`

```k03
program AB0;
start var int32 AC1, AD2;
  read AC1;
  AC1 add 10 :> AD2;
  write AD2;
end
```

All language rules are defined in [variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h](variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h) (regex) and [variant_specification/EBNF_N1.h](variant_specification/EBNF_N1.h) (grammar).

## Critical Build Workflow

**IMPORTANT:** Generator tools must run **before** building the main compiler, as they produce required source files.

### 1. Generate Lexer Tables (DFA)
```powershell
# Build and run dfa_generator__2025
# Outputs to built_src/ (file1-4.hpp) and built_doc/ (FSM diagrams)
```
This creates DFA transition tables from regex in [variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h](variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h#L14-L17) (lines 14-17: `TOKENS_RE`, `KEYWORDS_RE`, `IDENTIFIERS_RE`, `UNSIGNEDVALUES_RE`).

### 2. Generate Parser Tables (DPDA/LL(2))
```powershell
# Build and run dpda1_for_ll2_generator__2025
# Outputs grammar documentation to built_doc/ (NPDA_*.txt, Grammar_*.txt)
```

### 3. Build Main Compiler
```powershell
# Open sp2025_var25.sln in Visual Studio OR
# Build cw_sp2__2025_2026 project
# Set cw_sp2__2025_2026 as startup project
```

### 4. Run Compiler
```powershell
.\cw_sp2__2025_2026.exe ..\base_test_programs_2025\file0.k03
```

**Visual Studio Users:** See [QUICK_START.md](QUICK_START.md#L3-L30) for solution/project setup.  
**Детальна інструкція українською:** [ІНСТРУКЦІЯ_КОМПІЛЯЦІЇ.md](ІНСТРУКЦІЯ_КОМПІЛЯЦІЇ.md)

## Code Organization Patterns

### Shared Language Definition
**ALL** compiler components include [variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h](variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h). Changes here affect the entire pipeline:
- Token definitions (`T_SEMICOLON_0 ";"` pattern at lines 44-47)
- Regex patterns for lexer generation (lines 14-17)
- Shared constants across lexer, parser, semantic analyzer

### Lexer Architecture
The project uses **table-driven DFA** pattern:
- Generic DFA engine: [built_src/dfa.hpp](built_src/dfa.hpp) (`tryToAccept()` function)
- Generated tables: [built_src/file1-4.hpp](built_src/) (2D arrays `transitionTable1-4`)
- Integration: [cw_sp2__2025_2026/src/include/lexica/lexica.h](cw_sp2__2025_2026/src/include/lexica/lexica.h)

**ID Assignment Convention:** Lexeme IDs are calculated ranges (see [lexica.h#L21-L40](cw_sp2__2025_2026/src/include/lexica/lexica.h#L21-L40)):
```cpp
KEYWORD_LEXEM_MIN_ID = 2
IDENT_METETERMINAL_LEXEM_ID = KEYWORD_LEXEM_MAX_ID + 1
IDENTIFIER_LEXEM_MIN_ID = IDENT_METETERMINAL_LEXEM_ID + 1
```

### Parser Architecture
LL(2) predictive parser with two-token lookahead:
- Grammar structure: [syntax.h#L21-L44](cw_sp2__2025_2026/src/include/syntax/syntax.h#L21-L44) (`MarkedRule`, `Grammar`)
- First/second marks: Lookahead sets for LL(2) predictions
- Entry point: `getIndexAfterFragmentSyntax()` in [syntax.h#L50](cw_sp2__2025_2026/src/include/syntax/syntax.h#L50)

### Compiler Pipeline
[cw.cpp](cw_sp2__2025_2026/cw.cpp) orchestrates phases:
1. Load source → `loadSource()` (line 79)
2. Lexical analysis → includes `lexica/lexica.h` (line 43)
3. Syntax analysis → includes `syntax/syntax.h` (line 45)
4. Semantic checks → includes `semantics/semantics.h` (line 46)
5. Code generation → includes `generator/generator.h` (line 48)

**Module structure:** Each phase has `src/include/<phase>/<phase>.h` and `src/implementation/<phase>/` folder.

## Special Conventions

### Regular Expression Notation (Custom)
[dfa_generator__2025/README.md#L86-L93](dfa_generator__2025/README.md#L86-L93) documents the notation:
- `|` = OR, `~` = Kleene star, `^` = optional
- `\\` escapes specials; doubled chars (`((`, `||`) = literals
- Used in [variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h](variant_specification/LexicaByRegExAndSyntaxByLL2protototype.h#L14)

### EBNF Grammar Encoding
Grammar in [variant_specification/EBNF_N1.h](variant_specification/EBNF_N1.h) uses `#define` macros:
- `NONTERMINALS` lists all non-terminals (line 13+)
- `GRAMMAR_LL2__2025` macro defines full grammar (line 40+)
- Empty production: `""` represents epsilon (line 84 comment)

### Generated Files Pattern
All generators follow: `built_src/<name>.hpp` + `built_doc/<name>.dot/.svg/.txt`:
- `.hpp` files: C++ transition tables for runtime
- `.dot` files: Graphviz FSM diagrams (requires Graphviz in `Graphviz-14.0.5-win32/`)
- `.txt` files: Human-readable grammar/automata specs

### Error Handling Convention
`errorMessagesPtrToLastBytePtr` buffer accumulates error messages ([cw.cpp#L57](cw_sp2__2025_2026/cw.cpp#L57)). Phases append diagnostics without halting immediately.

## File Path Conventions

**Relative paths from project root:**
- Input: `../base_test_programs_2025/file0.k03`
- Output: `../built_src/`, `../built_doc/`
- Config: `../variant_specification/`

**Windows-specific:** Uses `#define _CRT_SECURE_NO_WARNINGS` (line 1 in most `.cpp` files) to suppress MSVC warnings for `strcpy`, `sprintf`.

## Debugging Tips

- `#define DEBUG_STATES` in [syntax.h#L48](cw_sp2__2025_2026/src/include/syntax/syntax.h#L48) enables parser trace output
- `#define DEBUG_DFA_STATE` in [dfa.hpp#L7](built_src/dfa.hpp#L7) shows DFA accept/reject decisions
- Test incrementally with simple programs from [base_test_programs_2025/](base_test_programs_2025/)

## External Dependencies

- **Boost:** Header-only library in [boost/](boost/) folder (used for regex/spirit parsing in some tools)
- **Graphviz 14.0.5:** Optional for FSM diagram generation (see [dfa_generator__2025/Graphviz-14.0.5-win32--link.txt](dfa_generator__2025/Graphviz-14.0.5-win32--link.txt))
- **Visual Studio 2019+** or **TDM-GCC** (batch file: [cw_sp2__2025_2026/compile_compiler_by_tdmgcc32__2025_2026.bat](cw_sp2__2025_2026/compile_compiler_by_tdmgcc32__2025_2026.bat))

## TODOs & Future Work

See [TODOlist.txt](TODOlist.txt): AST-based code generators (C, ASM, exe), Rust-if support, EBNF→Boost.Spirit translator.
