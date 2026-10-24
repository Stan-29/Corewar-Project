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

unsigned int load_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value = get_value_from_type(game_infos, robot, 0);
    unsigned int dest =
        robot->instr_infos.usable_args[1];

    if (value == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 2, true);
    robot->reg[dest - 1] = value;
    if (value == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 2, false);
}

unsigned int load_ind_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int offset_a = get_value_from_type(game_infos, robot, 0);
    unsigned int offset_b = get_value_from_type(game_infos, robot, 1);
    unsigned int dest =
        robot->instr_infos.usable_args[2];
    unsigned int index_mem = (robot->pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;
    unsigned char res = 0;

    if (offset_a == -1 || offset_b == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 10, true);
    res = game_infos->arena[index_mem];
    robot->reg[dest - 1] = res;
    if (res == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 10, false);
}

unsigned int long_load_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value = get_value_from_type(game_infos, robot, 0);
    unsigned int dest =
        robot->instr_infos.usable_args[1];

    if (value == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 13, true);
    if (robot->instr_infos.size_infos[0] == 2)
        value = game_infos->arena[(robot->pc +
                robot->instr_infos.usable_args[0])
            % MEM_SIZE];
    robot->reg[dest - 1] = value;
    if (value == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 13, false);
}

unsigned int long_load_ind_func(game_infos_t *game_infos,
    robot_game_t *robot)
{
    unsigned int offset_a = get_value_from_type(game_infos, robot, 0);
    unsigned int offset_b = get_value_from_type(game_infos, robot, 1);
    unsigned int dest =
        robot->instr_infos.usable_args[2];
    unsigned int index_mem = (robot->pc +
        (offset_a + offset_b)) % MEM_SIZE;
    unsigned char res = 0;

    if (offset_a == -1 || offset_b == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 10, true);
    res = game_infos->arena[index_mem];
    robot->reg[dest - 1] = res;
    if (res == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 10, false);
}
