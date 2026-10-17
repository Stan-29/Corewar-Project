/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** tests includes
*/
#include "structs.h"

#ifndef TESTS_H_
    #define TESTS_H_

unsigned int init_test_infos(game_infos_t *game_infos, unsigned int instr_id,
    unsigned int size_infos[MAX_ARGS_NUMBER], unsigned int args[MAX_ARGS_NUMBER]);
void free_tests(game_infos_t *game_infos);

#endif
