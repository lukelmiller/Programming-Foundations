//@author lukelmiller
/*
 * File:   helper.h
 * Created on September 10, 2019, 3:51 PM
 */

#ifndef HELPER_H
#define HELPER_H
#include <cstdlib>
#include <iostream>
using namespace std;

class Helper{

public:
    Helper();
    ~Helper();

    char *find_first_not_in_the_set(char *str, const char *set);
    char *find_first_in_the_set(char *str, const char *set);

};

#endif /* HELPER_H */
