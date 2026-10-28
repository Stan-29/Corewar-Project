/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(load_func, basic_load_indirect)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 1, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->arena[4] = 222;
    load_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 222);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(load_func, basic_load_indirect_with_IDX_MOD)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 1, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {516, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->arena[4] = 222;
    load_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 222);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(load_func, basic_load_direct)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 1, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    load_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 4);
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_tests(game_infos);
}

Test(load_func, zero_load)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 1, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {0, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    load_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 1);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_tests(game_infos);
}

Test(load_func, load_dest_not_a_reg_nbr)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 1, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {123, 18, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    load_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_tests(game_infos);
}