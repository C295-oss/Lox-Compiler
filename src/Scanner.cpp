#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <stdint.h>

#include "./Scanner.hpp"
#include "./token.hpp"


////////////////////////////////////////////////////////////////////////////
// private:


char Scanner::peek()
{
    if (this->atEnd())
        return '\0';
    
    return this->_src[this->_current];
}


char Scanner::peekNext()
{
    if (this->_current + 1 >= this->_src.length())
        return '\0';
    
    return this->_src[this->_current + 1];
}


void Scanner::addToken(tokenType token_type)
{
    this->addTokenLiteral(token_type, std::monostate{});
}


void Scanner::addTokenLiteral(
    tokenType token_type, 
    Literal literal=std::monostate{}
) {
    this->_tokens.push_back(
        Token::new_token(token_type, literal, this->_line)
    );
}


bool Scanner::atEnd()
{
    return this->_current >= this->_src.length();
}

char Scanner::advance()
{
    char c = this->_src[this->_current];
    this->_current++;
    return c;
}


void Scanner::getNumber()
{
    if (this->peek() == '.' && isdigit(this->peekNext()))
    {
        this->advance();
        while (isdigit(this->peek()))
            this->advance();
    }

    std::string num_str = this->_src.substr(this->_start, this->_current);
    float processed_num = std::stof(num_str);

    this->addTokenLiteral(tokenType::NUMBER, Literal(processed_num));
}


void Scanner::getString()
{
    while (this->peek() != '"' && !this->atEnd()) {
        if (this->peek() != '\n')
            this->_line++;

        this->advance();
    }

    if (this->atEnd())
        throw "getString - CALL ERROR";
    this->advance();
    
    std::string curr_string = this->_src.substr(this->_start, this->_current);
    this->addTokenLiteral(tokenType::STRING, Literal(curr_string));
}


// Since I can't use switch statements on strings,
// I need to use a hash to identify strings fast 

// constexpr means that if the input string is known at compile-time,
//  the hash func will be executed and result will be compiled
//  during compilation. Leads to significant performance improvements.
// Can be called at compiletime and runtime. 

// constexpr functions are not exactly "for performance reasons" (though it can help), 
//  but so that you can calculate something and use the result itself in a constant expression.
//  For example, you could calculate the size of an array 
//  based on certain compile time values.
constexpr uint64_t hash(std::string_view str) {
    uint64_t hash = 0;
    for (char c : str) {
        // Using 131 for making unique codes
        // prime numbers are often used for hash functions
        //  using a prime number reduces collisions and distributes hash
        //  values more evenly.
        hash = (hash * 131) + c;
    }
    return hash;
}

// operator"" is the keyword for defining user-defined literals
//  When appending _hash to string literal, the operator will be invoked
constexpr uint64_t operator"" _hash(const char* str, size_t len) {

    // A string view is basically a fancy pointer (contains pointer and size) 
    return hash(std::string_view(str, len));
}


void Scanner::scanLiteralAndKeywords()
{
    while (isalnum(this->peek()) || this->peek() == '_') 
        this->advance();

    std::string lt = this->_src.substr(this->_start, this->_current);
    
    switch (hash(lt)) {
        case "and"_hash:
            this->addToken(tokenType::AND);
            break;
        
        case "class"_hash:
            this->addToken(tokenType::CLASS);
            break;
        
        case "else"_hash:
            this->addToken(tokenType::ELSE);
            break;
        
        case "false"_hash:
            this->addToken(tokenType::FALSE);
            break;
        
        case "fun"_hash:
            this->addToken(tokenType::FUN);
            break;
        
        case "for"_hash:
            this->addToken(tokenType::FOR);
            break;
        
        case "if"_hash:
            this->addToken(tokenType::IF);
            break;
        
        case "nil"_hash:
            this->addToken(tokenType::NIL);
            break;
        
        case "or"_hash:
            this->addToken(tokenType::OR);
            break;
        
        case "print"_hash:
            this->addToken(tokenType::PRINT);
            break;

        case "return"_hash:
            this->addToken(tokenType::RETURN);
            break;
        
        case "super"_hash:
            this->addToken(tokenType::SUPER);
            break;
        
        case "this"_hash:
            this->addToken(tokenType::THIS);
            break;

        case "true"_hash:
            this->addToken(tokenType::TRUE);
            break;
        
        case "var"_hash:
            this->addToken(tokenType::VAR);
            break;
        
        case "while"_hash:
            this->addToken(tokenType::WHILE);
            break;

        default:
            this->addTokenLiteral(tokenType::IDENTIFIER, Literal(lt));        
    }
}


void Scanner::scanToken()
{
    char curr = this->advance();


    if ((curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z'))
    {
        this->scanLiteralAndKeywords();
        return;
    }
    else if (curr >= '0' && curr <= '9')
    {
        this->getNumber();
        return;
    }

    switch (curr)
    {
        

        case '{':
            this->addToken(tokenType::LeftBrace);
            break;
            
        case '}':
            this->addToken(tokenType::RightBrace);
            break;

        case '(':
            this->addToken(tokenType::LeftParen);
            break;

        case ')':
            this->addToken(tokenType::RightParen);
            break;

        case '[':
            this->addToken(tokenType::LeftSqrBrace);
            break;

        case ']':
            this->addToken(tokenType::RightSqrBrace);
            break;

        case ',':
            this->addToken(tokenType::COMMA);
            break;

        case '.':
            this->addToken(tokenType::DOT);
            break;

        case '-':
            this->addToken(tokenType::MINUS);
            break;

        case '+':
            this->addToken(tokenType::PLUS);
            break;

        case ';':
            this->addToken(tokenType::SEMICOLON);
            break;

        case '*':
            this->addToken(tokenType::STAR);
            break;

        case '\0':
            this->addToken(tokenType::END);
            break;


        char next;
        case '!':
            next = this->peekNext();

            if (next == '=')
                this->addToken(tokenType::BangEqual);
            else
                this->addToken(tokenType::BANG);
            break;

        case '=':
            next = this->peekNext();

            if (next == '=')
                this->addToken(tokenType::EqualEqual);
            else
                this->addToken(tokenType::EQUAL);
            break;

        case '>':
            next = this->peekNext();

            if (next == '=')
                this->addToken(tokenType::GreaterEqual);
            else
                this->addToken(tokenType::GREATER);
            break;

        case '<':
            next = this->peekNext();

            if (next == '=')
                this->addToken(tokenType::LessEqual);
            else
                this->addToken(tokenType::LESS);
            break;

        case '"':
            this->getString();
            break;

        case '/':
            next = this->peekNext();

            if (next == '/') {
                next = this->advance();

                while (this->peek() != '\n' && !this->atEnd())
                    char _ = this->advance();
            }
            else
                this->addToken(tokenType::SLASH);
            break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\\':
            next = this->peekNext();
                
            if (next  == 'n')
                this->_line += 1;
            break;

        default:
            break;
    }
}


////////////////////////////////////////////////////////////////////////////
// public:


Scanner::Scanner(std::string src)
{
    _src = src;
    _src_length = _src.length();
}


Scanner::~Scanner()
{
}

std::vector<Token> Scanner::getTokens() {
    return _tokens;
}

bool Scanner::Scan()
{
    while ( !this->atEnd() )
    {
        this->_start = this->_current;
        this->scanToken();
    }

    return true;
}
