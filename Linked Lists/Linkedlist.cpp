#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "Linkedlist.h"

using namespace std;


Linkedlist::Linkedlist(){
    head=NULL;
    tail=NULL;
} //default constructor for empty list

Linkedlist::~Linkedlist(){
    clear();
} //destructor to free nodes dynamically created to support the linklist 

bool Linkedlist::empty() const{
    if(head==NULL)
        return true;
    return false;
    
}

void Linkedlist::clear(){
    
    Node* current = head;  
    Node* temp;  
  
    while (current != NULL)  
    {  
        temp = current->next;  
        delete(current);  
        current = temp;  
    }  
    delete(temp);
    head = NULL;  
}

reference Linkedlist::back(){
    return tail->elem;
}

const_reference Linkedlist::back() const{
    return tail->elem;
}

reference Linkedlist::front(){
    return head->elem;
}

const_reference Linkedlist::front() const{
    return head->elem;
}

Linkedlist& Linkedlist::operator=(const Linkedlist& l){
    
    
    if (&l == this)
        return (*this);
    
    if(l.head == NULL){
        clear();
        return *this;
    } 
    Node *temp = head;
    Node *orig = l.head;
    
    while(orig->next){
        temp->elem = orig->elem;
        orig = orig->next;
        temp = temp->next;
        
    }
    
    tail = temp;
    
    return (*this);

    
}

void Linkedlist::pop_back ( ){
    Node *current=new Node;
    current=tail;
    current->next = NULL;
    tail=current->prev;
    tail->next = NULL;
    current=NULL;
    delete current;
}

void Linkedlist::pop_front ( ){
    Node *temp = new Node;
    temp=head;
    head=head->next;
    head->prev = NULL;
    delete temp;
}

void Linkedlist::push_back ( const element_type& x ){
    Node* temp = new Node;
    temp->elem = x;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    tail->next = NULL;
}

void Linkedlist::push_front ( const element_type& x ){
    Node *temp=new Node;
    temp->elem = x;
    temp->next = head;
    head->prev= temp;
    head = temp;
    head->prev = NULL;
    
} 

void Linkedlist::sort ( ){
    bool changed = true;
    int i; 
    
    Node *checker = new Node(); 
    Node *track = NULL; 
   
    
    if (head == NULL) 
        return; 
   
    while (changed)
    { 
        changed = false; 
        checker = head; 
   
        while (checker->next != track) 
        { 
            if (checker->elem > checker->next->elem) 
            { 
                int temp = checker->elem;
                checker->elem = checker->next->elem;
                checker->next->elem = temp;
                changed = true; 
            } 
            checker = checker->next; 
        } 
        track = checker; 
    } 
    
}

// constructor that initializes the linked list with n nodes, // with elem value from 0 to n-1
Linkedlist::Linkedlist(unsigned int n){
    // Create the first node
    Node* start = new Node();
    start->elem = 0;
    start->prev = NULL;
    start->next = NULL;
    Node* end = start;
    for(int i =1; i < n; i++){
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = end;
        node->next = NULL;

       
        // Fold it into the list
        end->next = node;
        
        // Move the tail
        end = node;
        
    }
    head = start;
    tail = end;
}

// print the linked list in the forward direction,
// similar to the show function of lab6
void Linkedlist::check() const{
    Node* current = head;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// print the linked list in the backward direction, // similar to the reverse_show function of lab7 
void Linkedlist::rcheck() const{
    Node* current = tail;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// insert a node with value specified by x after the node // specified by pos. The first node has position 0.
// if the number of nodes in the linked list is less than // pos, the node is inserted at the end.
void Linkedlist::insert(unsigned int pos, const element_type& x){
    if (head==NULL)
        return;
    if(pos  == 0){
        push_front(x);
        return;
    }
    
    
    Node *insert = new Node();
    
    insert->elem = x;
     
    
    Node *current=new Node;
    Node *currentA=new Node;
    
    current=head;
    currentA = head;
    
    for(int i=0; i<pos-1;i++){
         
        if(current->next==NULL){
            cout<<"HERE3"<<endl;
            push_back(x);
            return;
                    
        }
        current=current->next;
        currentA=currentA->next;
        
        if(currentA->next==NULL){
            push_back(x);
            return;
        }
    }  

    currentA = currentA->next;
    
    current->next = insert;
    insert->prev = current;
    insert->next = currentA;
    currentA->prev = insert;

    
}



// remove the node specified by pos.
// if the number of nodes in the linked list is less than // pos, the node at the end if any is removed.
void Linkedlist::erase(unsigned int pos){   
    if (head==NULL)
        return;
    if(pos  == 0){
        pop_front();
        return;
    }
                
    
    Node *current=new Node;
    current=head;
    for(int i=0; i<pos;i++){
        
        if(current->next==NULL){
            pop_back();
            return;
                    
        }
        current=current->next;
    }   
    
    current->prev->next=current->next;
    current->next->prev = current->prev;
    delete(current);
}