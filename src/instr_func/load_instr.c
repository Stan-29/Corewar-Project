/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** load instructions
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

    if (dest > 15)
        return update_pc(game_infos, index_robot, 2, true);
    game_infos->robots_game[index_robot].reg[dest] = value;
    if (value == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return update_pc(game_infos, index_robot, 2, false);
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
    return update_pc(game_infos, index_robot, 10, false);
}

unsigned int long_load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value = get_value_from_type(game_infos, index_robot, 0);
    unsigned int dest =
        game_infos->robots_game[index_robot].instr_infos.usable_args[1] - 1;

    if (game_infos->robots_game[index_robot].instr_infos.size_infos[0] == 2)
        value = game_infos->arena[
            (game_infos->robots_game[index_robot].pc + value) % MEM_SIZE];
    game_infos->robots_game[index_robot].reg[dest] = value;
    if (value == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return update_pc(game_infos, index_robot, 13, false);
}

unsigned int long_load_ind_func(game_infos_t *game_infos,
    unsigned int index_robot)
{
    unsigned int offset_a = get_value_from_type(game_infos, index_robot, 0);
    unsigned int offset_b = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        offset_a + offset_b) % MEM_SIZE;
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
    return update_pc(game_infos, index_robot, 14, false);
}
