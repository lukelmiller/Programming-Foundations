/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Queue.h"


// Constructors
Queue::Queue(){
    head = NULL;
    tail = NULL;
    numElements = 0;
}
Queue::~Queue(){
    delete head;
}

// Capacity
bool Queue::empty() const{
    if(!head)
        return true;
    return false;
                
}
unsigned int Queue::size() const{
    return numElements;
}

// Element access
int& Queue::front(){
    return head->elem;
}
const int& Queue::front() const{
    return head->elem;
}
int& Queue::back(){
    return tail->elem;
}
const int& Queue::back() const{
    return tail->elem;
}

// Modification
void Queue::push(const int& x){
    numElements++;
    
    Node *linky = new Node;
    linky->elem = x;
    Node *current =head;
    
    if(head == NULL) {
        head = linky;
        return;
    
    }
    
     while(current && current->next) {
        current = current->next;
    }
    
    current->next = linky;
    tail = linky;
    


}
void Queue::pop(){
    head = head->next;
    numElements--;
}

void Queue::print(){
    cout << "[ ";
    for (Node* cur = head; cur != NULL; cur = cur->next)
    {
        cout << cur->elem << " ";
    }
    cout << "]" << endl;
}
    

//    Node* head;               // The front of the queue
//    Node* tail;               // The end of the queue
//    unsigned int numElements; // The number of elements in the queue