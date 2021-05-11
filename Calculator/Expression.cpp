//@author lukelmiller
/* 
 * File:   Expression.cpp
 * Created on October 7, 2019, 10:44 PM
 */
#include "Token.h"
#include "Expression.h"

using namespace std;

//TYPE DECLORATION
enum Exp_type {assignment, arithmetic, illegal};

//CONSTRUCTORS
//Default Constructor
Expression::Expression(){
    original = "";
    valid = false;
    type = illegal;
}
//Constructor for sending string Expression
Expression::Expression(const string& s){
    original = s;
    this->set(s);
}
//Copy Constructor
Expression::Expression(const Expression& orig){
    valid = orig.valid;
    runnable = orig.runnable;
    type = orig.type;
    eval = orig.eval;
    original = orig.original;
    parenthisized = orig.parenthisized;
    prefix = orig.prefix;
    tokenized = orig.tokenized;
    postfix = orig.postfix;
    expressionized = orig.expressionized;
    assignments = orig.assignments;
}

//FUNCTIONS USED BY CONSTRUCTORS
//sets the whole expression
void Expression::set(const string& s){
    original = "";
    parenthisized.clear();
    prefix.clear();
    next.clear();
    tokenized.clear();
    postfix.clear();
    expressionized.clear();
    assignments.clear();
    valid = true;

    //chunk by ';'
    valid = splitSemi(s);
    
    for(int i = 0; i < next.size() && valid == true; i++){
        //make each chunk an expression and push it into expression vector
        Expression chunk;
        chunk.setNext(next[i]);
        expressionized.push_back(chunk);
        //if its an assignment then push it into assignment vector for evaluation
        if(chunk.type == assignment)
            assignments.push_back(chunk);
        else if(chunk.type == illegal){
            valid = false;
        }
    }
    //if the entire expression is valid then loop through the chunks that are arithmetic and calculate them (sending the assignments as a parameter)
    if(valid){
        for(int i = 0; i<expressionized.size(); i++){
            if(expressionized[i].get_type() == arithmetic)
                expressionized[i].calc(assignments);
        }
    } 
}
//sets the chunk
void Expression::setNext(const string& s){
    //set chunk's original
    original = s.substr(0, s.length()-1);
    //tokenize chunk
    tokenize(s);
    //check chunk for syntax errors
    syntaxCheck();
    //if chunk is arithmetic then postfix/prefix/parenthesize chunk
    if(type == arithmetic){
        postfixToken();
        prefixToken();
        paren();
    }
    //reset evaluation for chunk
    eval = 0;
}

//FUNCTIONS USED TO SET PROPERTIES
//splits string by ';' and checks for missing ';'
bool Expression::splitSemi(const string& s){
    int m = 0;
    string build = "";
    bool flag = false;
    for(int i = 0; i < s.length(); i++){
        flag = false;
        if(s[i] == ';'){
            flag = true;
            build = s.substr(m,i-m+1);
            m=i+1;
            if(build != "" and build != " ") 
                next.push_back(build);
        }
    }
    if(!flag)
        cout<<"error: missing ';'"<<endl;
    return flag;
}
//tokenizes sent string
void Expression::tokenize(const string& s){
    string build="";
    int k=0;
    int j=0;
     for(int i = 0; i<s.length() && s[i] != ';'; i++){
            k++;
            if(s[i] == '(' || s[i] == ')' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i]==' '){
                build = s.substr(j, k-1);
                if(build != "" and build != " ") 
                    tokenized.push_back(Token(build));
                build = s.substr(i, 1);
                if(build != "" and build != " "){
                    tokenized.push_back(Token(build));
                }
                j=i+1;
                k=0;
            }
        }
        build = s.substr(j,k);
        if(build != " " and build!="")
            tokenized.push_back(Token(build));
}
//Sorts the tokens in postfix order for the expression its run on
void Expression::postfixToken(){
    stack<Token> ops;
    for(int i = 0; i < tokenized.size();i++){
        if(tokenized[i].get_type() == Token::ID || tokenized[i].get_type() == Token::INT)
            postfix.push_back(tokenized[i]);
        else if(tokenized[i].get_type() == Token::OpenBrace)
            ops.push(tokenized[i]);
        else if(tokenized[i].get_type() == Token::CloseBrace){
            while(ops.top().get_type() != Token::OpenBrace){
                postfix.push_back(ops.top());
                ops.pop();   
            }
            ops.pop();
        }
        else{
            while(!ops.empty() && ops.top().get_priority() >= tokenized[i].get_priority()){
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(tokenized[i]);
        }   
    }
    while(!ops.empty()){
        postfix.push_back(ops.top());
        ops.pop();
    }
}
//Sorts the tokens into a string in prefix order for the expression its run on
void Expression::prefixToken(){
    stack<string> s;
    for(int i = 0; i < postfix.size(); i++){
        if(postfix[i].get_type() == Token::OP){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = postfix[i].get_token() + " " + op2 +" " + op1;
            s.push(temp);
        }
        else{
            string temp = postfix[i].get_token();
            char tempt = temp[0];
            s.push(string(1, tempt));
        } 
    }
    prefix = s.top();
}
//checks expression for syntax errors
bool Expression::syntaxCheck(){ 
    enum States {expect_operand, expect_operator, done}; 
    bool eqtrue = false; // set to true if = is encountered 
    States state = expect_operand; // initial state value 
    int pcount = 0; // for checking braces
    valid = true; // a field in Expression class
    for(int i = 0; i<tokenized.size() && state != done; i++){
        Token t = tokenized[i];
        switch(state){
                case expect_operand:
                    if (t.get_type() == Token::OpenBrace)
                        pcount++;
                    else if(t.get_type() == Token::INT || t.get_type() == Token::ID)
                        state = expect_operator;
                    else{
                        valid = false;
                        state = done;
                    }
                    break;
                case expect_operator:
                    if(t.get_type() == Token::CloseBrace){
                        pcount--;
                        if(pcount<0){
                            valid = false;
                            state = done;
                        }
                    } 
                    else if(t.get_type() == Token::EQ){
                        eqtrue = true;
                        state = expect_operand;
                    }
                    else if(t.get_type() == Token::OP)
                        state = expect_operand;
                    else{
                        valid = false;
                        state = done;
                    }
                    break;
                default:
                    break;   
        }
    }
    if(pcount != 0)
        valid = false;
    if(state == expect_operand)
        valid = false;
    if(valid){
        if(eqtrue){
            if(tokenized.size()==3 && tokenized[0].get_type()==Token::ID && tokenized[2].get_type()==Token::INT)
                type = assignment;
            else
                valid = false;
        }
        else
            type = arithmetic;
    }
    if(!valid||tokenized.size()<2)
        type = illegal;
}
//fully parenthesizes expression
void Expression::paren(){
    stack<string> stack;
    for(int i = 0; i < postfix.size();i++) {
        bool flag = false;
        string testy = postfix[i].get_token();
        char test = testy[0];
        if(postfix[i].get_type() == Token::ID ||postfix[i].get_type() == Token::INT)
                stack.push(testy);
        else{
            string first = stack.top();
            stack.pop();
            string second = stack.top();
            stack.pop();
            string temp = "";
            switch(test){
                case '+': 
                    temp = "("+second+"+"+first+")";
                    stack.push(temp);
                    break;
                case '-':
                    temp = "("+second+"-"+first+")";
                    stack.push(temp);
                    break;
                case '*':
                    temp = "("+second+"*"+first+")";
                    stack.push(temp);
                    break;
                case '/':
                    temp = "("+second+"/"+first+")";
                    stack.push(temp);
                    break;      
            }
        }
    }
    parenthisized = stack.top();
}
//fully evaluates all arithmetic types and error checks for missing assignments
void Expression::calc(vector<Expression> assign){
    vector<string> postCheckCopy;
    stack<string> notfound;
    runnable = true;
    for(int i = 0; i < postfix.size();i++){
        if(postfix[i].get_type() == Token::ID){
            bool found = false;
            for(int k = 0; k < assign.size(); k++){
                string firsty;
                string inty;
                for(int j = 0; j <assign[k].original.size(); j++){
                    string st1(1,assign[k].original[j]);
                    char tes = st1[0];
                    if(isdigit(tes))
                        inty +=st1;
                    else if(isalpha(tes))
                        firsty =st1; 
                }
                if(firsty==postfix[i].get_token()){
                    postCheckCopy.push_back(inty);
                    found = true;
                }
            }
            if(!found)
                    postCheckCopy.push_back(postfix[i].get_token());
        }else
            postCheckCopy.push_back(postfix[i].get_token());
    }
    for(int i = 0; i < postCheckCopy.size();i++){
        string testy = postCheckCopy[i];
        char test = testy[0];
        if(isalpha(test)){
            runnable = false;
            notfound.push(testy);
        } 
    }
    stack<int> stack;
    for(int i = 0; i < postCheckCopy.size() && runnable;i++) {
        string testy = postCheckCopy[i];
        char test = testy[0];
        if(isdigit(test))
            stack.push(stoi(testy));
        else{
            int first = stack.top();
            stack.pop();
            int second = stack.top();
            stack.pop();
            switch(test){
                case '+': stack.push(second + first);break;
                case '-': stack.push(second - first);break;
                case '*': stack.push(second * first);break;
                case '/': stack.push(second / first);break;       
            }
        }
    }
    if(!runnable){
        cout<<"Cannot evaluate assignments need for variables ";
        while(!notfound.empty()){
            cout<<notfound.top()<<"; ";
            notfound.pop();
        }
        cout<<endl;
        
    }else
        eval = stack.top();
}

//DISPLAY FUNCTIONS:
//displays postfix for all chunks of expression
void Expression::display_postfix() const{
    for(int i = 0; i < expressionized.size(); i++){
        if(expressionized[i].get_type() == arithmetic){
            cout<<"postfix of "<< expressionized[i].original << " is: ";
            for(int k = 0; k<expressionized[i].postfix.size(); k++ )
                cout<<expressionized[i].postfix[k].get_token()<<" ";
            cout<<endl;
        }
        else if(expressionized[i].get_type() == assignment)
            cout<<"no prefix of "<<expressionized[i].original<<" which is not an arithmetic expression, but assignment."<<endl;
    }
}
//displays prefix for all chunks of expression
void Expression::display_prefix() const{
    for(int i = 0; i < expressionized.size(); i++){
        if(expressionized[i].get_type() == arithmetic)
            cout<<"prefix of "<< expressionized[i].original << " is: "<<expressionized[i].prefix<<endl;
        else if(expressionized[i].get_type() == assignment)
            cout<<"no prefix of "<<expressionized[i].original<<" which is not an arithmetic expression, but assignment."<<endl;
    }
}
void Expression::display_paren() const{
    for(int i = 0; i < expressionized.size(); i++){
        if(expressionized[i].get_type() == arithmetic)
            cout<<"fully parenthesizing "<<expressionized[i].original << " results: "<<expressionized[i].parenthisized<<endl;
        else if(expressionized[i].get_type() == assignment)
            cout<<"no fully parenthesizing of "<<expressionized[i].original<<" which is not an arithmetic expression, but assignment."<<endl;
    }
}
void Expression::display_eval() const{
    for(int i = 0; i < expressionized.size(); i++){
        if(expressionized[i].get_type() == assignment)
            cout<<"cannot evaluate "<<expressionized[i].original<<" which is not an arithmetic expression, but assignment."<<endl;
        else if(!expressionized[i].runnable)
            cout<<expressionized[i].original << " = ? - More Assignments Needed, Cannot Evaluate"<<endl;
        else if(expressionized[i].get_type() == arithmetic)
            cout<<expressionized[i].original << " = "<<expressionized[i].eval<<endl;
    }
}

//ACCESOR
Expression::Exp_type Expression::get_type() const{
    return type;
}
bool Expression::get_valid() const{
    return valid;
}

//DECONSTRUCTOR
Expression::~Expression(){
    original.clear();
    parenthisized.clear();
    prefix.clear();
    next.clear();
    tokenized.clear();
    postfix.clear();
    expressionized.clear();
    assignments.clear();
}