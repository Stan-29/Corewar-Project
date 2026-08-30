/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** utils includes
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdbool.h>

//str handling
unsigned int my_strlen(const char *);
unsigned int is_same_str(const char *, const char *);

//number handling
bool is_positive_nb(char *);
int my_get_nb(const char *);

unsigned int display_error(unsigned int);

#endif
