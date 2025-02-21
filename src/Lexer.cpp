// Lexer.cpp - Implementation of Lexer
#include "Lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& text) : input(text) {}

Token Lexer::getNextToken() {
    while (pos < input.size() && isspace(input[pos])) pos++;
    if (pos >= input.size()) return {TokenType::END, ""};

    char current = input[pos];

    if (isalpha(current)) {
        std::string identifier;
        while (pos < input.size() && isalnum(input[pos])) {
            identifier += input[pos++];
        }
        return {TokenType::IDENTIFIER, identifier};
    }

    if (isdigit(current)) {
        std::string number;
        while (pos < input.size() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return {TokenType::NUMBER, number};
    }

    if (current == '+') { pos++; return {TokenType::PLUS, "+"}; }
    if (current == '-') { pos++; return {TokenType::MINUS, "-"}; }
    if (current == '*') { pos++; return {TokenType::MULTIPLY, "*"}; }
    if (current == '/') { pos++; return {TokenType::DIVIDE, "/"}; }
    if (current == '=') { pos++; return {TokenType::EQUAL, "="}; }

    throw std::runtime_error("Unexpected character: " + std::string(1, current));
}