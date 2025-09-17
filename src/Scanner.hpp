#pragma once
#include <string>
#include <vector>

#include "./token.hpp"


class Scanner {

private:
    // protected vars
    std::string _src = "";
    unsigned int _src_length = 0;

    std::vector<Token> _tokens;
    unsigned int _line = 0;
    unsigned int _start = 0;
    unsigned int _current = 0;

    // Getters

    char peek();

    char peekNext();

    // Setters

    void addToken(tokenType token_type);

    void addTokenLiteral(tokenType token_type, Literal literal);

    // Misc + Scan for specific token types

    bool atEnd();

    char advance();

    void getNumber();

    void getString();

    void scanLiteralAndKeywords();

    void scanToken();


public:

    // Constructor/Destructor

    Scanner(std::string src);

    ~Scanner();

    /// @brief 
    /// @return Boolean value if an error occurs 
    bool Scan();


    std::vector<Token> getTokens();
};
