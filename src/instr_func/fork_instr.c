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

void copy_robot(robot_game_t *robot, robot_game_t *fork)
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
    robot_game_t *new_elem = malloc(sizeof(robot_game_t));
    robot_game_t *temp = robot;

    if (!new_elem)
        return ERROR;
    copy_robot(robot, new_elem);
    new_elem->pc = (robot->pc + offset) % MEM_SIZE;
    while (temp->next_fork != NULL)
        temp = temp->next_fork;
    temp->next_fork = new_elem;
    return update_pc(game_infos, robot, 12, false);
}

unsigned int long_fork_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int offset = robot->instr_infos.usable_args[0];
    robot_game_t *new_elem = malloc(sizeof(robot_game_t));
    robot_game_t *temp = robot;

    if (!new_elem)
        return -1;
    copy_robot(robot, new_elem);
    new_elem->pc = (robot->pc + offset) % MEM_SIZE;
    while (temp->next_fork != NULL)
        temp = temp->next_fork;
    temp->next_fork = new_elem;
    return update_pc(game_infos, robot, 15, false);
}
