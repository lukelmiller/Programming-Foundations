//@author lukelmiller
/* 
 * File:   homework6.cpp
 * Created on November 18, 2019, 8:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Expression.h"
#include "Token.h"
using namespace std;

//Variables
char action;
string in;
Expression input;

//FUNCTIONS USED BY MAIN
//Tests Input From User
bool inputTest(string testStr){
    input.set(testStr);
    if(input.get_valid() == false){
        cout<<testStr<<" <-invalid input"<<endl;
        cout<<"input:";
        return false; 
    }
    return true;
}
//Tests Action From User
bool actionSwitchTest(char trigger){
    action = tolower(trigger);
    switch(action){
        case '=':
            input.display_eval();break;
        case '>':
            input.display_prefix();break;
        case '<':
            input.display_postfix();break;
        case 'f':
            input.display_paren();break;
        case 'q':
            break;
        case'c':
            break;
        case's':
            break;
        default:
            cout<<trigger<<" <-invalid action"<<endl;
            cout<<"action:";
            return false;
            break;
    }
    return true;
}
//Prompt for Input
void promptIn(){
    if(action == 'c'){
        string temp = in;
        cout<<"input:";
        do{
            getline(cin,in);
            temp+=in;
            in = temp;
        }while(!inputTest(in));
    }
    else{
        in = "";
        cout<<"input:";
        do{
            getline(cin,in);
        }while(!inputTest(in));
    }
}
//Prompt for Action
void promptAct(){
    string act;
    cout<<"action:";
    do{
        getline(cin,act);
    }while(!actionSwitchTest(act[0]));
}

//MAIN - The Composer of the Program
int main() {
    cout<<"=== expression evaluation program starts ==="<<endl;
    //Error Check and Worst Case Scenario Reboot
    try{
        do{
            promptIn();
            do{
                promptAct();
            }while(action!='c'&&action!='s'&&action!='q');
        }while(action!='q');
        cout<<"=== expression evaluation program ends ==="<<endl;
    }catch(...){
        cout<<"=== expression evaluation program ends ==="<<endl;
        cout<<endl << "       ~An unexpected error occurred~"<<endl<<"Check input for syntax errors before Return"<<endl<<endl<<"\t  ...Restarting program..."<<endl;
        main();
    }
    return 0;
}

