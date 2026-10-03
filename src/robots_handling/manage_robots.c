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

void manage_cycles(game_infos_t *game_infos, unsigned int index_robot,
    unsigned int cycle_remaining, unsigned int instr_id)
{
    if (cycle_remaining != -1 && cycle_remaining != 0) {
        game_infos->robots_game[index_robot].instr_infos.cycle_remaining -= 1;
        return;
    }
    if (cycle_remaining == -1)
        get_instr_infos(&game_infos->robots_game[index_robot],
            game_infos->arena, instr_id);
    if (cycle_remaining == 0) {
        op_tab[game_infos->robots_game[index_robot].instr_infos.next_instr_id].
        func(game_infos, index_robot);
        reset_instr_args(game_infos->robots_game, index_robot);
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

void manage_robots(game_infos_t *game_infos)
{
    int cycle_remaining = 0;
    int instr_id = 0;

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_game[index].is_alive) {
            cycle_remaining = game_infos->robots_game[index].
                instr_infos.cycle_remaining;
            instr_id = get_id_instr(game_infos, index);
            manage_cycles(game_infos, index, cycle_remaining, instr_id);
        }
    }
    return;
}
