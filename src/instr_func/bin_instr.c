/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"

unsigned int add_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value1 = get_value_from_type(game_infos, robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, robot, 1);
    unsigned int dest = robot->instr_infos.usable_args[2];

    if (value1 == -1 || value2 == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 4, true);
    robot->reg[dest - 1] = value1 + value2;
    if (value1 + value2 == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 4, false);
}

unsigned int sub_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value1 = get_value_from_type(game_infos, robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, robot, 1);
    unsigned int dest = robot->instr_infos.usable_args[2];
    int res = value1 - value2;

    if (value1 == -1 || value2 == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 4, true);
    robot->reg[dest - 1] = res;
    if (res < 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 5, false);
}

unsigned int and_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value1 = get_value_from_type(game_infos, robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, robot, 1);
    unsigned int dest = robot->instr_infos.usable_args[2];

    if (value1 == -1 || value2 == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 4, true);
    robot->reg[dest - 1] = value1 & value2;
    if ((value1 & value2) == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 6, false);
}

unsigned int or_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value1 = get_value_from_type(game_infos, robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, robot, 1);
    unsigned int dest = robot->instr_infos.usable_args[2];

    if (value1 == -1 || value2 == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 4, true);
    robot->reg[dest - 1] = value1 | value2;
    if ((value1 | value2) == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 7, false);
}

unsigned int xor_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value1 = get_value_from_type(game_infos, robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, robot, 1);
    unsigned int dest = robot->instr_infos.usable_args[2];

    if (value1 == -1 || value2 == -1 || dest > 16 || dest < 1)
        return update_pc(game_infos, robot, 4, true);
    robot->reg[dest - 1] = value1 ^ value2;
    if ((value1 ^ value2) == 0)
        robot->carry = 1;
    else
        robot->carry = 0;
    return update_pc(game_infos, robot, 8, false);
}
