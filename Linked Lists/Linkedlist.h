/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linkedlist.h
 * Author: lukemiller
 *
 * Created on October 30, 2019, 12:58 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

typedef int element_type;

typedef element_type& reference;

typedef const element_type& const_reference; 
    
    
class Linkedlist{
    
public:


    
    Linkedlist(); //default constructor for empty list

    ~Linkedlist(); //destructor to free nodes dynamically created to support the linklist
    
    bool empty() const;

    void clear();

    reference back();

    const_reference back() const;

    reference front();

    const_reference front() const;

    Linkedlist& operator=(const Linkedlist& l); 
    
    void pop_back ( );

    void pop_front ( );

    void push_back ( const element_type& x ); 
    
    void push_front ( const element_type& x ); 
    
    void sort ( );

    // constructor that initializes the linked list with n nodes, // with elem value from 0 to n-1
    explicit Linkedlist(unsigned int n);

    // print the linked list in the forward direction,
    // similar to the show function of lab6
    void check() const;
    
    // print the linked list in the backward direction, // similar to the reverse_show function of lab7 
    void rcheck() const;
    
    // insert a node with value specified by x after the node // specified by pos. The first node has position 0.
    // if the number of nodes in the linked list is less than // pos, the node is inserted at the end.
    void insert(unsigned int pos, const element_type& x); // remove the node specified by pos.
    
    // if the number of nodes in the linked list is less than // pos, the node at the end if any is removed.
    void erase(unsigned int pos);

private:
    
    struct Node{ 
    element_type elem; 
        struct Node* next; 
        struct Node* prev; 
    };
    
    Node *head, *tail;
    




};


#endif /* LINKEDLIST_H */

