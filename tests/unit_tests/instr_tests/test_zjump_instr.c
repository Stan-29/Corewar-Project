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

Test(zjump_func, basic_jump)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {10, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 9, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].carry = 1;
    zjump_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].pc == 10);
    free_tests(game_infos);
}

Test(zjump_func, zero_carry_jump)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {10, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 9, size_infos, args) == ERROR)
        return;
    zjump_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].pc == 3);
    free_tests(game_infos);
}

Test(zjump_func, jump_using_modulo_mem_index)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {MEM_SIZE + 5, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 9, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].carry = 1;
    zjump_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].pc == 5);
    free_tests(game_infos);
}