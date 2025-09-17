#include <string>
#include <variant>

#ifndef TOKEN_HPP
#define TOKEN_HPP


enum tokenType {
    // SINGLE CHAR TOKENS
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    LeftSqrBrace,
    RightSqrBrace,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    // ONE OR TWO CHARACTER TOKENS
    BANG,
    BangEqual,
    EQUAL,
    EqualEqual,
    GREATER,
    GreaterEqual,
    LESS,
    LessEqual,

    // LITERALS
    IDENTIFIER,
    STRING,
    NUMBER,

    // KEYWORDS
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    VAR,
    WHILE,

    END,
};


// Vairants can hold different values (introducted C++17)
// Monostate allows the variant to hold an empty value.
using Literal = std::variant<std::string, double, std::monostate>;


struct Token {
    tokenType token_type;
    Literal literal_type;
    unsigned int line;

    // A default constructor that initializes members to a valid state
    Token() : token_type(END), literal_type(std::monostate{}), line(0) {}

    Token(tokenType type, Literal lit_type, unsigned int ln)
        : token_type(type), literal_type(lit_type), line(ln) {}

    static Token new_token(tokenType type, Literal lit_type, unsigned int ln) {
        return Token(type, lit_type, ln);
    }
};


#endif