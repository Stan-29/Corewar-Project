/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** main includes
*/
#include "structs.h"

#ifndef MAIN_H_
    #define MAIN_H_

    #include "defines.h"

unsigned int display_instr(void);
unsigned int start_game(int, char **);

//args
unsigned int handle_args(int, char **, robot_t *);
unsigned int handle_helper(int, char **);
unsigned int find_flags(char *, char *, robot_t *, unsigned int *);
unsigned int handle_flags(int, char **, robot_t *, unsigned int *);
unsigned int handle_file(char *, robot_t *, unsigned int *, unsigned int *);

//init
robot_t *init_robots(void);

#endif
