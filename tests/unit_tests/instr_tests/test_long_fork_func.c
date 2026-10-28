/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_long_fork_func
*/
#include "instr.h"
#include "structs.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(long_fork_func, basic_fork)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {5, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 15, size_infos, args) == ERROR)
        return;
    long_fork_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].next_fork != NULL);
    cr_assert(game_infos->robots_game[0].next_fork->pc == 5);
    free_tests(game_infos);
}

Test(long_fork_func, basic_fork_with_IDX_MOD)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {IDX_MOD + 5, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 15, size_infos, args) == ERROR)
        return;
    long_fork_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].next_fork != NULL);
    cr_assert(game_infos->robots_game[0].next_fork->pc == IDX_MOD + 5);
    free_tests(game_infos);
}

Test(long_fork_func, two_forks)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {2, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {IDX_MOD + 5, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 15, size_infos, args) == ERROR)
        return;
    long_fork_func(game_infos, &game_infos->robots_game[0]);
    long_fork_func(game_infos, &game_infos->robots_game[0]);
    printf("pc: %i\n", game_infos->robots_game[0].next_fork->next_fork->pc);
    cr_assert(game_infos->robots_game[0].next_fork != NULL);
    cr_assert(game_infos->robots_game[0].next_fork->pc == IDX_MOD + 5);
    cr_assert(game_infos->robots_game[0].next_fork->next_fork != NULL);
    cr_assert(game_infos->robots_game[0].next_fork->next_fork->pc == IDX_MOD + 5 + 3);
    free_tests(game_infos);
}