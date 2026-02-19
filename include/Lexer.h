// Lexer.h - Tokenizer class
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Token types
enum class TokenType {
    IDENTIFIER, NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POWER,
    EQUAL,
    LPAREN,
    RPAREN,
    END
};

// Token structure
struct Token {
    TokenType type;
    std::string value;
};

// Lexer class
class Lexer {
    std::string input;
    size_t pos = 0;

public:
    explicit Lexer(const std::string& text);
    Token getNextToken();
};

#endif // LEXER_H
