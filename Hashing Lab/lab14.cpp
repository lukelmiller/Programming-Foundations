/* 
 * File:   main.cpp
 * Author: lukemiller
 *
 * Created on December 12, 2019, 7:11 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
int convert(char str){
    int val;
    if (str >= 48 && str <= 57) 
        val = str - 48;
    else if(str>=65 && str<=90)
        val = str - 55;
    else if(str>=97 && str<=122)
        val = str - 61;
    else if(str==45)
        val = 62;
    else if(str==95)
        val = 63;
    else
        return 0;
    return val;
}

size_t dmHash(string key, size_t tableSize){
    int N = tableSize;
    int a5 = convert(key[0]);
    for(int i = 0; i<key.size()-1; i++){
        int a4 = convert(key[i+1]);
        a5 = (a5)*64%N+a4;
    }
    return a5;
}
size_t mmHash(string key, size_t tableSize){
    
    int n = 0;
    
    int track = key.size();
    for(int i = 0; i<key.size(); i++){
        track--;
        int temp = convert(key[i]); 
        n += temp*pow(64,track);
    }

    double d = n*0.61803398875;

    double f = d-floor(d);
    
    int index = f * tableSize;

    return index;
     
}


string convertStr(string str){
    string fin="";
    
    for(int i = 0; i<str.size(); i++){
        string temp = to_string(convert(str[i]));
        
        fin.append(temp) ;
    }
    
    
    return fin;
    
}
void printCharChart(){
    string stringy = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    for(int i = 0; i<stringy.size(); i++){
        cout<<stringy[i]<<": ";
        int c = stringy[i];
        cout<<c<<endl;
    }
}
string randomKey(unsigned int min, unsigned int max){
    const int SIZE = 64;
    const char alphabet[SIZE]={'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','-','_'};

    // simple error handling
    if (min == 0)
        min = 1;
    if (max < min)
        max = min;

    // pick a length between min and max
    int lenRange = max - min + 1;    
    int len      = rand() % lenRange;
    len          = len + min;

    // len is one of min, min+1,...max
    string s;
    for (int i = 0; i < len; i++)
        s.push_back(alphabet[rand() % SIZE]);
    
    return s;
}

int main() {
    int hash[103981];
    string strings[75000];
    for(int i = 0; i<103981;i++)
        hash[i]=0;
    cout<<"out of for1"<<endl;
    for(int i = 0; i<75000; i++){

        strings[i] = randomKey(12,12);
        
        hash[dmHash(strings[i],103981)]++;;
        
    }
    cout<<"out of for2"<<endl;
    int max = 0;
    int col = 0;
    for(int i = 0; i<103981;i++){
        if(hash[i]>1){
            col++;
            if(hash[i]>max)
                max = hash[i];
        }
    
    }
    cout<<"COL: "<<col<<endl;
    cout<<"MAX: "<<max<<endl;
    return 0;
}

