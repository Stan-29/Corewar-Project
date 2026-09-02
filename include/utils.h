/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** utils includes
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdbool.h>

//tab handling
unsigned int my_tablen(const char *tab[]);

//str handling
unsigned int my_strlen(const char *);
unsigned int is_same_str(const char *, const char *);
unsigned char *my_ustrcat(unsigned char *, unsigned int,
    unsigned char *, unsigned int);

//number handling
bool is_positive_nb(char *);
int my_get_nb(const char *);

unsigned int display_error(unsigned int);

#endif
