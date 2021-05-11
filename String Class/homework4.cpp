/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homework4.cpp
 * Author: lukemiller
 *
 * Created on October 24, 2019, 6:44 PM
 */

#include "Mystring.h"

#define string Mystring

using namespace std;

/*
 * Check function from the previous lab
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
    
}   

int main() 

{

    cout<< "This is Lab 6"<<endl;
    string s1 = "Hello, World!";

    string s1name = "s1";
    
    check(s1, "s1");

    check(s1name, "s1name");

    
    cout << "---Testing assignment operator---\n\n";

    string s2;
    s2=s1;
    string s2name("s2");
    check(s2,s2name);

    check(s1,s1name);
    
    
    

    
    char test_set[20];
    strcpy(test_set, "uq");
    
//test +=
    s1+=s1name;
    cout<<s1<<endl;
    s1+="+=";
    cout<<s1<<endl;
//test +
    s1=s1+s1name;
    cout<<s1<<endl;
//test push_back()
    s1.push_back('u');
//test find_first_of() and find_last_not()
    int i = s1.find_first_of(test_set,0,3);
    int k = s1.find_last_not_of(test_set, 4);   
    cout<<s1<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"k: "<<k<<endl;
//test append()
    s1.append(s1name);
    cout<<s1<<endl;
    
//test clear()
    s1name.clear();
    cout<<"clear: "<<s1name<<endl;
//test =
    s1 = "hello";
    s1name = s1;
    cout<<s1name<<endl;
//test insert()
    s1.insert(0,s1name);
    cout<<s1<<endl;
    string rep = "this";
    cout<<rep<<endl;
//test replace()
    string rep2 = "1234";
    rep.replace(0,5,rep2);
    cout<<rep<<endl;
    rep.replace(1,2,"432");
    cout<<rep<<endl;
//test empty()
    if(!rep.empty()){
        cout<<"rep is not empty"<<endl;
        
    }
//test !=
    if(rep != rep2){
        cout<<"rep != rep2"<<endl;
    }
    if("1434" != rep2){
        cout<<"1434 != rep2"<<endl;
    }
    if(rep != "1434"){
        cout<<"rep != 1434"<<endl;
    }
//test ==
    rep = rep2;
    if(rep == rep2){
        cout<<"rep == rep2"<<endl;
    }
    if("1434" == rep2){
        cout<<"1434 == rep2"<<endl;
    }
    if(rep == "1434"){
        cout<<"rep == 1434"<<endl;
    }
    
    
    
  
    

    cout<<"Lab 6 ends";

    

    

    return 0;

}