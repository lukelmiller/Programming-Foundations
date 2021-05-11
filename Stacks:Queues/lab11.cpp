/* 
 * File:   main.cpp
 * Author: Jon C. Hammer
 *
 * Created on April 1, 2016, 11:22 AM
 */

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    
    // Create an empty stack
    Stack stack;
    
   
    // Add some elements to the stack
    for (int i = 0; i < 10; ++i)
        stack.push(i);
    
    // Pop each element off of the stack
    while (!stack.empty())
    {
        
        cout << "Stack contains: ";
        
        stack.print();
        
        cout << "Stack Size: " << stack.size() << endl;
        
        cout << "Top: " << stack.top() << endl << endl;
        stack.pop(); 
        
    }
    
    //--------------------------------------------------//
  
    // Create an empty queue
    Queue queue;

    // Add some elements to the queue
    for (int i = 0; i < 10; ++i)
        queue.push(i);
    

    // Pop each element off of the stack
    while (!queue.empty())
    {

        cout << "Queue contains: ";
        queue.print();
        cout << "Queue Size: " << queue.size() << endl;
        
        cout << "Front: " << queue.front() << endl << endl;
        queue.pop();
    }

    return 0;
}
