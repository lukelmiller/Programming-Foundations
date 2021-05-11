/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lukemiller
 *
 * Created on October 30, 2019, 1:21 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int factorial(int n){
    int fact;
    if(n == 1)
        return 1;
    if(n>1)
        return factorial(n-1)*n;
    
}
int fibonacci(int n){
    int fib;
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if(n>1)
        fib = fibonacci(n-1) + fibonacci(n-2);
    
    
    return fib;
    
}
void sort (int * seq, int size){
    int min = seq[0];
    int tmp;
    if(size == 1)
        return;
    for(int i = 0; i<size; i++){
        
        if (seq[0]>seq[i]){
            tmp = seq[0];
            seq[0]=seq[i];
            seq[i]= tmp;
            
        }
        
    }
    
    sort(seq+1,size-1);  
    
}
void display(int * seq, int size){
    
    for(int i= 0; i < size; i++){
        cout<<seq[i];
        if(i+1<size)
            cout<<",";
    }
    
    
    
}




int main(int argc, char** argv) {
    
    int arr[6] = {5,-3,4,3,2,1}; 
    int * ptr = arr;
 
    cout<<"factorial(5) = "<< factorial(5) << endl;
    
    cout<<"fibonacci(9) = " << fibonacci(9) << endl;
    
    sort(ptr,5);
    
    
    cout<<"sort(seq, size) = "; 
    display(ptr,5);
    cout<<endl;
    
    return 0;
}

