#include <iostream>
#include <string>
#include "AST.h"
#include "Lexer.h"
#include "Parser.h"
#include "PrintVisitor.h"
#include "EvaluatingVisitorRecursive.h"
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

        // Evaluate the AST using the recursive evaluator (legacy/reference version)
        EvaluatingVisitorRecursive evalRecursive;
        double resultRecursive = evalRecursive.evaluate(ast.get());
        std::cout << "Evaluated result (recursive): " << resultRecursive << "\n";

        // Evaluate the AST using the stack-based evaluator (current/preferred version)
        EvaluatingVisitor evalStack;
        double resultStack = evalStack.evaluate(ast.get());
        std::cout << "Evaluated result (stack-based): " << resultStack << "\n";

    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << '\n';
    }

    return 0;
}
