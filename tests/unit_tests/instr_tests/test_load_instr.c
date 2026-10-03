/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(load_func, basic_load)
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
    game_infos->robots_game[0].instr_infos.size_infos[0] = 2;
    game_infos->robots_game[0].instr_infos.size_infos[1] = 1;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 1;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 2;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].carry = 0;
    load_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 1);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_game_infos(game_infos);
}

Test(load_func, zero_load)
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
    game_infos->robots_game[0].instr_infos.size_infos[0] = 2;
    game_infos->robots_game[0].instr_infos.size_infos[1] = 1;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 0;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 2;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].carry = 0;
    load_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].carry == 1);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_game_infos(game_infos);
}