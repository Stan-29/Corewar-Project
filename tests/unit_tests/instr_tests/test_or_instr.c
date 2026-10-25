/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_or_instr
*/
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(or_func, reg_or)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 5;
    game_infos->robots_game[0].reg[1] = 5;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 5);
    cr_assert(game_infos->robots_game[0].reg[1] == 5);
    cr_assert(game_infos->robots_game[0].reg[2] == (5 | 5));
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(or_func, ind_or)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->arena[1] = 5;
    game_infos->arena[2] = 5;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == (5 | 5));
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_tests(game_infos);
}

Test(or_func, ind_or_with_IDX_MOD)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {513, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->arena[1] = 5;
    game_infos->arena[2] = 5;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == (5 | 5));
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_tests(game_infos);
}

Test(or_func, dir_or)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 4, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {5, 5, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == (5 | 5));
    cr_assert(game_infos->robots_game[0].pc == 11);
    free_tests(game_infos);
}

Test(or_func, mixed_or)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 4, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 5, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->arena[1] = 5;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == (5 | 5));
    cr_assert(game_infos->robots_game[0].pc == 9);
    free_tests(game_infos);
}

Test(or_func, basic_or_zero)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 1);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(or_func, or_with_reg_out_of_range)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {18, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_tests(game_infos);
}

Test(or_func, or_with_dest_out_of_range)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {18, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    or_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_tests(game_infos);
}
