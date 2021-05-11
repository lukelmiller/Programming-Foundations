/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lukemiller
 *
 * Created on October 30, 2019, 12:58 PM
 */

#include <cstdlib>
#include "Linkedlist.h"

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    //This tests the constructor with an unsigned int passed to it
    Linkedlist *listy= new Linkedlist(50);
    
    
    //This tests the empty() function
    if(listy->empty()){
        cout<< "EMPTY"<<endl;
    };
    
    //THis tests the check() and rcheck() functions
    listy->check();
    listy->rcheck();
    
    //This tests the front() and back() getters
    int front = listy->front();
    cout<<"Front of listy: "<<front<<endl;
    
    int back = listy->back();
    cout<<"Back of listy: "<<back<<endl;
    
    
    //This test the pop() functions
    listy->pop_front();
    listy->pop_back();
    listy->pop_front();
    
    
    front = listy->front();
    cout<<"Front of listy: "<<front<<endl;
    
    back = listy->back();
    cout<<"Back of listy: "<<back<<endl;
       
    //This tests the push() functions
    listy->push_back(-24);
    listy->push_front(99);
    
    
    
    listy->check();
    //listy->rcheck();
    
    
    //This tests the sort() function
    cout<<endl<< "SORT NOW RUNNING"<<endl<<endl;
    listy->sort();
    listy->check();
    listy->rcheck();
    
    //this tests the erase() functions
    cout<<"DELETING POS 5"<<endl;
    listy->erase(5);
    listy->check();
    //listy->rcheck();
    
    //this test the insert() function
    listy->insert(4,69);
    listy->check();
    
    
    
    
    Linkedlist *listy2= new Linkedlist(70);
    
    //this test the = operator overload
    cout<<"listy2 = listy;"<<endl;
    listy2 = listy;
    listy2->check();
    //listy2->rcheck();
    
     cout<<" listy = listy2;"<<endl;
    listy = listy2;
    listy2= new Linkedlist(70);
     listy = listy2;
    listy->sort();
    listy->check();
    //listy->rcheck();
    
    //this tests the clear() function
    listy->clear();
    if(listy->empty())
        cout<< "EMPTY"<<endl;
    
    
    
    return 0;
}

