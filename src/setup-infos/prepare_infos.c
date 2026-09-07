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

void if_same_add(robot_args_t *robots_args, game_infos_t *game_infos,
    unsigned int index, unsigned int index_robot)
{
    if (index != robots_args[index_robot].load_adress)
        return;
    for (unsigned int index_instr = 0;
        index_instr < robots_args[index_robot].len_instr; index_instr++) {
        game_infos->arena[index % MEM_SIZE] = robots_args[index_robot].
            instr_list[index_instr];
        index += 1;
    }
}

void put_robots_in_arena(robot_args_t *robots_args, game_infos_t *game_infos)
{
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        for (unsigned int index_robot = 0; index_robot < game_infos->nb_robots;
            index_robot++)
            if_same_add(robots_args, game_infos, index, index_robot);
    }
}

unsigned int prepare_infos(robot_args_t *robots_args, game_infos_t **game_infos)
{
    *game_infos = malloc(sizeof(game_infos_t));
    if (*game_infos == NULL)
        return display_error(MALLOC_FAIL);
    if (init_game_infos(robots_args, *game_infos) == ERROR)
        return ERROR;
    manage_robots_id(robots_args, (*game_infos)->nb_robots);
    for (unsigned int index = 0; index < (*game_infos)->nb_robots; index++)
        (*game_infos)->robots_game[index].reg[0] = robots_args[index].prog_nb;
    if (manage_load_pos(robots_args,
            (*game_infos)->nb_robots) == ERROR)
        return ERROR;
    put_robots_in_arena(robots_args, *game_infos);
    for (unsigned int index_robot = 0; index_robot < (*game_infos)->nb_robots;
        index_robot++)
        (*game_infos)->robots_game[index_robot].pc =
            robots_args[index_robot].load_adress;
    return OK;
}
