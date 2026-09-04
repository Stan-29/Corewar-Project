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

void get_nb_robots_and_dump(robot_args_t *robots_args, game_infos_t *game_infos)
{
    game_infos->dump = -1;
    game_infos->nb_robots = 0;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (robots_args[index].instr_list != NULL)
            game_infos->nb_robots += 1;
        if (robots_args[index].dump != -1)
            game_infos->dump = robots_args[index].dump;
    }
}

unsigned int init_robot_game(robot_game_t *robot_game, unsigned int nb_robots)
{
    for (unsigned int index = 0; index < nb_robots; index++) {
        robot_game[index].carry = 0;
        robot_game[index].cycle_remaining = 0;
        robot_game[index].has_said_alive = false;
        robot_game[index].is_alive = true;
        robot_game[index].pc = 0;
        robot_game[index].reg = malloc(sizeof(unsigned char) * REG_NUMBER);
        if (robot_game[index].reg == NULL)
            return ERROR;
    }
    return OK;
}

unsigned int init_game_infos(robot_args_t *robots_args,
    game_infos_t *game_infos)
{
    get_nb_robots_and_dump(robots_args, game_infos);
    game_infos->robots_game = malloc(sizeof
        (robot_game_t) * game_infos->nb_robots);
    if (game_infos->robots_game == NULL)
        return ERROR;
    if (init_robot_game(game_infos->robots_game,
            game_infos->nb_robots) == ERROR)
        return ERROR;
    game_infos->robots_args = robots_args;
    game_infos->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
    if (game_infos->arena == NULL) {
        free(game_infos->robots_game);
        return ERROR;
    }
    game_infos->cycle_nb = 0;
    return OK;
}
