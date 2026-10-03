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
#include <criterion/redirect.h>


Test(print_func, basic_print, .init = cr_redirect_stdout)
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
    game_infos->robots_game[0].instr_infos.usable_args[0] = 48;
    game_infos->robots_game[0].pc = 0;
    print_func(game_infos, 0);
    cr_assert_stdout_eq_str("0");
    cr_assert(game_infos->robots_game[0].pc == 2);
    free_game_infos(game_infos);
}

Test(print_func, print_one, .init = cr_redirect_stdout)
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
    game_infos->robots_game[0].instr_infos.usable_args[0] = 49;
    game_infos->robots_game[0].pc = 0;
    print_func(game_infos, 0);
    cr_assert_stdout_eq_str("1");
    cr_assert(game_infos->robots_game[0].pc == 2);
    free_game_infos(game_infos);
}