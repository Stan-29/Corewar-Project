/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "consts.h"
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "consts.h"
#include <stdlib.h>
#include <stdio.h>

void manage_cycles(game_infos_t *game_infos, robot_game_t *robot,
    unsigned int cycle_remaining, unsigned int instr_id)
{
    if (cycle_remaining != -1 && cycle_remaining != 0) {
        robot->instr_infos.cycle_remaining -= 1;
        return;
    }
    if (cycle_remaining == -1)
        get_instr_infos(robot, game_infos->arena, instr_id);
    if (cycle_remaining == 0) {
        op_tab[robot->instr_infos.next_instr_id].
        func(game_infos, robot);
        reset_instr_args(robot);
    }
}

int get_id_instr(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int instr_id = game_infos->arena[
        game_infos->robots_game[index_robot].pc];

    if (instr_id > NBR_INSTR || instr_id < 1)
        return -1;
    return instr_id;
}

void manage_forks(game_infos_t *game_infos, unsigned int index_robot)
{
    robot_game_t *temp = game_infos->robots_game[index_robot].next_fork;
    int cycle_remaining = 0;
    int instr_id = 0;

    while (temp != NULL) {
        cycle_remaining = temp->instr_infos.cycle_remaining;
        instr_id = game_infos->arena[temp->pc];
        manage_cycles(game_infos, temp, cycle_remaining, instr_id);
        temp = temp->next_fork;
    }
}

void manage_robots(game_infos_t *game_infos)
{
    int cycle_remaining = 0;
    int instr_id = 0;

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_game[index].is_alive) {
            cycle_remaining = game_infos->robots_game[index].
                instr_infos.cycle_remaining;
            instr_id = get_id_instr(game_infos, index);
            manage_cycles(game_infos, &game_infos->robots_game[index],
                cycle_remaining, instr_id);
            manage_forks(game_infos, index);
        }
    }
    return;
}
