/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

void get_nb_robots_and_unique_values(robot_args_t *robots_args,
    game_infos_t *game_infos)
{
    game_infos->dump_cycle = -1;
    game_infos->nb_robots = 0;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (robots_args[index].instr_list != NULL)
            game_infos->nb_robots += 1;
        if (robots_args[index].dump != -1)
            game_infos->dump_cycle = robots_args[index].dump;
        if (robots_args[index].ncurse_active != -1) {
            game_infos->ncurse_timer = robots_args[index].ncurse_active;
            game_infos->ncurse_active = true;
        }
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
        robot_game[index].reg = malloc(sizeof(int) * REG_NUMBER);
        if (robot_game[index].reg == NULL)
            return ERROR;
        for (unsigned int index_reg = 0; index_reg < REG_NUMBER; index_reg++) {
            robot_game[index].reg[index_reg] = 0;
        }
    }
    return OK;
}

unsigned init_arena(game_infos_t *game_infos)
{
    game_infos->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
    game_infos->index_colors = malloc(sizeof(unsigned int) * MEM_SIZE);
    if (game_infos->arena == NULL || game_infos->index_colors == NULL) {
        free(game_infos->robots_game);
        return ERROR;
    }
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        game_infos->arena[index] = 0;
        game_infos->index_colors[index] = 0;
    }
    return OK;
}

unsigned int init_game_infos(robot_args_t *robots_args,
    game_infos_t *game_infos)
{
    get_nb_robots_and_unique_values(robots_args, game_infos);
    game_infos->robots_game = malloc(sizeof
        (robot_game_t) * game_infos->nb_robots);
    if (game_infos->robots_game == NULL)
        return ERROR;
    if (init_robot_game(game_infos->robots_game,
            game_infos->nb_robots) == ERROR)
        return ERROR;
    if (init_arena(game_infos) == ERROR)
        return ERROR;
    game_infos->robots_args = robots_args;
    game_infos->cycle_nb = 0;
    game_infos->cycle_to_die = CYCLE_TO_DIE;
    game_infos->nbr_live_exec = 0;
    return OK;
}
