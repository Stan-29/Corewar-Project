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
        game_infos->robots_game[index_robot].instr_infos.usable_args[1];

    if (value == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, index_robot, 2, true);
    game_infos->robots_game[index_robot].reg[dest - 1] = value;
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
    unsigned int dest =
        game_infos->robots_game[index_robot].instr_infos.usable_args[2];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;
    unsigned char res = 0;

    if (offset_a == -1 || offset_b == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, index_robot, 10, true);
    res = game_infos->arena[index_mem];
    game_infos->robots_game[index_robot].reg[dest - 1] = res;
    if (res == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return update_pc(game_infos, index_robot, 10, false);
}

unsigned int long_load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value = get_value_from_type(game_infos, index_robot, 0);
    unsigned int dest =
        game_infos->robots_game[index_robot].instr_infos.usable_args[1];

    if (value == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, index_robot, 13, true);
    if (game_infos->robots_game[index_robot].instr_infos.size_infos[0] == 2)
        value = game_infos->arena[(game_infos->robots_game[index_robot].pc +
                game_infos->robots_game[index_robot].instr_infos.usable_args[0])
            % MEM_SIZE];
    game_infos->robots_game[index_robot].reg[dest - 1] = value;
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
    unsigned int dest =
        game_infos->robots_game[index_robot].instr_infos.usable_args[2];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b)) % MEM_SIZE;
    unsigned char res = 0;

    if (offset_a == -1 || offset_b == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, index_robot, 10, true);
    res = game_infos->arena[index_mem];
    game_infos->robots_game[index_robot].reg[dest - 1] = res;
    if (res == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return update_pc(game_infos, index_robot, 10, false);
}
