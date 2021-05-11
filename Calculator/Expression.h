/* 
 * File:   Expression.h
 * Author: Luke Miller
 *
 * Created on October 7, 2019, 10:44 PM
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Token.h"
#include "Expression.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

class Expression {
public:
    
    enum Exp_type {assignment, arithmetic, illegal};
    
    Expression();
    Expression(const string& s);
    Expression(const Expression& orig);
    
    void set(const string& s);

    void display_postfix() const;
    void display_prefix() const;
    void display_paren() const;
    void display_eval() const;

    Exp_type get_type() const;
    bool get_valid() const;

    ~Expression();
    
private:

    void setNext(const string& s);
    bool splitSemi(const string& s);
    void tokenize(const string& s);
    void postfixToken();
    void prefixToken();
    bool syntaxCheck();
    void paren();
    void calc(vector<Expression> assignments);
    
    //Properties
    Exp_type type;
    int eval;
    bool valid;
    bool runnable;
    string original;
    string parenthisized;
    string prefix;
    vector<string> next;
    vector<Token> tokenized;
    vector<Token> postfix;
    vector<Expression> expressionized;
    vector<Expression> assignments;
    
};

#endif /* EXPRESSION_H */

