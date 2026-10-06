/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "main.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

unsigned int exit_event_ncurse(game_infos_t *game_infos)
{
    return 1;
}

unsigned int next_cycle_ncurse(game_infos_t *game_infos)
{
    game_infos->ncurse_infos.ncurse_skip_one = true;
    return 0;
}

unsigned int pause_start_ncurse(game_infos_t *game_infos)
{
    game_infos->ncurse_infos.ncurse_stop =
        !game_infos->ncurse_infos.ncurse_stop;
    return 0;
}

unsigned int speed_up_ncurse(game_infos_t *game_infos)
{
    if (game_infos->ncurse_infos.ncurse_timer - 50 > 1)
        game_infos->ncurse_infos.ncurse_timer -= 50;
    else
        game_infos->ncurse_infos.ncurse_timer = 1;
    return 0;
}

unsigned int speed_down_ncurse(game_infos_t *game_infos)
{
    if (game_infos->ncurse_infos.ncurse_timer + 50 < 500)
        game_infos->ncurse_infos.ncurse_timer += 50;
    else
        game_infos->ncurse_infos.ncurse_timer = 500;
    return 0;
}
