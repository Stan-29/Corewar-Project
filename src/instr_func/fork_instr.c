/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "consts.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

void copy_robot(robot_game_t *robot, robot_game_t *fork,
    unsigned int offset)
{
    fork->next_fork = NULL;
    fork->carry = robot->carry;
    fork->color_index = robot->color_index;
    fork->has_said_alive = robot->has_said_alive;
    for (unsigned int index = 0; index < REG_NUMBER; index++)
        fork->reg[index] = robot->reg[index];
    reset_instr_args(fork);
    fork->is_alive = true;
}

unsigned int fork_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int offset = get_value_from_type(game_infos, robot, 0);

    robot->next_fork = malloc(sizeof(robot_game_t));
    if (!robot->next_fork)
        return -1;
    copy_robot(robot, robot->next_fork, offset);
    robot->next_fork->pc = (robot->pc + offset % IDX_MOD) % MEM_SIZE;
    return update_pc(game_infos, robot, 12, false);
}

unsigned int long_fork_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int offset = get_value_from_type(game_infos, robot, 0);

    robot->next_fork = malloc(sizeof(robot_game_t));
    if (!robot->next_fork)
        return -1;
    copy_robot(robot, robot->next_fork, offset);
    robot->next_fork->pc = (robot->pc + offset) % MEM_SIZE;
    return update_pc(game_infos, robot, 12, false);
}
