/*
 * File:   Mystring.h
 * Author: wingning
 *
 * Mystring class that mimics the C++ string class in the standard library
 * 2019
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

class Mystring 
{
public:
    // types with scope in this class
    typedef unsigned int size_type;
    typedef char* iterator;
    typedef const char* const_iterator;
    static const long int npos = 1073741824;

    // Default constructor, code given to you in lab6 Mystring.cpp
    Mystring();
    
    // Other constructors, code given to you in lab6 Mystring.cpp
    Mystring(const char *);
    
    // Copy constructor, done in lab6
    Mystring(const Mystring& orig);

    // Destructor, code given to you in lab6 Mystring.cpp
    ~Mystring();

    // Iterators We will not implement them for hw4
    iterator begin();
    iterator end();

    //=== Memory Related ===

    // Change buffer size to n
    void reserve(size_type n);

    size_type size() const; // code given to you in lab6 Mystring.cpp
    size_type length() const; //code given to you in lab6 Mystring.cpp
    size_type capacity() const; //code given to you in lab6 Mystring.cpp
    size_type max_size() const; //code given to you in lab6 Mystring.cpp
    bool empty() const;

    //=== Overloading operators ===

    // Assignment operator
    // the next two lines are commented out, so to use default. Uncomment to implement both later
    Mystring& operator=(const Mystring&);
    Mystring& operator=(const char *);

    // Array notation
    char operator[](size_type pos) const;
    char& operator[](size_type pos);

    // Append
    Mystring& operator+=(const Mystring& str);
    Mystring& operator+=(const char * str);

    //=== Methods that modifiy the string

    void clear();
    void push_back(char c);

    Mystring& append(const Mystring& str);
    Mystring& append(const char * str);

    Mystring& insert(size_type pos, const Mystring& str);
    Mystring& insert(size_type pos, const char * str);

    Mystring& replace(size_type start, size_type span, const Mystring& str);
    Mystring& replace(size_type start, size_type span, const char * str);

    //=== Conversion to c-string

    const char * c_str() const; // code given to you in lab6 Mystring.cpp

    //=== Two new methods not in lab 6 header file

    // buffer (3) version of the overloaded method
    size_type find_first_of (const char* s, size_type pos, size_type n) const;

    // c-string (2)
    size_type find_last_not_of (const char* s, size_type pos = npos) const;


private:
    
    // pointer to the memory location where string is stored as a c-style
    // string
    char * ptr_buffer;
    
    // the size of the memory in terms of bytes or characters
    size_type buf_size;
    
    // number of characters currently in the memory not including the
    // terminating null character
    size_type len;
};

//=== Overloading global operators for Mystring

// Overload operator == for Mystring
bool operator==(const Mystring&, const Mystring&);
bool operator==(const char *, const Mystring&);
bool operator==(const Mystring&, const char *);

// Overload operator != for Mystring
bool operator!=(const Mystring&, const Mystring&);
bool operator!=(const char *, const Mystring&);
bool operator!=(const Mystring&, const char *);

// Overload operator + for string as concatenation
Mystring operator+(const Mystring&, const Mystring&);

// Output
ostream& operator<<(ostream& out, const Mystring& str);

// typedef Mystring::iterator iterator;

#endif /* MYSTRING_H */
