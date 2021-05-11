//@author lukelmiller
/*
 * File:   homework1.cpp
 * Created on September 10, 2019, 3:57 PM
 */

#include <cstdlib>
#include "Helper.h"

using namespace std;
int main(int argc, char** argv) {

    Helper hel;
    char test_string[15];
    char test_set[10];
    char *p; // pointer to the return character
    strcpy(test_string, "Hi Everyone!");
    strcpy(test_set, "e");
    p = hel.find_first_in_the_set(test_string, test_set);

    cout << *(p) << endl;
    // the above output should e and *(p-1) is v and *(p+1) is r
    p = hel.find_first_not_in_the_set(test_string, test_set);
    cout <<*p << endl; // the output should be H
    return 0;
}
