/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */
#include <iostream>
#include <cstring>
#include <math.h>
#include "Mystring.h"

// default constructor
Mystring::Mystring(){
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s){
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor implemented
Mystring::Mystring(const Mystring& orig){
    ptr_buffer=new char[orig.buf_size];
    memcpy(ptr_buffer,orig.ptr_buffer,orig.buf_size);
    buf_size=orig.buf_size;
    len=orig.len;
}

Mystring::~Mystring(){
    delete [] ptr_buffer;
}

void Mystring::reserve(size_type n){
    int size=(n>buf_size?n:buf_size);
    char* tmp=new char[size];
    memcpy(tmp,ptr_buffer,buf_size);
    delete[] ptr_buffer;
    ptr_buffer=tmp;
    buf_size=size;

}

// some simple methods implemented for you
 Mystring::size_type Mystring::size() const {
     return len;
 }
 
 Mystring::size_type Mystring::length() const{
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const{
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const{
       return (int)pow(2,30) -4 ;
 }
 
 bool Mystring::empty() const{
     if(len == 0)
         return true;
     return false;
 }
 
 // one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig){
    if(ptr_buffer!=orig.ptr_buffer){
        delete[] ptr_buffer;
        ptr_buffer=new char[orig.buf_size];
        //memcpy(ptr_buffer,orig.ptr_buffer,orig.buf_size);
        strcpy(ptr_buffer, orig.ptr_buffer);
        buf_size=orig.buf_size;
        len=orig.len;
    }
        
    
    
    return *this;
}

Mystring& Mystring::operator=(const char * orig){

        delete[] ptr_buffer;
        unsigned s=strlen(orig);
        ptr_buffer=new char[s+33];
        memcpy(ptr_buffer,orig,s+1);
        buf_size=s+32;
        len=s;
    
    return *this;
    
    
}
 
char Mystring::operator[](size_type pos) const{
    
    return *(ptr_buffer+pos);
}

char& Mystring::operator[](size_type pos){
    return *(ptr_buffer+pos);
} 
 
Mystring& Mystring::operator+=(const Mystring& str){
    if(len+str.len<buf_size){
            memcpy(ptr_buffer+len,str.ptr_buffer,str.len);
            len+=str.len;
    }
    else{
            char* tmp=new char[(buf_size+str.len)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memcpy(ptr_buffer+len,str.ptr_buffer,str.len);
            buf_size+=str.len<<1;
            len+=str.len;
    }
    
    
    return *this;
}

Mystring& Mystring::operator+=(const char * str){
    unsigned s = strlen(str);
    if(len+s<buf_size){
            memcpy(ptr_buffer+len,str,s);
            len+=s;}
    else{
            char* tmp=new char[(buf_size+s)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memcpy(ptr_buffer+len,str,s);
            buf_size+=s<<1;
            len+=s;}
    return *this;
}
 
void Mystring::clear(){
    delete[] ptr_buffer;
    ptr_buffer=new char[1];
    ptr_buffer[0]='\0';
    buf_size=1;
    len=0;
}

void Mystring::push_back(char c){
    len+=1;
    buf_size   = len + 1;
    ptr_buffer[len-1]=c;
    
    
}

Mystring& Mystring::append(const Mystring& str){
    if(len+str.len<buf_size){
            memcpy(ptr_buffer+len,str.ptr_buffer,str.len);
            len+=str.len;
    }
    else{
            char* tmp=new char[(buf_size+str.len)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memcpy(ptr_buffer+len,str.ptr_buffer,str.len);
            buf_size+=str.len<<1;
            len+=str.len;
    }
    
    
    return *this;
    
    
}

Mystring& Mystring::append(const char * str){
    unsigned s = strlen(str);
    if(len+s<buf_size){
            memcpy(ptr_buffer+len,str,s);
            len+=s;}
    else{
            char* tmp=new char[(buf_size+s)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memcpy(ptr_buffer+len,str,s);
            buf_size+=s<<1;
            len+=s;}
    return *this;
}

Mystring& Mystring::insert(size_type pos, const Mystring& str){
    if(len+pos+str.len<buf_size){
            memmove(ptr_buffer+pos+str.len,ptr_buffer+pos,len-pos);
            memcpy(ptr_buffer+pos,str.ptr_buffer,str.len);
            len+=str.len;}
    else{
            char* tmp=new char[(buf_size+str.len)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memmove(ptr_buffer+pos+str.len,ptr_buffer+pos,len-pos);
            memcpy(ptr_buffer+pos,str.ptr_buffer,str.len);
            buf_size+=str.len<<1;
            len+=str.len;}
    return *this;
}

Mystring& Mystring::insert(size_type pos, const char * str){
    unsigned s=strlen(str);
    if(len+s<buf_size){
            memmove(ptr_buffer+pos+s,ptr_buffer+pos,len-pos);
            memcpy(ptr_buffer+pos,str,s);
            len+=s;}
    else{
            char* tmp=new char[(buf_size+s)<<1];
            memcpy(tmp,ptr_buffer,buf_size);
            delete[] ptr_buffer;
            ptr_buffer=tmp;
            memmove(ptr_buffer+pos+s,ptr_buffer+pos,len-pos);
            memcpy(ptr_buffer+pos,str,s);
            buf_size+=s<<1;
            len+=s;}
    return *this;
}

Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str){
    
    int k = 0;      
    int strLen = str.len;
    
    if(strLen>buf_size)
        reserve(strLen);
    
    strLen= strLen - start;
    for(int i = start; i<span && i<strLen && k<span; i++){
        
        
        ptr_buffer[i]=str[k];
        
        
        k++;
    }
    
    return *this;
}

Mystring& Mystring::replace(size_type start, size_type span, const char * str){
    int k = 0;      
    int strLen = strlen(str);
    
    if(strLen>buf_size)
        reserve(strLen);
    strLen = strLen - start;
    for(int i = start; i<span && i<strLen && k<span; i++){
        ptr_buffer[i]=str[k];
        k++;
    }
    
    return *this;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const{

    return ptr_buffer;
}

Mystring::size_type Mystring::find_first_of(const char* s, size_type pos, size_type n) const{
    bool flag = false;
    size_type finder = 0;
    if(pos<len){
       for(int i = pos; i<len && !flag;i++){
           for(int k = 0; *(s+k)!='\0' && !flag && k<n;k++){
               if(ptr_buffer[i]==s[k]){
                   flag = true;
                   finder = pos+i;
               }
           }
        } 
    }
    if(flag){
        return finder;
    }
    return npos;
}
        
Mystring::size_type Mystring::find_last_not_of(const char* s, size_type pos) const{
    
    bool flag = true;
    size_type finder = 0;
    int start = pos;
    if(pos>len)
        start = len-1;
    
    
    for(int i = start; i>=0 && flag;i--){
        flag = false;
        for(int k = 0; *(s+k)!='\0' && !flag;k++){
            if(ptr_buffer[i]==s[k]){
                flag = true;
                
            }
        }
        finder = i;
        //cout<<"finder: " << finder<< endl;
        
     } 
    
    if(!flag){
        return finder;
    }
    return npos;
    
    
    
} 

bool operator==(const Mystring& a, const Mystring& b){
    if(strcmp(a.c_str(),b.c_str())==0)
        return true;
    return false;

}
bool operator==(const char * a, const Mystring& b){
    if(strcmp(a, b.c_str())!=0)
        return true;
    return false;
}
bool operator==(const Mystring& a, const char * b){
    if(strcmp(a.c_str(), b) != 0)
        return true;
    return false;
}

// Overload operator != for Mystring
bool operator!=(const Mystring& a, const Mystring& b){
    if(strcmp(a.c_str(),b.c_str())!=0)
        return true;
    return false;
}
bool operator!=(const char * a, const Mystring& b){
    if(strcmp(a, b.c_str())!=0)
        return true;
    return false;
}
bool operator!=(const Mystring& a, const char * b){
    if(strcmp(a.c_str(), b) != 0)
        return true;
    return false;
}



Mystring operator+(const Mystring& a, const Mystring& b){
    Mystring tmp(a);
    tmp+=b;
    return tmp;
}


// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) {
    out << str.c_str();
    return out;
}
        