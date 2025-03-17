#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_
#include <iostream>
using namespace std;
class Expression {
public:
    Expression() { cout << "ctor expression" << endl;}
    virtual int solve() = 0;
};

class TerminalExpression : public Expression {
protected:
    int x;
public:
    TerminalExpression(int x);
    int solve();
};

class UnaryExpression : public Expression {
protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual int solve() = 0;
};

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;
public:
    BinaryExpression(Expression* x, Expression* y);
    virtual int solve() = 0;
};

#endif