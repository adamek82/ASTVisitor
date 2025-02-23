#include <iostream>
#include <string>
#include "AST.h"
#include "Lexer.h"
#include "Parser.h"
#include "PrintVisitor.h"

int main() {
    std::string input = "x = (5.5 + 2e1 * (3.14 - 1)) ^ 2 ^ 2 - 30 / 6.2";  // Example input

    try {
        // Lexing and Parsing
        Lexer lexer(input);
        Parser parser(lexer);
        auto ast = parser.parse();

        // Print the AST
        PrintVisitor printer;
        ast->accept(&printer);  // Output: x = (5 + 10)
    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << '\n';
    }

    return 0;
}