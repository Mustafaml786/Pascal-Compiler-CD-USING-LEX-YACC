# Pascal Compiler Using Lex and Yacc

This project is a **Pascal Compiler** implemented using **Lex** (Flex) and **Yacc** (Bison) as part of a **Compiler Design** course. It demonstrates the compilation process by covering the major phases of compilation: **Lexical Analysis**, **Syntax Analysis**, **Semantic Analysis**, and **Code Generation**. The compiler supports a subset of Pascal's language constructs and performs basic error detection.

---

## Features

### 1. Lexical Analysis (Scanning)
- Converts the input Pascal source code into tokens.
- Recognizes keywords, identifiers, operators, and literals.
- Detects invalid tokens and generates error messages.

### 2. Syntax Analysis (Parsing)
- Validates the grammar of the Pascal code.
- Implements rules for basic constructs like:
  - `BEGIN...END`
  - Variable declarations
  - Assignment statements
  - Conditional (`IF...THEN`) and loop constructs (`WHILE...DO`).

### 3. Semantic Analysis
- Performs type checking for operations.
- Ensures all variables are declared before use.
- Identifies scope-related errors.

### 4. Code Generation
- Produces intermediate code for valid Pascal constructs.
- Supports simple operations like assignments and arithmetic expressions.

---

## Example

### Input Pascal Code
```pascal
BEGIN
    VAR x;
    x := 5;
    IF x > 0 THEN
        WRITE(x);
END
