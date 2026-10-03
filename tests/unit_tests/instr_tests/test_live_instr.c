/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(live_func, basic_live)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    robot_args_t *robots = init_robots();
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    if (game_infos == NULL)
        return;
    game_infos->nbr_live_exec = 0;
    game_infos->robots_game[0].has_said_alive = false;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 1;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_args[0].prog_nb = 1; 
    live_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].has_said_alive == true);
    cr_assert(game_infos->robots_game[0].pc == 5);
    cr_assert(game_infos->nbr_live_exec == 1);
    free_game_infos(game_infos);
}

Test(live_func, bad_index_live)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    robot_args_t *robots = init_robots();
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    if (game_infos == NULL)
        return;
    if (game_infos == NULL)
        return;
    game_infos->nbr_live_exec = 0;
    game_infos->robots_game[0].has_said_alive = false;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 18;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_args[0].prog_nb = 1; 
    live_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].has_said_alive == false);
    cr_assert(game_infos->robots_game[0].pc == 5);
    cr_assert(game_infos->nbr_live_exec == 0);
    free_game_infos(game_infos);
}