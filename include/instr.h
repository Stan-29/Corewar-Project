/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** main includes
*/
#include "structs.h"

#ifndef INSTR_H_
    #define INSTR_H_

unsigned int pending_func(game_infos_t *, unsigned int);
unsigned int live_func(game_infos_t *, unsigned int);
unsigned int load_func(game_infos_t *, unsigned int);
unsigned int load_ind_func(game_infos_t *, unsigned int);
unsigned int zjump_func(game_infos_t *, unsigned int);
unsigned int print_func(game_infos_t *, unsigned int);
unsigned int store_ind_func(game_infos_t *, unsigned int);
unsigned int store_func(game_infos_t *, unsigned int);
unsigned int add_func(game_infos_t *, unsigned int);
unsigned int sub_func(game_infos_t *, unsigned int);
unsigned int and_func(game_infos_t *, unsigned int);
unsigned int or_func(game_infos_t *, unsigned int);
unsigned int xor_func(game_infos_t *, unsigned int);

#endif
