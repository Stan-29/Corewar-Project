/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "consts.h"
#include "utils.h"
#include <stdio.h>

unsigned int load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value = get_value_from_type(game_infos, index_robot, 0);
    unsigned int dest = 
        game_infos->robots_game[index_robot].instr_infos.usable_args[1] - 1;

    game_infos->robots_game[index_robot].reg[dest] = value;
    if (value == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    update_pc(game_infos, index_robot, 2);
    return OK;
}

unsigned int load_ind_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int offset_a = get_value_from_type(game_infos, index_robot, 0);
    unsigned int offset_b = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;
    unsigned char value[4] = {0};

    for (unsigned int index = 0; index < T_IND; index++) {
        value[index] = game_infos->arena[index_mem];
        index_mem = (index_mem + 1) % MEM_SIZE;
    }
    game_infos->robots_game[index_robot].reg[dest] = uc_to_ui(value, T_IND);
    if (game_infos->robots_game[index_robot].reg[dest] == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    update_pc(game_infos, index_robot, 2);
    return OK;
}
