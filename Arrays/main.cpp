/*
 * File:   main.cpp
 * Author: wingning
 *
 * Created on August 30, 2010, 2:33 PM
 * Based on some of the work of Baha
 * Modified on January 18, 2016
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

// Initializes the given array with the simple example.
void populateTest(int * &array)
{
    array = new int[10];
    array[0] = 31;
    array[1] = -41;
    array[2] = 59;
    array[3] = 26;
    array[4] = -53;
    array[5] = 58;
    array[6] = 97;
    array[7] = -93;
    array[8] = -23;
    array[9] = 87;
}

// Initializes the array with arbitrary values.
void populate(int * &array, int size)
{
    srand(0);
    array = new int[size];
    
    for(int i = 0; i < size ; i++)
    {
        //Generate values between -10 * size and 10 * size
        array[i] = rand() % (size * 20 + 1) - size * 10;
    }
}

// Prints the contents of the given array
void print(int * array, int size)
{
    for (int i = 0; i < size; i++)
        cout <<"Array[" << i << "] = " <<  array[i] << endl;
}

int subseqSum(int * seqArray, int i, int j)
{
    //int max = 0;
    int sum = seqArray[j];
    for (int k = i; k<j; k++){
        //for(int k = i; k==j; k++){
            sum += seqArray[k];
//            if(sum > max){
//                max = sum;
//            }
        //}
        //sum = 0;
        
    }
    //cout <<sum;
    return sum;
}

int subseqSum(int prefixToaj, int aj)
{
    return (prefixToaj+aj);
}

int algo1MSS(int * seqArray, int size)
{
    int max = 0;
    int sum = 0;
    
    
    
    for(int i = 0; i<size; i++){
        for(int k = i; k<size; k++){
            sum = subseqSum(seqArray, i, k);
            if(sum>max){
                max = sum;
            }
            //sum = 0;
            
        }
            
        
        
       
    }
    
    
    
    
    //cout << max<<endl;
    //cout << sum << endl;
    return max;
}

int algo2MSS(int * seqArray, int size)
{
    int max = 0;
    int pre = 0;
    
    for(int i = 0; i < size; i++){
        pre = 0;
        for(int k = i; k < size; k++){
            pre = subseqSum(pre, seqArray[k]);
            if(pre>max){
                max = pre;
            }
        }
        
    }
    //cout<< max<<endl;
    return max;
}

/*
 * Main program for testing the functions implemented.
 * You should not need to change any of the code in this
 * function.
 */
int main(int argc, char** argv) 
{
    // Space will be allocated by populateTest, and popolate
    int * array; 
    int size, result;
    clock_t start, end; // For timing of the code

    // Create the example sequence
    size = 10;
    populateTest(array);
    
    // Print the content of the array that was just filled
    print(array, size);
    cout << endl;
    
    //=== first algorithm and related functions testing
    // Testing subseqSum function
    if (subseqSum(array, 0, 2) == 49)
        cout << "Passed test 1" << endl;
    else
        cout << "Failed test 1" << endl;

    // Testing algo1MSS function
    if (algo1MSS(array, size) == 187)
        cout << "Passed test 2" << endl;
    else
        cout << "Failed test 2" << endl;

    //=== second algorithm and related functions testing
    // Testing the other version of subseqSum
    if (subseqSum(-10, array[2]) == 49)
        cout << "Passed test 3" << endl;
    else
        cout << "Failed test 3" << endl;

    // Testing algo2MSS function
     if (algo2MSS(array, size) == 187)
        cout << "Passed test 4" << endl;
    else
        cout << "Failed test 4" << endl;

    cout << endl;
    
    // This part would be done with a loop and would get the size 
    // of the array interactively in the real world
    size = 1000;
    populate(array, size);
    
    // Execute and time algorithm 1
    start  = clock();
    result = algo1MSS(array, size);
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 1 to obtain the result." << endl;

    // Execute and time algorithm 2
    start  = clock();
    result = algo2MSS(array, size);
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 2 to obtain the result." << endl;

    return 0;
}