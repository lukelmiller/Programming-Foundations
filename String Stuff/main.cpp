//@author lukelmiller
/*
 * File:   main.cpp
 * Created on September 11, 2019, 8:43 AM
 */



#include <cstdlib>
#include <cstring>
#include <iostream>
#include "mystrtok.h"
using namespace std;


int main(int argc, char** argv) {

    char line[] = "-- // --- -";

    char add[] = "is jank";

    size_t len;

    len = strlen(line);

    cout<<"The length of 'line' is "<< len << endl;

    char* strArray[40];
    for(int i=0; i<40; i++){
        strArray[i]='\0';
    }

    int pieces = 0;

    char* ptr = mystrtok(line, " -/");
    //cout<<"ptr "<< ptr<<endl;

    while(ptr != '\0'){
        strArray[pieces] = ptr;
        ptr= mystrtok('\0', " -/");
        //cout<<"ptr "<< ptr<<endl;
        pieces++;
    }
    cout<<pieces<<endl;

    for(int i = 0; i < pieces; i++){
        cout<<strArray[i]<<endl;
    }

    size_t size = 0;

    for(int i = 0; i < pieces; i++){
        size = i;
    }

    size_t numBanks = pieces-1;

    cout<<"The number of blanks is ..."<<numBanks<<endl;

    char* result = new char[size + 1];
    result[0] = '\0';



    for(int i = 0; i < pieces; i++){

        strcat(result,strArray[i]);

    }



    cout<<"The concatenation of all strings in strArray is: ..."<< result<< endl;



    delete[] result;



    return 0;

}
