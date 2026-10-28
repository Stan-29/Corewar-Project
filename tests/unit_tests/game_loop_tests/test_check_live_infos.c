/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(check_live_infos, basic_check)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->nbr_live_exec = NBR_LIVE + 2;
    game_infos->cycle_infos.cycle_to_die_max = 1000;
    game_infos->cycle_infos.cycle_to_die = 1;
    cr_assert(check_live_infos(game_infos) == 0);
    cr_assert(game_infos->cycle_infos.cycle_to_die_max == 1000 - CYCLE_DELTA);
    cr_assert(game_infos->nbr_live_exec == 2);
    free_game_infos(game_infos);
}

Test(check_live_infos, end_game)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->nbr_live_exec = NBR_LIVE + 2;
    game_infos->cycle_infos.cycle_to_die_max = 1000;
    game_infos->cycle_infos.cycle_to_die = 0;
    game_infos->robots_game[0].is_alive = false;
    game_infos->robots_game[1].is_alive = false;
    cr_assert(check_live_infos(game_infos) == 1);
    free_game_infos(game_infos);
}