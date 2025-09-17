// #include <iostream>
// #include <memory>
// #include <vector>
// #include <deque>
// #include <string>

// #include "token.hpp"


// class Stmt;
// class Decl;
// class Expr;
// class FunDecl;
// class ClassDecl;
// class VarDecl;
// class FunctionStmt;
// class ForStmt;
// class ExprStmt;
// class IfStmt;
// class PrintStmt;
// class ReturnStmt;
// class WhileStmt;
// class BlockStmt;
// class LogicExpr;
// class UnaryExpr;
// class BinaryExpr;
// class AssignExpr;
// class CallExpr;
// class LiteralExpr;
// class VarExpr;
// class GroupExpr;


// /////////////////////////////////////////////////
// // Declarations

// class Decl
// {
// public:
//     virtual ~Decl() {}
// };

// class FunDecl : public Decl
// {
// public:
//     Token name;
//     std::vector<Token> params;
//     std::unique_ptr<BlockStmt> body;

//     FunDecl(Token name, std::vector<Token> params, std::unique_ptr<BlockStmt> body)
//         : name(name), params(params), body(std::move(body)) {}
// };

// class ClassDecl : public Decl
// {
// public:
//     Token name;
//     std::unique_ptr<Token> super_class;
//     std::vector<std::unique_ptr<FunDecl>> methods;

//     ClassDecl(Token name, std::unique_ptr<Token> super_class, 
//               std::vector<std::unique_ptr<FunDecl>> methods)
//         : name(name), super_class(std::move(super_class)), methods(std::move(methods)) {}
// };

// class VarDecl : public Decl
// {
// public:
//     Token identity;
//     std::unique_ptr<Expr> express;

//     VarDecl(Token identity, std::unique_ptr<Expr> express)
//         : identity(identity), express(std::move(express)) {}
// };

// /////////////////////////////////////////////////
// // Statement

// class Stmt
// {
// public:
//     virtual ~Stmt() {}
// };

// class FunctionStmt : public Stmt
// {
// public:
//     Token name;
//     std::vector<Token> params;
//     std::unique_ptr<BlockStmt> body;

//     FunctionStmt(Token name, std::vector<Token> params, std::unique_ptr<BlockStmt> body)
//         : name(name), params(params), body(std::move(body)) {}
// };

// class DeclStmt : public Stmt 
// {
// public:
//     std::unique_ptr<Decl> declaration;

//     DeclStmt(std::unique_ptr<Decl> decl) : declaration(std::move(decl)) {}
// };

// class ExprStmt : public Stmt
// {
// public:
//     std::unique_ptr<Expr> expression; 

//     ExprStmt(std::unique_ptr<Expr> expr) : expression(std::move(expr)) {}
// };

// class ForStmt : public Stmt
// {
// public:
//     std::unique_ptr<Stmt> initializer;
//     std::unique_ptr<Expr> condition;
//     std::unique_ptr<Expr> increment;
//     std::unique_ptr<Stmt> body;

//     ForStmt(std::unique_ptr<Stmt> initializer = nullptr,
//             std::unique_ptr<Expr> condition = nullptr,
//             std::unique_ptr<Expr> increment = nullptr,
//             std::unique_ptr<Stmt> body = nullptr)
//         : initializer(std::move(initializer)),
//           condition(std::move(condition)),
//           increment(std::move(increment)),
//           body(std::move(body)) {}
// };

// class IfStmt : public Stmt
// {
// public:
//     std::unique_ptr<Expr> condition;
//     std::unique_ptr<Stmt> then_stmt;
//     std::unique_ptr<Stmt> else_stmt;

//     IfStmt(std::unique_ptr<Expr> condition,
//            std::unique_ptr<Stmt> then_stmt,
//            std::unique_ptr<Stmt> else_stmt = nullptr)
//         : condition(std::move(condition)),
//           then_stmt(std::move(then_stmt)),
//           else_stmt(std::move(else_stmt)) {}
// };

// class PrintStmt : public Stmt
// {
// public:
//     std::unique_ptr<Expr> expression;

//     PrintStmt(std::unique_ptr<Expr> expr) : expression(std::move(expr)) {}
// };

// class ReturnStmt : public Stmt
// {
// public:
//     std::unique_ptr<Expr> value;

//     ReturnStmt(std::unique_ptr<Expr> val = nullptr) : value(std::move(val)) {}
// };

// class WhileStmt : public Stmt
// {
// public:
//     std::unique_ptr<Expr> condition;
//     std::unique_ptr<Stmt> body;

//     WhileStmt(std::unique_ptr<Expr> condition, std::unique_ptr<Stmt> body)
//         : condition(std::move(condition)), body(std::move(body)) {}
// };

// class BlockStmt : public Stmt
// {
// public:
//     std::vector<std::unique_ptr<Decl>> declarations; 

//     BlockStmt(std::vector<std::unique_ptr<Decl>> decls) 
//         : declarations(std::move(decls)) {}
// };

// /////////////////////////////////////////////////
// // Expression and its children

// class Expr
// {
// public:
//     virtual ~Expr() {}
// };

// class LogicOrExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     std::unique_ptr<Expr> right;

//     LogicOrExpr(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
//         : left(std::move(left)), right(std::move(right)) {}
// };

// class LogicAndExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     std::unique_ptr<Expr> right;

//     LogicAndExpr(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
//         : left(std::move(left)), right(std::move(right)) {}
// };

// class EqualityExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     Token op;
//     std::unique_ptr<Expr> right;

//     EqualityExpr(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right)
//         : left(std::move(left)), op(op), right(std::move(right)) {}
// };

// class CompExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     Token op;  // Added operator
//     std::unique_ptr<Expr> right;

//     CompExpr(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right)
//         : left(std::move(left)), op(op), right(std::move(right)) {}
// };

// class TermExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     Token op;  // Added operator
//     std::unique_ptr<Expr> right;

//     TermExpr(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right)
//         : left(std::move(left)), op(op), right(std::move(right)) {}
// };

// class FactorExpr: public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     Token op;  // Added operator
//     std::unique_ptr<Expr> right;

//     FactorExpr(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right)
//         : left(std::move(left)), op(op), right(std::move(right)) {}
// };

// class UnaryExpr : public Expr
// {
// public:
//     Token op;
//     std::unique_ptr<Expr> right;

//     UnaryExpr(Token op, std::unique_ptr<Expr> right)
//         : op(op), right(std::move(right)) {}
// };

// class BinaryExpr : public Expr 
// {
// public:
//     std::unique_ptr<Expr> left;
//     Token op;
//     std::unique_ptr<Expr> right;

//     BinaryExpr(std::unique_ptr<Expr> left, Token op, std::unique_ptr<Expr> right)
//         : left(std::move(left)), op(op), right(std::move(right)) {}
// };

// class AssignExpr : public Expr 
// {
// public:
//     std::unique_ptr<Expr> target;    
//     std::unique_ptr<Expr> value;    

//     AssignExpr(std::unique_ptr<Expr> target, std::unique_ptr<Expr> value)
//         : target(std::move(target)), value(std::move(value)) {}
// };

// class CallExpr : public Expr
// {
// public:
//     std::unique_ptr<Expr> callee;
//     std::vector<std::unique_ptr<Expr>> arguments;

//     CallExpr(std::unique_ptr<Expr> callee, std::vector<std::unique_ptr<Expr>> args)
//         : callee(std::move(callee)), arguments(std::move(args)) {}
// };

// class LiteralExpr : public Expr
// {
// public:
//     Literal value;
    
//     LiteralExpr(const Literal& val) : value(val) {}
// };

// class VarExpr : public Expr {
// public:
//     Token name;
    
//     VarExpr(const Token& name) : name(name) {}
// };

// class GroupExpr : public Expr
// {
// public:
//     std::unique_ptr<Expr> expression;

//     GroupExpr(std::unique_ptr<Expr> expr) : expression(std::move(expr)) {}
// };

// class GetExpr : public Expr {
// public:
//     std::unique_ptr<Expr> object;
//     Token name;

//     GetExpr(std::unique_ptr<Expr> object, const Token& name) 
//         : object(std::move(object)), name(name) {}
// };

// /////////////////////////////////////////////////
// // Parser

// class Parser
// {
// private:
//     std::vector<std::unique_ptr<Decl>> _declarations;
//     std::deque<Token> _tokens;

//     // AST building functions
//     void errorMsg(std::string msg, int line);
//     bool isAtEnd();

//     const Token& matchToken(const Token& token, const tokenType& expected);
//     const Token& consume(tokenType expected, const std::string& msg);
//     const Token& peek();
//     const Token& advance();

//     ///////////////////////////////////////////////////////////////////////
//     // Grammar

//     // Declarations
//     std::unique_ptr<Decl> declaration();
//     std::unique_ptr<ClassDecl> classDecl();
//     std::unique_ptr<FunDecl> funDecl();
//     std::unique_ptr<VarDecl> varDecl();

//     // Statements
//     std::unique_ptr<Stmt> statement();
//     std::unique_ptr<ExprStmt> exprStmt();
//     std::unique_ptr<ForStmt> forStmt();
//     std::unique_ptr<IfStmt> ifStmt();
//     std::unique_ptr<PrintStmt> printStmt();
//     std::unique_ptr<ReturnStmt> returnStmt();
//     std::unique_ptr<WhileStmt> whileStmt();

//     std::unique_ptr<BlockStmt> block();
//     std::unique_ptr<Expr> expression();
//     std::unique_ptr<Expr> assignment();

//     // Logic
//     std::unique_ptr<LogicOrExpr> logic_or();
//     std::unique_ptr<LogicAndExpr> logic_and();
//     std::unique_ptr<EqualityExpr> equality();
//     std::unique_ptr<CompExpr> comparison();
//     std::unique_ptr<TermExpr> term();
//     std::unique_ptr<FactorExpr> factor();

//     std::unique_ptr<Expr> unary();
//     std::unique_ptr<CallExpr> call();
//     std::unique_ptr<Expr> primary();

//     // Functions
//     std::unique_ptr<FunDecl> function();
//     std::vector<Token> parameters();
//     std::vector<std::unique_ptr<Expr>> arguments();

// public:
//     Parser();
//     ~Parser();

//     void parseTokens(std::vector<Token> tokens);
//     const std::vector<std::unique_ptr<Decl>>& getAstTree();
// };
