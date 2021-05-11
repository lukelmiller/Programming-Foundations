//@author lukelmiller
/*
 * File:  mystrtok.cpp
 * Created on September 11, 2019, 8:43 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

size_t mystrlen(const char *s){
    size_t ret = 0;
    for(int i=0;s[i]!='\0';i++){
        ret++;

    }

    return ret;
}

char *find_first_not_in_the_set(char *str, const char *set){
    char ret='\0';
    bool yikes = false;
    for(int i=0; *(str+i)!='\0'; i++){
        yikes = false;
        for(int k=0; *(set+k)!='\0';k++){
            if(str[i]==set[k]){
                yikes = true;
            }
        }
        if(yikes == false){
            return &str[i];
        }
    }

    return '\0';
}

char *find_first_in_the_set(char *str, const char *set){
    char* ret='\0';

    for(int i=0;*(str+i)!='\0'; i++){

        for(int k=0; *(set+k)!='\0';k++){
            if(str[i]==set[k]){
                return &str[i];
            }
        }

    }


    return ret;

}
char *mystrtok(char *str, const char *delim){

    static char * remember=str;
    //cout<<"MADE it!"<<endl;
    static bool look;


    if (str=='\0'){
        //cout<<"remember1: '"<<remember<<"'"<<endl;
        char * var1 = find_first_not_in_the_set(remember, delim);
//        if(var=='\0'){
//            return '\0';
//        }

        //cout<<"here1"<<endl;
        //cout<<"var12 "<< var1<<endl;
        size_t var1len = mystrlen(var1);

        if(look==true){
            //cout<< "did we get here?"<<endl;
            return '\0';
        }

        char * var2 = find_first_in_the_set(var1,delim);

        if(var2=='\0'){
            //cout<<"LOOKE WHO MADE IT"<<endl;
            look = true;
            return '\0';
        }


        //cout<<"var22 "<< var2<<endl;
        //cout<<"here2"<<endl;
        size_t var2len = mystrlen(var2);

        //cout<<"var12 "<< var1<<endl;

        //cout<<"var22 "<< var2<<endl;

        //cout<<"var1len "<< var1len<<endl;

        //cout<<"var2len "<< var2len<<endl;
        //cout<<"str "<<str[23]<<endl;

        remember[var1len-var2len]='\0';
        remember = var2+1;
        //cout<<"here3"<<endl;
        return remember;







//   }else if(remember=='\0'){
//       cout<<"remember3: '"<<remember<<"'"<<endl;
//       cout<<"trying to get here!"<<endl;
//       return '\0';
   }else{

//        cout<<"str[var1len-var2len] "<< str[var1len-var2len]<<endl;
//
//        str[var1len-var2len]='\0';

        //cout<<"remember2: '"<<remember<<"'"<<endl;
           char * var1 = find_first_not_in_the_set(str, delim);
        size_t var1len = mystrlen(var1);
        //cout<<"var1 "<< var1<<endl;


        char * var2 = find_first_in_the_set(var1,delim);
        size_t var2len = mystrlen(var2);
         //cout<<"var22 "<< var2<<endl;

        //cout<<"var1len "<< var1len<<endl;

        //cout<<"var2len "<< var2len<<endl;
        //cout<<"var2 "<< var2<<endl;
        //cout<<"str "<<str[23]<<endl;
        str[var1len-var2len]='\0';
        remember = var2+1;
        //cout<<"remember: "<<remember<<endl;

        return str;

    }








    return str;

}
