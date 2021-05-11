/* 
 * File:   main.cpp
 * Author: lukemiller
 *
 * Created on November 12, 2019, 9:37 PM
 */

#include <cstdlib>
#include <ctime> 
#include <iostream>
using namespace std;


// Given an sorted array of integers a[left] to a[right] 
// and value x to be searched 
// return -1 if x is not in the list or 
// return an index i where a[i] == x 
// using binary search algorithm 
int binarySearch(int* a, int left, int right, int x){
        if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        if (a[mid] == x) 
            return mid; 

        if (a[mid] > x) 
            return binarySearch(a, left, mid - 1, x); 
  

        return binarySearch(a, mid + 1, right, x); 
    } 
 
    return -1; 
}

// Given an array of integers a[left] to a[right] as the sequence 
// return the maximum subsequence sum 
// using the recursive approach 
int mss(int* a, int left, int right){
    
//    for(int i = left; left < right)
//  
//    return max;
 
}


// Given an sorted array of integers a[left] to a[right] 
// and value x to be searched 
// return -1 if x is not in the list or 
// return an index i where a[i] == x 
// using linear search algorithm 
int linearSearch(int* a, int left, int right, int x){
    
    for(int i = left; i<right && (a+i)!=NULL; i++){
        if(a[i]==x)
            return i;
    }
    return -1;
    
}


int main(int argc, char** argv) {
// Create an array of N integers for the maximum subsequence sum problem.
    const int N = 100000;
    
    int array[N];
 
     srand((unsigned)time(0)); 
     
    for(int i=0; i<N; i++){ 
        array[i] = (rand()%100)+1; 

    } 
    
// Initialize the array with random values.
// Start timing
// Loop >= 1000 times
     for(int i = 0; i<1000; i++){
         
     }
//    Call either the iterative or the recursive variant of the MSS function
// End timing.
// Print results.
    
    
    
// Create an array of N integers for the search problem.
//    array[N];
//    for(int i=0; i<N; i++){ 
//        array[i] = i; 
//         
//        cout << array[i] << endl;
//    } 
//// Initialize the array such that the values are sorted.
//// Start timing
//// Loop >= 1000 times
//    for(int i = 0; i<1000; i++){
//        cout<<linearSearch(array, 3, 1000, 100)<<endl;
//    }
////     Call binarySearch() or linearSearch() with an element that is either in the array or is not in the array.
// End timing.
// Print results.
    return 0;
}

