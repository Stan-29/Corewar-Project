/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(exit_event_ncurse, exit_ncurse)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    cr_assert(exit_event_ncurse(game_infos) == 1);
    free(game_infos);
}

Test(next_cycle_ncurse, next_cycle_ncurse)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_skip_one = false;
    next_cycle_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_skip_one == true);
    free(game_infos);
}

Test(pause_start_ncurse, pause_start_ncurse_false)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_stop = false;
    pause_start_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_stop == true);
    free(game_infos);
}

Test(pause_start_ncurse, pause_start_ncurse_true)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_stop = true;
    pause_start_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_stop == false);
    free(game_infos);
}

Test(speed_up_ncurse, speed_up_ncurse)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_timer = 100;
    speed_up_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_timer == 50);
    free(game_infos);
}

Test(speed_up_ncurse, speed_up_ncurse_max)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_timer = 50;
    speed_up_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_timer == 50);
    free(game_infos);
}

Test(speed_down_ncurse, speed_down_ncurse)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_timer = 100;
    speed_down_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_timer == 150);
    free(game_infos);
}

Test(speed_down_ncurse, speed_down_ncurse_max)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    game_infos->ncurse_infos.ncurse_timer = 960;
    speed_down_ncurse(game_infos);
    cr_assert(game_infos->ncurse_infos.ncurse_timer == 960);
    free(game_infos);
}