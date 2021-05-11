/* 
 * File:   Queue.h
 * Author: Jon C. Hammer
 *
 * Created on April 1, 2016, 11:22 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <iostream>
using namespace std;

// Basic Node structure
struct Node
{
    int elem;    // Data
    Node * next; // Pointer to the next node in the chain
};

class Queue
{
public:
    // Constructors
    Queue();
    ~Queue();
    
    // Capacity
    bool empty() const; 
    unsigned int size() const; 
    
    // Element access
    int& front(); 
    const int& front() const; 
    int& back(); 
    const int& back() const; 
    
    // Modification
    void push(const int& x);
    void pop();

    void print();
    
private:
    Node* head;               // The front of the queue
    Node* tail;               // The end of the queue
    unsigned int numElements; // The number of elements in the queue
};

#endif /* QUEUE_H */
