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
unsigned int handle_args(int, char **, robot_args_t *);
unsigned int handle_helper(int, char **);
unsigned int find_flag(char *, char *, robot_args_t *, unsigned int *);
unsigned int handle_flags(int, char **, robot_args_t *, unsigned int *);
unsigned int handle_file(char *, robot_args_t *, unsigned int *,
    unsigned int *);
unsigned int dump_flag(char *, robot_args_t *);
unsigned int load_flag(char *, robot_args_t *);
unsigned int prog_nb_flag(char *, robot_args_t *);

//init
robot_args_t *init_robots(void);
unsigned int prepare_infos(robot_args_t *, game_infos_t *);

//free
void free_robots_args(robot_args_t *);
void free_game_infos(game_infos_t *);

#endif
