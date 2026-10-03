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
#include <ncurses.h>

void kill_robot(game_infos_t *game_infos, unsigned int index_robot)
{
    game_infos->robots_game[index_robot].is_alive = false;
    game_infos->robots_game[index_robot].pc = MEM_SIZE + 1;
    for (unsigned int index = 0; index < MEM_SIZE; index++)
        if (game_infos->index_colors[index] ==
            game_infos->robots_game[index_robot].color_index)
            game_infos->index_colors[index] = 0;
    game_infos->robots_game[index_robot].color_index = 0;
}

unsigned int print_winning_message(game_infos_t *game_infos)
{
    return 1;
}

bool check_robots_alive(game_infos_t *game_infos)
{
    unsigned int nb_robots_alive = 0;

    for (unsigned int index_robot = 0; index_robot < game_infos->nb_robots;
        index_robot++) {
        if (game_infos->robots_game[index_robot].is_alive &&
            game_infos->robots_game[index_robot].has_said_alive)
            nb_robots_alive += 1;
        else
            kill_robot(game_infos, index_robot);
        game_infos->robots_game[index_robot].has_said_alive = false;
    }
    game_infos->cycle_infos.cycle_to_die = CYCLE_TO_DIE -
        CYCLE_DELTA * game_infos->nbr_live_exec % NBR_LIVE;
    if (nb_robots_alive <= 1)
        return print_winning_message(game_infos);
    return 0;
}

void game_loop(game_infos_t *game_infos)
{
    manage_ncurse(game_infos);
    if (!game_infos->ncurse_infos.ncurse_stop ||
        game_infos->ncurse_infos.ncurse_skip_one) {
        if (game_infos->cycle_infos.cycle_to_die == 0 &&
            check_robots_alive(game_infos) == 1)
            return;
        manage_instructions(game_infos);
        if (game_infos->cycle_infos.cycle_nb ==
            game_infos->cycle_infos.dump_cycle)
            print_arena(game_infos, 0);
        game_infos->cycle_infos.cycle_nb += 1;
        game_infos->cycle_infos.cycle_to_die -= 1;
        game_infos->ncurse_infos.ncurse_skip_one = false;
    }
    if (get_ncurse_events(game_infos) != 1)
        game_loop(game_infos);
}
