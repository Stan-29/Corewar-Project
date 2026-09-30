/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "consts.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int live_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int index_robot_live = instr_infos.usable_args[0];

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_args[index].prog_nb == index_robot_live)
            game_infos->robots_game[index].has_said_alive = true;
    }
    game_infos->nbr_live_exec += 1;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    return 0;
}

unsigned int load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    return 0;
}

unsigned int pending_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    return 0;
}
