/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

void free_robot_args(robot_args_t *robots)
{
    if (robots == NULL)
        return;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (robots[index].instr_list != NULL)
            free(robots[index].instr_list);
    }
    free(robots);
}

void free_game_infos(game_infos_t *game_infos)
{
    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        free(game_infos->robots_game[index].reg);
    }
    free(game_infos->robots_game);
    free_robot_args(game_infos->robots_args);
    free(game_infos->arena);
    free(game_infos);
}
