// Parser.cpp - Parser Implementation
#include "Parser.h"  // Include own header
#include "Lexer.h"   // Ensure Lexer is included
#include "AST.h"     // Include AST nodes like NodeNumber, NodePlus, etc.
#include <stdexcept> // For std::runtime_error
#include <memory>    // For std::unique_ptr

Parser::Parser(Lexer lex) : lexer(std::move(lex)) {
    currentToken = lexer.getNextToken();
}

void Parser::eat(TokenType expectedType) {
    if (currentToken.type == expectedType) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Unexpected token: " + currentToken.value);
    }
}

std::unique_ptr<Node> Parser::parseNumber() {
    int value = std::stoi(currentToken.value);
    eat(TokenType::NUMBER);
    return std::make_unique<NodeNumber>(value);
}

std::unique_ptr<Node> Parser::parseAssignment() {
    std::string varName = currentToken.value;
    eat(TokenType::IDENTIFIER);
    eat(TokenType::EQUAL);
    auto expr = parseExpression();
    return std::make_unique<NodeAssign>(varName, std::move(expr));
}

std::unique_ptr<Node> Parser::parse() {
    return parseAssignment();
}

std::unique_ptr<Node> Parser::parseExpression() {
    auto left = parseTerm();
    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        TokenType op = currentToken.type;
        eat(op);
        auto right = parseTerm();
        if (op == TokenType::PLUS) {
            left = std::make_unique<NodePlus>(std::move(left), std::move(right));
        } else {
            left = std::make_unique<NodeMinus>(std::move(left), std::move(right));
        }
    }
    return left;
}

std::unique_ptr<Node> Parser::parseTerm() {
    auto left = parseFactor();
    while (currentToken.type == TokenType::MULTIPLY || currentToken.type == TokenType::DIVIDE) {
        TokenType op = currentToken.type;
        eat(op);
        auto right = parseFactor();
        if (op == TokenType::MULTIPLY) {
            left = std::make_unique<NodeMultiply>(std::move(left), std::move(right));
        } else {
            left = std::make_unique<NodeDivide>(std::move(left), std::move(right));
        }
    }
    return left;
}

std::unique_ptr<Node> Parser::parseFactor() {
    if (currentToken.type == TokenType::NUMBER) {
        return parseNumber();
    } else if (currentToken.type == TokenType::IDENTIFIER) {
        return parseAssignment();
    } else {
        throw std::runtime_error("Unexpected token in factor: " + currentToken.value);
    }
}
