#include <iostream>
#include <vector>
#include <string>

#include "Scanner.hpp"


const char* tokenTypeNames[] = {
    "LeftParen", "RightParen", "LeftBrace", "RightBrace", "LeftSqrBrace",
    "RightSqrBrace", "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH",
    "STAR", "BANG", "BangEqual", "EQUAL", "EqualEqual", "GREATER",
    "GreaterEqual", "LESS", "LessEqual", "IDENTIFIER", "STRING", "NUMBER",
    "AND", "CLASS", "ELSE", "FALSE", "FUN", "FOR", "IF", "NIL", "OR",
    "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE", "END"
};

std::string stringTokenType(tokenType type) {
    return tokenTypeNames[static_cast<int>(type)];
}


int main() 
{
    std::string test = "var x = 1;\nvar y = 2;\n";

    auto scanner = Scanner(test);

    if (scanner.Scan()) {

        auto tokens = scanner.getTokens();

        // TODO: Call parser.
        // TODO: go over previous parser issues.
        // TODO: Debug parser.

        for (auto t : tokens) {
            std::cout << stringTokenType(t.token_type) << ", " << std::endl;
        }

        // TODO: write this...

        std::cout << "done" << std::endl;
    }

    return 0;
}