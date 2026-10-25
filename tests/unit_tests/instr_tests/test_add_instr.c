/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(add_func, basic_add)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 2;
    game_infos->robots_game[0].reg[1] = 2;
    game_infos->robots_game[0].reg[2] = 0;
    add_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 2);
    cr_assert(game_infos->robots_game[0].reg[1] == 2);
    cr_assert(game_infos->robots_game[0].reg[2] == 4);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(add_func, basic_add_zero)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    add_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 1);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}

Test(add_func, add_with_reg_out_of_range)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {18, 2, 3, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    add_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_tests(game_infos);
}

Test(add_func, add_with_dest_out_of_range)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 1, 1, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 2, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[0] = 0;
    game_infos->robots_game[0].reg[1] = 0;
    game_infos->robots_game[0].reg[2] = 0;
    add_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].carry == 0);
    cr_assert(game_infos->robots_game[0].reg[0] == 0);
    cr_assert(game_infos->robots_game[0].reg[1] == 0);
    cr_assert(game_infos->robots_game[0].reg[2] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_tests(game_infos);
}