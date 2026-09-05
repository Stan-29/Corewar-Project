/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int prepare_infos(robot_args_t *robots_args, game_infos_t **game_infos)
{
    *game_infos = malloc(sizeof(game_infos_t));
    if (*game_infos == NULL)
        return display_error(MALLOC_FAIL);
    if (init_game_infos(robots_args, *game_infos) == ERROR)
        return ERROR;
    manage_robots_id((*game_infos)->robots_args, (*game_infos)->nb_robots);
    if (manage_load_pos((*game_infos)->robots_args,
            (*game_infos)->nb_robots) == ERROR)
        return ERROR;
    return OK;
}
