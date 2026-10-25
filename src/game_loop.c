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
#include "utils.h"
#include <ncurses.h>

void kill_robot(game_infos_t *game_infos, unsigned int index_robot)
{
    if (game_infos->robots_game[index_robot].is_alive == false)
        return;
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
    unsigned int index = game_infos->last_to_live;

    if (game_infos->ncurse_infos.ncurse_active)
        endwin();
    my_put_str(game_infos->robots_args[index].header.prog_name);
    my_put_str("(");
    my_put_nbr(game_infos->robots_args[index].prog_nb);
    my_put_str(")");
    my_put_str(" won the game!\n");
    return 1;
}

unsigned int check_robots_alive(game_infos_t *game_infos)
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
    game_infos->cycle_infos.cycle_to_die =
        game_infos->cycle_infos.cycle_to_die_max;
    if (nb_robots_alive <= 1)
        return print_winning_message(game_infos);
    return 0;
}

unsigned int check_live_infos(game_infos_t *game_infos)
{
    if (game_infos->nbr_live_exec > NBR_LIVE) {
        game_infos->cycle_infos.cycle_to_die_max -= CYCLE_DELTA;
        game_infos->nbr_live_exec =
            game_infos->nbr_live_exec % NBR_LIVE;
    }
    if (game_infos->cycle_infos.cycle_to_die == 0 &&
        check_robots_alive(game_infos) == 1)
        return 1;
    return 0;
}

void game_loop(game_infos_t *game_infos)
{
    manage_ncurse(game_infos);
    if (!game_infos->ncurse_infos.ncurse_stop ||
        game_infos->ncurse_infos.ncurse_skip_one) {
        if (check_live_infos(game_infos) == 1)
            return;
        manage_robots(game_infos);
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
