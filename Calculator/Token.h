/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.h
 * Author: lukemiller
 *
 * Created on October 6, 2019, 9:24 PM
 */



#ifndef TOKEN_H
#define TOKEN_H

#include "Token.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Token 
{
public:
    Token();
    Token(const Token& orig);
    Token(string s);
    ~Token();
    enum Token_type {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};
    void set(string s);
    int value() const;
    void display() const;

    //Accessors
    Token_type get_type() const;
    string get_token() const;
    int get_priority() const;

private:
    Token_type type;
    string token;
    int priority;
};

#endif /* TOKEN_H */

