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
    for (unsigned int index = 0; index < MAX_ROBOTS_NUMBER; index++) {
        if (robots[index].instr_list != NULL)
            free(robots[index].instr_list);
    }
    free(robots);
}

void free_game_infos(game_infos_t *game_infos)
{
    robot_game_t *temp = NULL;
    robot_game_t *next_temp = NULL;

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        temp = game_infos->robots_game[index].next_fork;
        while (temp != NULL) {
            next_temp = temp->next_fork;
            free(temp);
            temp = next_temp;
        }
    }
    free(game_infos->robots_game);
    free_robot_args(game_infos->robots_args);
    free(game_infos->arena);
    free(game_infos->index_colors);
    free(game_infos);
}
