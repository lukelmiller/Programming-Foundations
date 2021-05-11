/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
    cout << "----------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }
    
    // Set the properties of the last Node (including setting 'next' to NULL)
    //cout<<"HERE"<<endl;
    current->elem = size;
    current->next = NULL;
    
    show(head);

    // TODO: Your Code Here
    head = head->next;
    
    show(head);
    
    Node* second_last = head; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next;
    
    delete(second_last->next);
    
    second_last->next = NULL;
    
    show(head);
    
    for(int i = 0; i<10; i++){

        Node* new_node = new Node();
        new_node->elem = i;
        new_node->next = head;
        head = new_node;  
    
   
    }
    
     show(head);
    
     
      
    second_last = head; 
    while (second_last->elem != 7) 
        second_last = second_last->next;
    
    Node* search = head; 
    while (search->elem != 7) 
        search = search->next;
    search = search->next;
     
    
    cout<< second_last->elem<<endl;
     
    for(int i = 0; i<10; i++){

                Node* new_node = new Node();
                new_node->elem = i;
                second_last->next = new_node;
                second_last = new_node; 
                new_node->next = search;
                
    
   
    }      
     

    

        
     show(head);
     
     
     
    
    // Clean up
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}