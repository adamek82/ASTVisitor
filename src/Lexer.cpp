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

    if (isdigit(current) || current == '.') {
        std::string number;
        bool hasDecimal = false;

        // Capture leading digits or decimal point
        while (pos < input.size() && (isdigit(input[pos]) || input[pos] == '.')) {
            if (input[pos] == '.') {
                // If we already found a decimal point, throw an exception
                if (hasDecimal) {
                    throw std::runtime_error("Invalid numeric literal with multiple decimal points: " + number);
                }
                hasDecimal = true;
            }
            number += input[pos++];
        }

        // (Optional) parse simple scientific notation: e.g., 1.23e+10
        // Check if next char is 'e' or 'E'
        if (pos < input.size() && (input[pos] == 'e' || input[pos] == 'E')) {
            number += input[pos++];
            // Check optional sign
            if (pos < input.size() && (input[pos] == '+' || input[pos] == '-')) {
                number += input[pos++];
            }
            // Capture exponent digits
            while (pos < input.size() && isdigit(input[pos])) {
                number += input[pos++];
            }
        }

        return {TokenType::NUMBER, number};
    }

    if (current == '(') {
        pos++;
        return {TokenType::LPAREN, "("};
    }
    if (current == ')') {
        pos++;
        return {TokenType::RPAREN, ")"};
    }

    if (current == '+') { pos++; return {TokenType::PLUS, "+"}; }
    if (current == '-') { pos++; return {TokenType::MINUS, "-"}; }
    if (current == '*') { pos++; return {TokenType::MULTIPLY, "*"}; }
    if (current == '/') { pos++; return {TokenType::DIVIDE, "/"}; }
    if (current == '^') { pos++; return {TokenType::POWER, "^"}; }
    if (current == '=') { pos++; return {TokenType::EQUAL, "="}; }

    throw std::runtime_error("Unexpected character: " + std::string(1, current));
}