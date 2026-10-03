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

Test(zjump_func, basic_jump)
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
    game_infos->robots_game[0].instr_infos.usable_args[0] = 10;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].carry = 1;
    zjump_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].pc == 10);
    free_game_infos(game_infos);
}

Test(zjump_func, zero_carry_jump)
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
    game_infos->robots_game[0].instr_infos.usable_args[0] = 10;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].carry = 0;
    zjump_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].pc == 3);
    free_game_infos(game_infos);
}

Test(zjump_func, jump_using_modulo_mem_index)
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
    game_infos->robots_game[0].instr_infos.usable_args[0] = MEM_SIZE + 5;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].carry = 1;
    zjump_func(game_infos, 0);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_game_infos(game_infos);
}