/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "defines.h"
#include "structs.h"
#include <stdlib.h>

void init_test_robots(game_infos_t *game_infos, unsigned int instr_id,
    unsigned int size_infos[MAX_ARGS_NUMBER], unsigned int args[MAX_ARGS_NUMBER])
{
    for (unsigned int index = 0; index < MAX_ROBOTS_NUMBER; index++) {
        game_infos->robots_game[index].color_index = index;
        game_infos->robots_game[index].carry = 0;
        game_infos->robots_game[index].has_said_alive = false;
        game_infos->robots_game[index].pc = 0;
        for (unsigned int index_reg = 0; index_reg < REG_NUMBER; index_reg++)
            game_infos->robots_game[index].reg[index_reg] = 0;
        game_infos->robots_game[index].instr_infos.next_instr_id = instr_id;
        for (unsigned int index_size = 0; index_size < MAX_ARGS_NUMBER; index_size++)
            game_infos->robots_game[index].instr_infos.size_infos[index_size] = size_infos[index_size];
        for (unsigned int index_arg = 0; index_arg < MAX_ARGS_NUMBER; index_arg++)
            game_infos->robots_game[index].instr_infos.usable_args[index_arg] = args[index_arg];
        game_infos->robots_args[index].prog_nb = index + 1;
    }
}

unsigned int init_test_infos(game_infos_t *game_infos, unsigned int instr_id,
    unsigned int size_infos[MAX_ARGS_NUMBER], unsigned int args[MAX_ARGS_NUMBER])
{
    game_infos->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
    game_infos->index_colors = malloc(sizeof(unsigned int) * MEM_SIZE);
    game_infos->nb_robots = 4;
    if (!game_infos->arena || !game_infos->index_colors)
        return ERROR;
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        game_infos->arena[index] = 0;
        game_infos->index_colors[index] = 0;
    }
    game_infos->nbr_live_exec = 0;
    game_infos->robots_game = malloc(sizeof(robot_game_t) * MAX_ROBOTS_NUMBER);
    game_infos->robots_args = malloc(sizeof(robot_args_t) * MAX_ROBOTS_NUMBER);
    if (!game_infos->robots_game || !game_infos->robots_args) {
        free(game_infos->arena);
        free(game_infos->index_colors);
        return ERROR;
    }
    init_test_robots(game_infos, instr_id, size_infos, args);
    return OK;
}

void free_tests(game_infos_t *game_infos)
{
    free(game_infos->arena);
    free(game_infos->index_colors);
    free(game_infos->robots_game);
    free(game_infos->robots_args);
    free(game_infos);
}