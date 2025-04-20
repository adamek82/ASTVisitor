# AST Visitor Playground

A C++ "playground" demonstrating compiler front-end techniques: lexing, parsing, Abstract Syntax Tree (AST) construction, and AST traversal via the Visitor pattern.  
Ideal for learning how compilers handle expressions, variable assignments, and tree-based evaluation.

---

## Features

- **Lexer** (`src/Lexer.cpp`, `include/Lexer.h`)  
  Tokenizes input strings into identifiers, numbers (with optional scientific notation), operators (`+`, `-`, `*`, `/`, `^`, `=`), and parentheses.

- **Parser** (`src/Parser.cpp`, `include/Parser.h`)  
  Recursive descent parser that builds an AST:  
  - **Assignment**: `x = expr`  
  - **Expressions**: handles `+`, `-`, `*`, `/` with correct precedence  
  - **Exponentiation**: `^` as right-associative  
  - **Parentheses**: grouping via `(...)`

- **AST Nodes** (`src/AST.cpp`, `include/AST.h`)  
  Node types for numbers, variable references, plus, minus, multiply, divide, power, and assignment. Uses `std::unique_ptr` for memory safety.

- **Visitor Pattern**  
  - **PrintVisitor** (`src/PrintVisitor.cpp`, `include/PrintVisitor.h`): prints AST in infix form.  
  - **EvaluatingVisitor** (`src/EvaluatingVisitor.cpp`, `include/EvaluatingVisitor.h`): computes expression values with a symbol table.

- **Driver** (`src/main.cpp`)  
  Parses a sample expression, prints AST, and evaluates result.

---

## Project Structure

```
ASTVisitor/
│
├── .gitignore
├── ASTVisitor.code-workspace
├── CMakeLists.txt
│
├── include/
│   ├── AST.h
│   ├── Lexer.h
│   ├── Parser.h
│   ├── Visitor.h
│   ├── PrintVisitor.h
│   └── EvaluatingVisitor.h
│
├── src/
│   ├── AST.cpp
│   ├── Lexer.cpp
│   ├── Parser.cpp
│   ├── PrintVisitor.cpp
│   ├── EvaluatingVisitor.cpp
│   └── main.cpp
│
├── build/    # CMake output (ignored)
└── bin/      # Executables (ignored)
```

---

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./ASTVisitor
```

---

## Sample Output

```
x = ((5.5 + (20 * (3.14 - 1))) ^ (2 ^ 2)) - (30 / 6.2)
Evaluated result: 4840.41
```

---

## Learning Takeaways

- **Recursive descent parsing** of expressions with correct precedence.  
- **AST construction** with smart pointers.  
- **Visitor pattern** for AST traversal (printing, evaluation).  
- Handling **operator associativity** and **variable assignments**.
