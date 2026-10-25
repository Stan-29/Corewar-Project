/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_load_ind
*/
#include "main.h"
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(long_load_ind_func, basic_load_ind_with_reg)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 2;
    game_infos->robots_game[0].reg[1] = 2;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[4] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 222);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(long_load_ind_func, basic_load_ind_with_index)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {2, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = 10;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[4] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 222);
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_game_infos(game_infos);
}

Test(long_load_ind_func, basic_load_ind_with_IDX_MOD)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {511, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = 10;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[513] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 222);
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_game_infos(game_infos);
}

Test(long_load_ind_func, mixed_load_ind)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = 10;
    game_infos->robots_game[0].reg[0] = 2;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[4] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 222);
    cr_assert(game_infos->robots_game[0].pc == 6);
    free_game_infos(game_infos);
}

Test(long_load_ind_func, zero_load)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 2, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {2, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[2] = 1;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 1);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 7);
    free_game_infos(game_infos);
}

Test(long_load_ind_func, load_ind_reg_not_in_range)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {20, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[4] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_game_infos(game_infos);
}

Test(long_load_ind_func, load_ind_dest_not_a_reg_nbr)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 2, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[2] = 0;
    game_infos->arena[4] = 222;
    long_load_ind_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_game_infos(game_infos);
}
