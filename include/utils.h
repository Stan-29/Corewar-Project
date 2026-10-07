/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** utils includes
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "structs.h"
    #include <stdbool.h>

//tab handling
unsigned int my_tablen(const char *tab[]);

//str handling
void my_putchar(char);
void my_put_str(char *);
unsigned int my_strlen(const char *);
unsigned int is_same_str(const char *, const char *);
unsigned char *my_ustrcat(unsigned char *, unsigned int,
    unsigned char *, unsigned int);
void print_str(char *, bool, int);


//number handling
int my_pow(int, int);
bool is_positive_nb(char *);
int my_get_nb(const char *);
void my_put_nbr(int);
void print_hexa(int, int, game_infos_t *, unsigned int);
void print_nbr(int, bool, int);
unsigned int uc_to_ui(unsigned char[4], unsigned int);
unsigned char *ui_to_uc(unsigned int, unsigned int);

unsigned int display_error(unsigned int);
void update_pc(game_infos_t *, unsigned int, unsigned int);
unsigned int get_value_from_type(game_infos_t *, unsigned int,
    unsigned int);

#endif
