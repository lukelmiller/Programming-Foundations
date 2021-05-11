/* 
 * File:   Token.cpp
 * Created on October 6, 2019, 9:24 PM
 */

#include "Token.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack> 

using namespace std;
    enum Token_type{ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};
    Token::Token(){
        type = INVALID;
        token = "";
        priority = -1;
    }
    Token::Token(const Token& orig){
        token =orig.token;
        type = orig.type;
        priority = orig.priority;
    }
    Token::Token(string s){
        token = s;
        this->set(s);
    }
    Token::~Token(){
    }
    void Token::set(string s){
        token = s;
        bool frontIsLetter = false;
        bool buildID = false;
        bool buildINT = false;
        bool frontIsNumber = false;
        bool frontIsZero = false;
        int buildCount = 0;
        if(isalpha(s.front()))
            frontIsLetter = true;
        if(isdigit(s.front()))
            frontIsNumber = true;
        if(s.front()=='0')
            frontIsZero = true;
        if(s.size()==1){
            char t = s[0];           
            if(t=='+'||t=='-'){
                type = OP;
                priority = 1;
            }
            else if(t=='*'||t=='/'){
                type = OP;
                priority = 2;
            }
            else if(t=='='){
                type = EQ;
                priority = -1;
            }
            else if(t=='('){
                priority = 0;
                type = OpenBrace;
            }
            else if(t==')'){
                type = CloseBrace;
                priority = -1;
            }
            else if(isdigit(t)){
                type = INT;
                priority = -1;
            }
            else if(isalpha(t)){
                type = ID;
                priority = -1;
            }
            else{
                type = INVALID;
                priority = -1;
            }
        }else{
            for(int i=0; i<s.size(); i++){
                char t = s[i]; 
                if(frontIsLetter){
                    if(isalnum(t) and t!=' '){
                        buildID = true;
                        buildCount++;
                    }
                    else
                        buildID = false;
                }
                else if(frontIsNumber && !frontIsZero){
                    if(isdigit(t))
                        buildINT = true;
                    else
                        buildINT = false;
                }
                else
                    break;
            }
                if(buildID&&buildCount == s.size())
                    type = ID;
                else if(buildINT)
                    type= INT;
                else
                    type = INVALID;
        }
    }
    int Token::value() const{
        int ret = -2;
        if(type == INT)
            ret = stoi(token);
        else if(type == ID)
            ret = -1;
        return ret;
    }
    void Token::display() const{
        cout<<"type = ";
        if(type==0)
            cout<<"ID"<<endl;
        if(type==1)
            cout<<"INT"<<endl;
        if(type==2)
            cout<<"OP"<<endl;
        if(type==3)
            cout<<"EQ"<<endl;
        if(type==4)
            cout<<"OpenBrace"<<endl;
        if(type==5)
            cout<<"CloseBrace"<<endl;
        if(type==6)
            cout<<"INVALID"<<endl;
        cout<<"token = "<< token<< " (value is " <<value()<< ")"<<endl;
        cout<<"priority = "<< priority<<endl<<endl;
    }
    //Accessors
    Token::Token_type Token::get_type() const{
        return type;
    }
    string Token::get_token() const{
        return token;
    }
    int Token::get_priority() const{
        return priority;
    }
