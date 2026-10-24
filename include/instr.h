/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** main includes
*/
#include "structs.h"

#ifndef INSTR_H_
    #define INSTR_H_

unsigned int pending_func(game_infos_t *, robot_game_t *);
unsigned int live_func(game_infos_t *, robot_game_t *);
unsigned int load_func(game_infos_t *, robot_game_t *);
unsigned int store_func(game_infos_t *, robot_game_t *);
unsigned int add_func(game_infos_t *, robot_game_t *);
unsigned int sub_func(game_infos_t *, robot_game_t *);
unsigned int and_func(game_infos_t *, robot_game_t *);
unsigned int or_func(game_infos_t *, robot_game_t *);
unsigned int xor_func(game_infos_t *, robot_game_t *);
unsigned int zjump_func(game_infos_t *, robot_game_t *);
unsigned int load_ind_func(game_infos_t *, robot_game_t *);
unsigned int store_ind_func(game_infos_t *, robot_game_t *);
unsigned int long_load_func(game_infos_t *, robot_game_t *);
unsigned int long_load_ind_func(game_infos_t *, robot_game_t *);
unsigned int print_func(game_infos_t *, robot_game_t *);

#endif
