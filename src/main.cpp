#include <iostream>
#include <string>
#include "AST.h"
#include "Lexer.h"
#include "Parser.h"
#include "PrintVisitor.h"
#include "EvaluatingVisitor.h"

int main() {
    std::string input = "x = (5.5 + 2e1 * (3.14 - 1)) ^ 2 ^ 2 - 30 / 6.2";  // Example input

    try {
        // Lexing and Parsing
        Lexer lexer(input);
        Parser parser(lexer);
        auto ast = parser.parse();

        // Print the AST
        PrintVisitor printer;
        ast->accept(&printer);
        std::cout << std::endl;

        // Evaluate the AST
        EvaluatingVisitor eval;
        double result = eval.evaluate(ast.get());
        std::cout << "Evaluated result: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << '\n';
    }

    return 0;
}