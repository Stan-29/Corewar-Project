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

unsigned int live_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int robot_alive = get_value_from_type(game_infos, robot, 0);

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_args[index].prog_nb == robot_alive) {
            game_infos->robots_game[index].has_said_alive = true;
            game_infos->last_to_live = index;
            game_infos->nbr_live_exec += 1;
            my_put_str(game_infos->robots_args[index].header.prog_name);
            my_put_str("(");
            my_put_nbr(game_infos->robots_args[index].prog_nb);
            my_put_str(")");
            my_put_str(" has said alive.\n");
        }
    }
    robot->pc = (robot->pc + 1 + DIR_SIZE) % MEM_SIZE;
    return OK;
}

unsigned int zjump_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int offset = get_value_from_type(game_infos, robot, 0);

    if (robot->carry == 1) {
        robot->pc = (robot->pc + offset) % MEM_SIZE;
    } else {
        robot->pc = (robot->pc + IND_SIZE + 1) % MEM_SIZE;
    }
    return OK;
}

unsigned print_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int value = get_value_from_type(game_infos, robot, 0);

    my_putchar(value);
    robot->pc = (robot->pc + REG_SIZE + 1) % MEM_SIZE;
    return OK;
}

unsigned int pending_func(game_infos_t *game_infos, robot_game_t *robot)
{
    instr_infos_t instr_infos =
        robot->instr_infos;

    return update_pc(game_infos, robot, instr_infos.next_instr_id, false);
}
