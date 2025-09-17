// #include <iostream>
// #include <memory>
// #include <string>
// #include <vector>
// #include <deque>

// #include "token.hpp"
// #include "parser.hpp"


// // // Constructor / Destructor
// Parser::Parser() 
// {
// }

// Parser::~Parser() 
// {
// }


// // /////////////////////////////////////////////////
// // // AST builder helper functions

// // // TODO: Extremely basic exception handler. Will eventually make an exception class
// // // to handle different types of errors. I also want the user to have access to it
// // // so they can throw specific errors.
// void Parser::errorMsg(std::string msg, int line)
// {
//     std::string err = msg + "\nLine: " + std::to_string(line);
//     throw err;
// }







// bool isAtEnd();


// const Token& matchToken(const Token& token, const tokenType& expected);
// const Token& consume(tokenType expected, const std::string& msg);
// const Token& peek();
// const Token& advance();


// // Declarations
// std::unique_ptr<Decl> Parser::declaration()
// {
//     std::cout << "Parser::declaration" << std::endl;

//     if (peek().token_type == tokenType::CLASS)
//         return classDecl();

//     if (peek().token_type == tokenType::FUN)
//         return funDecl();
    
//     if (peek().token_type == tokenType::VAR)
//         return varDecl();

//     std::unique_ptr<Stmt> stmt = statement();
//     consume(tokenType::SEMICOLON, "Expected ';' after statement.");

//     return stmt;
// }

// std::unique_ptr<ClassDecl> Parser::classDecl()
// {

// }

// std::unique_ptr<FunDecl> Parser::funDecl()
// {

// }

// std::unique_ptr<VarDecl> Parser::varDecl()
// {
    
// }


// // Statements
// std::unique_ptr<Stmt> Parser::statement()
// {

// }

// std::unique_ptr<ExprStmt> Parser::exprStmt()
// {

// }

// std::unique_ptr<ForStmt> Parser::forStmt()
// {

// }

// std::unique_ptr<IfStmt> Parser::ifStmt()
// {

// }

// std::unique_ptr<PrintStmt> Parser::printStmt()
// {

// }

// std::unique_ptr<ReturnStmt> Parser::returnStmt()
// {

// }

// std::unique_ptr<WhileStmt> Parser::whileStmt()
// {

// }


// std::unique_ptr<BlockStmt> Parser::block()
// {

// }

// std::unique_ptr<Expr> Parser::expression()
// {

// }

// std::unique_ptr<Expr> Parser::assignment()
// {

// }


// // Logic
// std::unique_ptr<LogicOrExpr> Parser::logic_or()
// {

// }

// std::unique_ptr<LogicAndExpr> Parser::logic_and()
// {

// }

// std::unique_ptr<EqualityExpr> Parser::equality()
// {

// }

// std::unique_ptr<CompExpr> Parser::comparison()
// {

// }

// std::unique_ptr<TermExpr> Parser::term()
// {

// }

// std::unique_ptr<FactorExpr> Parser::factor()
// {

// }


// std::unique_ptr<Expr> Parser::unary()
// {

// }

// std::unique_ptr<CallExpr> Parser::call()
// {

// }

// std::unique_ptr<Expr> Parser::primary()
// {

// }


// // Functions
// std::unique_ptr<FunDecl> Parser::function()
// {

// }

// std::vector<Token> Parser::parameters()
// {

// }

// std::vector<std::unique_ptr<Expr>> Parser::arguments()
// {

// }


// void Parser::parseTokens(std::vector<Token> tokens)
// {
//     std::cout << "Parser::parseTokens" << std::endl;

//     // moving to a deque to pop tokens from front as we create AST.
//     _tokens = std::deque<Token>(std::make_move_iterator(tokens.begin()),
//                                  std::make_move_iterator(tokens.end()));

//     if (_tokens.empty())
//         return;    

//     while(!isAtEnd()) {
//         std::cout << "while loop" << std::endl;
//         _declarations.push_back(declaration());
//     }
// }








// // const Token& Parser::peek()
// // {
// //     return _tokens.front();
// // }


// // bool Parser::isAtEnd()
// // {
// //     return _tokens.empty() || peek().token_type == tokenType::END;
// // }


// // const Token& Parser::advance()
// // {
// //      const Token& current = peek(); 
// //     _tokens.pop_front(); 

// //     return current;
// // }


// // const Token& Parser::matchToken(const Token& token, const tokenType& expected)
// // {
// //     if (token.token_type != expected) 
// //     {
// //         const std::string msg = "Expected " + expected;
// //         errorMsg(msg, token.line);
// //     } 
// //     return advance();
// // }


// // const std::vector<Decl*>& Parser::getAstTree()
// // {
// //     return _declarations;
// // }


// // const Token& Parser::consume(tokenType expected, const std::string& msg) {
// //     if (peek().token_type != expected) {
// //         errorMsg(msg, peek().line);
// //     }
// //     return advance();
// // }


// // /////////////////////////////////////////////////
// // // Grammar
    
// // // declaration
// // Decl* Parser::declaration()
// // {
//     // std::cout << "Parser::declaration" << std::endl;

//     // if (peek().token_type == tokenType::CLASS)
//     //     return classDecl();

//     // if (peek().token_type == tokenType::FUN)
//     //     return funDecl();
    
//     // if (peek().token_type == tokenType::VAR)
//     //     return varDecl();

//     // Stmt* stmt = statement();
//     // consume(tokenType::SEMICOLON, "Expected ';' after statement.");

// //     // TODO:
// //     // If your `Decl` class is meant for top-level declarations only,
// //     // and `Stmt` is a separate hierarchy, you might need a way to wrap
// //     // a Stmt into a Decl, or adjust your base classes.
// //     // For now, let's assume a simple case where a statement can also be a top-level Decl.
// //     // In many languages, an ExpressionStatement is a common top-level construct.
// //     // A common approach is to have an `ExprStmt` that inherits from `Stmt`,
// //     // and then the `declaration` function would return `new ExprStmt(expression())`.
// //     // Since your `ExprStmt` is already a `Stmt`, and `Stmt` is not a `Decl`,
// //     // you have a slight mismatch. The simplest fix for now is to return the statement directly
// //     // and assume `Decl` can encompass `Stmt` or that `ExprStmt` is the only top-level statement.
// //     // A more robust solution might involve a `StatementDecl` wrapper if `Decl` and `Stmt`
// //     // are strictly separate hierarchies at the top level.
    
// //     // For the purpose of getting this working, and assuming `Stmt` can be treated as a `Decl`
// //     // at the top-level program structure, we will return the Stmt* directly.
// //     // If your `Decl` and `Stmt` hierarchies are truly separate and `Decl` is only for
// //     // `class`, `fun`, `var`, then you'd need a `StatementDeclaration` class that wraps a `Stmt*`.
    
// //     // For now, let's return the statement, but be aware of this design point.
// //     // You might need a specific `StatementDecl` class if `Decl` is strictly for actual declarations.
// //     // For a minimal working example, we'll cast it, assuming `Stmt` can be handled as a `Decl`
// //     // at the program's top level.
// //     return dynamic_cast<Decl*>(stmt); 
// // }

// // ClassDecl* Parser::classDecl()
// // {
// //     std::cout << "Parser::classDecl" << std::endl;

// //     consume(tokenType::CLASS, "Expected 'class' before identifier");
// //     Token name = consume(tokenType::IDENTIFIER, "Expected 'Identifier'");
// //     Token* super_class = nullptr;
    
// //     consume(tokenType::LeftBrace, "Expected '{'");
    
// //     std::vector<FunDecl*> functions;
// //     while(peek().token_type == tokenType::FUN)
// //         functions.push_back(funDecl());
    
// //     consume(tokenType::RightBrace, "Expected '}'");
// //     consume(tokenType::SEMICOLON, "Expected ';'");


// //     return new ClassDecl(name, super_class, functions);
// // }


// // FunDecl* Parser::funDecl()
// // {
// //     std::cout << "Parser::funDecl" << std::endl;

// //     consume(tokenType::FUN, "Expected 'fun'");
// //     Token name = consume(tokenType::IDENTIFIER, "Expected 'Identifier'");

// //     consume(tokenType::LeftParen, "Expected '('");
// //     std::vector<Token> params;
// //     if (peek().token_type != tokenType::RightParen) {
// //         params = parameters();
// //     }
// //     consume(tokenType::RightParen, "Expected ')'");
// //     BlockStmt* body = block();
// //     return new FunDecl(name, params, body);
// // }


// // VarDecl* Parser::varDecl()
// // {
// //     std::cout << "Parser::varDecl" << std::endl;

// //     consume(tokenType::VAR, "Expected 'var'");
// //     Token name = consume(tokenType::IDENTIFIER, "Expected 'Identifier'");
// //     Expr* express = nullptr;

// //     if (peek().token_type == tokenType::EQUAL) {
// //         consume(tokenType::EQUAL, "Expected '='");
// //         express = expression();
// //     }

// //     consume(tokenType::SEMICOLON, "Expected ';'");
// //     return new VarDecl(name, express);
// // }
    

// // /////////////////////////////////////////////////
// // // Statements
// // Stmt* Parser::statement()
// // {
// //     std::cout << "Parser::statement" << std::endl;

// //     if (peek().token_type == tokenType::LeftBrace)
// //         return block();
// //     else if (peek().token_type == tokenType::WHILE)
// //         return whileStmt();
// //     else if (peek().token_type == tokenType::RETURN)
// //         return returnStmt();
// //     else if (peek().token_type == tokenType::PRINT)
// //         return printStmt();
// //     else if (peek().token_type == tokenType::IF)
// //         return ifStmt();
// //     else if (peek().token_type == tokenType::FOR)
// //         return forStmt();
// //     else 
// //         return exprStmt();
// // }


// // ExprStmt* Parser::exprStmt()
// // {
// //     std::cout << "Parser::exprStmt" << std::endl;

// //     auto expr = expression();
// //     consume(tokenType::SEMICOLON, "Expected ';'");

// //     return new ExprStmt(expr);
// // }


// // ForStmt* Parser::forStmt()
// // {
// //     std::cout << "Parser::forStmt" << std::endl;

// //     consume(tokenType::FOR, "Expected 'for' keyword.");
// //     consume(tokenType::LeftParen, "Expected '(' after 'for'.");

// //     Stmt* initializer = nullptr;
// //     if (peek().token_type == tokenType::VAR) {
// //         initializer = new DeclStmt(varDecl());
// //     } else if (peek().token_type == SEMICOLON) {
// //         advance();
// //     } else {
// //         initializer = exprStmt();
// //     }
// //     consume(tokenType::SEMICOLON, "Expected ';'");
    
// //     auto expr_one = expression();
// //     consume(tokenType::SEMICOLON, "Expected ';'");
    
// //     auto expr_two = expression();
// //     consume(tokenType::RightParen, "Expected ')'");

// //     Stmt* body = statement();

// //     return new ForStmt(initializer, expr_one, expr_two, body);
// // }


// // IfStmt* Parser::ifStmt()
// // {
// //     std::cout << "Parser::ifStmt" << std::endl;

// //     consume(tokenType::IF, "Expected 'if'");
// //     consume(tokenType::LeftParen, "Expected '('");

// //     Expr* condition = expression();  

// //     consume(tokenType::RightParen, "Expected ')'");

// //     Stmt* then_statement = statement();
// //     Stmt* else_statement = nullptr;

// //     if (peek().token_type == tokenType::ELSE) {
// //         consume(tokenType::ELSE, "Expected 'else'");
// //         else_statement = statement();
// //     }

// //     return new IfStmt(condition, then_statement, else_statement);
// // }


// // PrintStmt* Parser::printStmt()
// // {
// //     std::cout << "Parser::printStmt" << std::endl;

// //     consume(tokenType::PRINT, "Expected 'print'");
// //     Expr* print_expr = expression();
// //     consume(tokenType::SEMICOLON, "Expected ';'");

// //     return new PrintStmt(print_expr);
// // }


// // ReturnStmt* Parser::returnStmt()
// // {
// //     std::cout << "Parser::returnStmt" << std::endl;

// //     consume(tokenType::RETURN, "Expected 'return'");

// //     Expr* return_expr = nullptr;

// //     if (peek().token_type != tokenType::SEMICOLON) {
// //         return_expr = expression();
// //     }

// //     consume(tokenType::SEMICOLON, "Expected ';'");

// //     return new ReturnStmt(return_expr);
// // }


// // WhileStmt* Parser::whileStmt()
// // {
// //     std::cout << "Parser::whileStmt" << std::endl;

// //     consume(tokenType::WHILE, "Expected 'while'");
// //     consume(tokenType::LeftParen, "Expected '('");

// //     Expr* condition = expression();

// //     consume(tokenType::RightParen, "Expected ')'");

// //     Stmt* action = statement();

// //     return new WhileStmt(condition, action);
// // }

    
// // BlockStmt* Parser::block()
// // {
// //     std::cout << "Parser::block" << std::endl;

// //     consume(tokenType::LeftBrace, "Expected '{'");

// //     std::vector<Decl*> decl_vector;

// //     while (peek().token_type != tokenType::RightBrace)
// //         decl_vector.push_back(declaration());

// //     consume(tokenType::RightBrace, "Expected '}'");

// //     return new BlockStmt(decl_vector);
// // }


// // Expr* Parser::expression()
// // {
// //     std::cout << "Parser::expression" << std::endl;
// //     return assignment();
// // }


// // Expr* Parser::assignment() 
// // {

// //     std::cout << "Parser::assignment" << std::endl;    

// //     Expr* expr = logic_or();

// //     if (peek().token_type == tokenType::EQUAL) {
// //         // expr = nullptr;
// //         Token equals_token = advance();
// //         Expr* value = assignment();
// //         // Token equals_token = advance();

// //         // Expr* value = assignment();

// //         // if (VarExpr* var_expr = dynamic_cast<VarExpr*>(expr))
// //         //     return new AssignExpr(var_expr, value);

// //         if (VarExpr* var_expr = dynamic_cast<VarExpr*>(expr)) {
// //             // Correct logic: Create an `AssignExpr` and return it.
// //             return new AssignExpr(var_expr, value);
// //         } else {
// //             // Error: Cannot assign to a non-variable expression.
// //             errorMsg("Invalid assignment target.", equals_token.line);
// //         }
// //     }

// //     return expr;
// // }


// // /////////////////////////////////////////////////
// // // Logic
// // // LogicExpr* Parser::logical()
// // // {
// // //     std::cout << "Parser::logical" << std::endl;

// // //     LogicExpr* left = equality();

// // //     Token op;
// // //     if (peek().token_type == tokenType::OR) {
// // //         op = consume(tokenType::OR, "Expected 'OR'");
// // //     } else {
// // //         op = consume(tokenType::AND, "Expected 'AND'");
// // //     }
    
// // //     LogicExpr* right = equality();

// // //     return new LogicExpr(left, op, right);
// // // }


// // LogicOrExpr* Parser::logic_or()
// // {
// //     auto left = logic_and();

// //     if (peek().token_type == OR)
// //     {
// //         advance();
// //         auto right = logic_and();
        
// //         return new LogicOrExpr(left, right);
// //     }

// //     // return nullptr;
// //     return dynamic_cast<LogicOrExpr*>(left);
// // }


// // LogicAndExpr* Parser::logic_and()
// // {
// //     auto left = equality();

// //     if (peek().token_type == AND)
// //     {
// //         advance();
// //         auto right = equality();
        
// //         return new LogicAndExpr(left, right);
// //     }
    
// //     // return nullptr;
// //     return dynamic_cast<LogicAndExpr*>(left);
// // }


// // EqualityExpr* Parser::equality()
// // {
// //     auto left = comparison();

// //     if (peek().token_type == EqualEqual || peek().token_type == BangEqual) 
// //     {
// //         advance();
// //         auto right = comparison();
        
// //         return new EqualityExpr(left, right);
// //     }
    
// //     // return nullptr;
// //     return dynamic_cast<EqualityExpr*>(left);
// // }


// // CompExpr* Parser::comparison()
// // {
// //     auto left = term();

// //     if (
// //         peek().token_type == GREATER 
// //         || peek().token_type == GreaterEqual
// //         || peek().token_type == LESS
// //         || peek().token_type == LessEqual
// //     ) 
// //     {
// //         advance();
// //         auto right = term();
        
// //         return new CompExpr(left, right);
// //     }
    
// //     // return nullptr;
// //     return dynamic_cast<CompExpr*>(left);
// // }


// // TermExpr* Parser::term()
// // {
// //     auto left = factor();

// //     if (
// //         peek().token_type == MINUS 
// //         || peek().token_type == PLUS
// //     ) 
// //     {
// //         advance();
// //         auto right = factor();
        
// //         return new TermExpr(left, right);
// //     }
    
// //     // return nullptr;
// //     return dynamic_cast<TermExpr*>(left);
// // }


// // FactorExpr* Parser::factor()
// // {
// //     auto left = unary();

// //     if (
// //         peek().token_type == SLASH 
// //         || peek().token_type == STAR
// //     ) 
// //     {
// //         advance();
// //         auto right = unary();
        
// //         return new FactorExpr(left, right);
// //     }
    
// //     // return nullptr;
// //     return dynamic_cast<FactorExpr*>(left);
// // }

// // // LogicExpr* Parser::comparison()
// // // {
// // //     std::cout << "Parser::comparison" << std::endl;

// // //     LogicExpr* left = term();

// // //     Token op;
// // //     if (peek().token_type == tokenType::GREATER) {
// // //         op = consume(tokenType::GREATER, "Expected '>'");

// // //     } else if (peek().token_type == tokenType::LESS) {
// // //         op = consume(tokenType::LESS, "Expected '<'");

// // //     } else if (peek().token_type == tokenType::LessEqual) {
// // //         op = consume(tokenType::LessEqual, "Expected '<='");

// // //     } else {
// // //         op = consume(tokenType::GreaterEqual, "Expected '>='");
// // //     } 
    
// // //     LogicExpr* right = term();

// // //     return new LogicExpr(left, op, right);
// // // }


// // // LogicExpr* Parser::term()
// // // {
// // //     std::cout << "Parser::term" << std::endl;

// // //     LogicExpr* left = factor();

// // //     Token op;
// // //     if (peek().token_type == tokenType::MINUS) {
// // //         op = consume(tokenType::MINUS, "Expected '-'");
// // //     } else {
// // //         op = consume(tokenType::PLUS, "Expected '+'");
// // //     }
    
// // //     LogicExpr* right = factor();

// // //     return new LogicExpr(left, op, right);
// // // }


// // // LogicExpr* Parser::factor()
// // // {
// // //     std::cout << "Parser::factor" << std::endl;

// // //     Expr* left = unary();

// // //     std::cout << "factor: after unary" << std::endl;

// // //     Token op;
// // //     if (peek().token_type == tokenType::SLASH) {
// // //         std::cout << "\tpeek().token_type == tokenType::SLASH" << std::endl;
// // //         op = consume(tokenType::SLASH, "Expected '/'");
// // //     } else if (peek().token_type == tokenType::DOT) {
// // //         std::cout << "\telse" << std::endl;
// // //         op = consume(tokenType::DOT, "Expected '*'");
// // //     }
    
// // //     Expr* right = unary();

// // //     return new LogicExpr(left, op, right);
// // // }


// // Expr* Parser::unary()
// // {
// //     std::cout << "Parser::unary()" << std::endl;

// //     if (peek().token_type == tokenType::BANG || peek().token_type == tokenType::MINUS) 
// //     {
// //         Token op = advance();
        
// //         Expr* right = unary();
// //         return new UnaryExpr(op, right);
// //     }    
// //     return call();
// // }


// // CallExpr* Parser::call()
// // {
// //     std::cout << "Parser::call()" << std::endl;
// //     Expr* expr = primary();

// //     std::cout << "\texpr complete" << std::endl;

// //     while (true) {

// //         std::cout << "\twhile loop" << std::endl;

// //         if (peek().token_type == tokenType::LeftParen) {
// //             std::cout << "\tpeek().token_type == tokenType::LeftParen" << std::endl;
// //             advance();

// //             // Handle function calls
// //             std::vector<Expr*> arguments;
// //             if (peek().token_type != RightParen) {
// //                 do {
// //                     advance();
// //                     arguments.push_back(expression());
// //                 } while (peek().token_type == COMMA);
// //             }
// //             consume(tokenType::RightParen, "Expect ')' after arguments");
// //             expr = new CallExpr(expr, arguments);
// //         }
// //         else if (peek().token_type == DOT) {
// //             std::cout << "\tpeek().token_type == DOT" << std::endl;
            
// //             advance();
// //             // Handle method calls/property access
// //             Token name = consume(tokenType::IDENTIFIER, 
// //                                "Expect property name after '.'");
// //             // Create a getter expression
// //             expr = new GetExpr(expr, name);
// //         }
// //         else {
// //             std::cout << "\telse" << std::endl;
// //             break;
// //         }
// //     }

// //     return dynamic_cast<CallExpr*>(expr);
// // }


// // Expr* Parser::primary()
// // {
// //     std::cout << "Parser::primary" << std::endl;

// //     const Token& token = peek();
// //     // std::cout << "\tProcessing token: " << token. << std::endl;

// //     switch(token.token_type) 
// //     {
// //         case TRUE:
// //         case FALSE:
// //         case NIL:
// //         case THIS:
// //         case NUMBER:
// //         case STRING: {
// //             std::cout << token.token_type << std::endl;

// //             Literal value = token.literal_type;

// //             std::cout << "fuck" << std::endl;            

// //             advance();

// //             std::cout << "fuck_2" << std::endl;

// //             return new LiteralExpr(value);
// //         }

// //         case IDENTIFIER:
// //             return new VarExpr(advance());
        
// //         case LeftParen: {
// //             std::cout << "\tGrouping" << std::endl;
// //             advance(); // Consume '('
// //             Expr* expr = expression();
// //             consume(tokenType::RightParen, "Expected ')' after expression");
// //             return expr;
// //         }
        
// //         // case SUPER: {
// //         //     std::cout << "\tsuper" << std::endl;
// //         //     consume(tokenType::SUPER, "Expected 'super'");
// //         //     consume(tokenType::DOT, "Expected '.'");
            
// //         //     return new GroupExpr(expr);
// //         //     // std::cout << "\tSuper" << std::endl;
// //         //     // Token superToken = advance();
// //         //     // consume(tokenType::DOT, "Expected '.' after 'super'");
// //         //     // Token method = consume(tokenType::IDENTIFIER, "Expected superclass method name");
// //         //     // return new LiteralExpr(superToken, method);
// //         // }
        
// //         default:
// //             // errorMsg("Unexpected token in expression: ", token.line);
// //             return nullptr; // Won't reach here
// //     }
// // }



// // /////////////////////////////////////////////////
// // // Functions

// // FunDecl* Parser::function()
// // {   
// //     std::cout << "Parser::functions" << std::endl;

// //     // function → IDENTIFIER "(" parameters? ")" block ;
// //     Token identity = consume(tokenType::IDENTIFIER, "Expected 'Identifier'");
// //     consume(tokenType::LeftParen, "Expected '('");

// //     std::vector<Token> params = parameters();
// //     consume(tokenType::RightParen, "Expected ')'");

// //     BlockStmt* block_statement = block();

// //     return new FunDecl(identity, params, block_statement);
// // }


// // std::vector<Token> Parser::parameters()
// // {
// //     std::cout << "Parser::parameters" << std::endl;

// //     std::vector<Token> params;

// //     params.push_back(consume(tokenType::IDENTIFIER, "Expected parameter name."));

// //     while (peek().token_type == tokenType::COMMA) {
// //         consume(tokenType::COMMA, "Expected ',' between parameters.");
// //         params.push_back(consume(tokenType::IDENTIFIER, "Expected parameter name after ','."));
// //     }

// //     return params;
// // }


// // std::vector<Token> Parser::arguments()
// // {
// //     std::cout << "Parser::arguments" << std::endl;

// //     auto identity = consume(tokenType::IDENTIFIER, "Expected 'Identifier'");
    
// //     std::vector<Token> args;
// //     args.push_back(identity);

// //     while (peek().token_type == tokenType::COMMA)
// //     {
// //         consume(tokenType::COMMA, "Expected ','");
// //         args.push_back(consume(tokenType::IDENTIFIER, "Expected 'Identifier'"));
// //     }   

// //     return args;
// // }



// // void Parser::parseTokens(std::vector<Token> tokens)
// // {
// //     std::cout << "Parser::parseTokens" << std::endl;

// //     // moving to a deque to pop tokens from front as we create AST.
// //     _tokens = std::deque<Token>(std::make_move_iterator(tokens.begin()),
// //                                  std::make_move_iterator(tokens.end()));

// //     if (_tokens.empty())
// //         return;

    

// //     while(!isAtEnd()) {
// //         std::cout << "while loop" << std::endl;
// //         _declarations.push_back(declaration());
// //     }
// // }
