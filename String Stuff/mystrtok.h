//@author lukelmiller
/*
 * File:   mystrtok.h
 * Created on September 22, 2019, 1:59 PM
 */

#ifndef MYSTRTOK_H
#define MYSTRTOK_H
size_t mystrlen(const char *s);
char *find_first_not_in_the_set(char *str, const char *set);
char *find_first_in_the_set(char *str, const char *set);
char *mystrtok(char *str, const char *delim);

#endif /* MYSTRTOK_H */
