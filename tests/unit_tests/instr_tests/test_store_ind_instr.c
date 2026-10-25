/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "defines.h"
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(store_ind, basic_store_with_index)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 2, 2, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 5, 5, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[3] = 22;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_tests(game_infos);
}


Test(store_ind, complex_store_with_index)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 2, 2, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 5, 5, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[3] = 287341;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].reg[3] == 287341);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 4);
    cr_assert(game_infos->arena[12] == 98);
    cr_assert(game_infos->arena[13] == 109);
    free_tests(game_infos);
}


Test(store_ind, store_with_idx_mod)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 2, 2, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 5, 517, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[3] = 22;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_tests(game_infos);
}

Test(store_ind, basic_store_with_reg)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 1, 2, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 5;
    game_infos->robots_game[0].reg[1] = 5;
    game_infos->robots_game[0].reg[3] = 22;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 5);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_tests(game_infos);
}

Test(store_ind, basic_store_mixed_sizes)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 2, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {4, 1, 5, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 5;
    game_infos->robots_game[0].reg[3] = 22;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 6);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_tests(game_infos);
}

Test(store_ind, store_reg_inexistent)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 2, 2, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {182, 5, 5, 0};

    if (!game_infos || init_test_infos(game_infos, 11, size_infos, args) == ERROR)
        return;
    store_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].pc == 1);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 0);
    free_tests(game_infos);
}
