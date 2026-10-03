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

Test(check_robots_alive, all_robots_alive)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor",  "./champions/tyron.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].is_alive = true;
    game_infos->robots_game[0].has_said_alive = true;
    game_infos->robots_game[1].is_alive = true;
    game_infos->robots_game[1].has_said_alive = true;
    game_infos->robots_game[2].is_alive = true;
    game_infos->robots_game[2].has_said_alive = true;
    game_infos->cycle_infos.cycle_to_die = 0;
    game_infos->nbr_live_exec = 1;
    cr_assert(check_robots_alive(game_infos) == 0);
    cr_assert(game_infos->robots_game[0].is_alive == true);
    cr_assert(game_infos->robots_game[0].has_said_alive == false);
    cr_assert(game_infos->robots_game[1].is_alive == true);
    cr_assert(game_infos->robots_game[1].has_said_alive == false);
    cr_assert(game_infos->cycle_infos.cycle_to_die == (1536 - 5 * 1));
    free_game_infos(game_infos);
}

Test(check_robots_alive, one_robot_dies_modulo_number_live)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor",  "./champions/tyron.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].is_alive = true;
    game_infos->robots_game[0].has_said_alive = true;
    game_infos->robots_game[1].is_alive = true;
    game_infos->robots_game[1].has_said_alive = true;
    game_infos->robots_game[2].is_alive = true;
    game_infos->robots_game[2].has_said_alive = false;
    game_infos->cycle_infos.cycle_to_die = 0;
    game_infos->nbr_live_exec = 41;
    cr_assert(check_robots_alive(game_infos) == 0);
    cr_assert(game_infos->robots_game[0].is_alive == true);
    cr_assert(game_infos->robots_game[0].has_said_alive == false);
    cr_assert(game_infos->robots_game[1].is_alive == true);
    cr_assert(game_infos->robots_game[1].has_said_alive == false);
    cr_assert(game_infos->cycle_infos.cycle_to_die == (1536 - 5 * 1));
    free_game_infos(game_infos);
}

Test(check_robots_alive, all_robots_die)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor",  "./champions/tyron.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].is_alive = true;
    game_infos->robots_game[0].has_said_alive = false;
    game_infos->robots_game[1].is_alive = true;
    game_infos->robots_game[1].has_said_alive = false;
    game_infos->robots_game[2].is_alive = true;
    game_infos->robots_game[2].has_said_alive = false;
    game_infos->cycle_infos.cycle_to_die = 0;
    game_infos->nbr_live_exec = 42;
    cr_assert(check_robots_alive(game_infos) == 1);
    cr_assert(game_infos->robots_game[0].is_alive == false);
    cr_assert(game_infos->robots_game[0].has_said_alive == false);
    cr_assert(game_infos->robots_game[1].is_alive == false);
    cr_assert(game_infos->robots_game[1].has_said_alive == false);
    cr_assert(game_infos->cycle_infos.cycle_to_die == (1536 - 5 * 2));
    free_game_infos(game_infos);
}