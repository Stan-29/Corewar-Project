/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "defines.h"
#include "main.h"
#include "structs.h"

void manage_instructions(game_infos_t *game_infos)
{
    return;
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
            game_infos->robots_game[index_robot].is_alive = false;
        game_infos->robots_game[index_robot].has_said_alive = false;
    }
    game_infos->cycle_to_die = CYCLE_TO_DIE -
        CYCLE_DELTA * game_infos->nbr_live_exec % NBR_LIVE;
    if (nb_robots_alive <= 1)
        return 1;
    return 0;
}

void game_loop(game_infos_t *game_infos)
{
    if (game_infos->cycle_to_die == 0)
        if (check_robots_alive(game_infos) == 1)
            return;
    manage_instructions(game_infos);
    if (game_infos->cycle_nb == game_infos->dump_cycle)
        print_arena(game_infos);
    game_infos->cycle_nb += 1;
    game_infos->cycle_to_die -= 1;
    game_loop(game_infos);
}
