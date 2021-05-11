/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Stack.h"
// Constructors
Stack::Stack(){
    buffer = new int[100];
    numElements = 0; // The number of elements currently on the stack
    topIndex = -1; 
}
Stack::~Stack(){
    delete buffer;
    
}

// Capacity
bool Stack::empty() const{
    if(numElements<1){
        return true;
    }
    return false;
}
unsigned int Stack::size() const{
    return numElements;
}

// Element access
int& Stack::top(){
    return buffer[topIndex];
}
const int& Stack::top() const{
    return buffer[topIndex];
}

// Modification
void Stack::push(const int& x){
   topIndex++; 
    buffer[topIndex] = x;
    numElements++;
    
} 
void Stack::pop(){
    buffer[topIndex] = NULL;
    numElements--;
    topIndex--;
}

void Stack::print(){
    cout << "[ ";
    for (int i = 0; i < numElements; ++i)
    {
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}
