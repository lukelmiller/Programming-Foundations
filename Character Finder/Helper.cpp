//@author lukelmiller
/*
 * File:   main.cpp
 * Created on September 9, 2019, 9:22 PM
 */

#include <cstdlib>
#include "Helper.h"
//#include <iostream>

using namespace std;
Helper::Helper(){

}

Helper::~Helper(){

}


char *Helper::find_first_not_in_the_set(char *str, const char *set){
    char ret='\0';
    bool yikes = false;
    //cout<<"HERE2"<<endl;
    for(int i=0; *(str+i)!='\0'; i++){
        //cout<< "str["<<i<<"] = "<< str[i]<<endl;

        yikes = false;
        for(int k=0; *(set+k)!='\0';k++){
            //cout<< "set["<<k<<"] = "<< str[k]<<endl;
            if(str[i]==set[k]){
                //cout<< "found"<< endl;
                yikes = true;
                //ret=str[i];
                //return &ret;
            }


        }
        if(yikes == false){
            return &str[i];
        }


    }


    return '\0';
}

char *Helper::find_first_in_the_set(char *str, const char *set){
    char ret='\0';
    //cout<<"HERE1";
    for(int i=0;*(str+i)!='\0'; i++){
        //cout<< "str["<<i<<"] = "<< str[i]<< endl;
//        if(str[i]==*set){
//            ret=str[i];
//            return &ret;
//        }
        for(int k=0; *(set+k)!='\0';k++){
            if(str[i]==set[k]){
                //ret=str[i];
                return &str[i];
            }
        }
//        if(str[i]=='\0'){
//            return '\0';
//        }
    }


    return '\0';

}
