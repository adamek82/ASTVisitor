// Parser.h - Parser class
#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "AST.h"
#include <memory>  // Required for unique_ptr

class Parser {
    Lexer lexer;
    Token currentToken;

    void eat(TokenType expectedType);
    std::unique_ptr<Node> parseNumber();
    std::unique_ptr<Node> parseExpression();
    std::unique_ptr<Node> parseAssignment();
    std::unique_ptr<Node> parseTerm();
    std::unique_ptr<Node> parseFactor();
    std::unique_ptr<Node> parsePower();

public:
    explicit Parser(Lexer lex);
    std::unique_ptr<Node> parse();
};

#endif // PARSER_H