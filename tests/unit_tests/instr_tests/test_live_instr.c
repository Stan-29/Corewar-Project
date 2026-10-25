/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_live_func
*/
#include "defines.h"
#include "tests.h"
#include "instr.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(live_func, basic_live)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {1, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 1, size_infos, args) == ERROR)
        return;
    live_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].has_said_alive == true);
    cr_assert(game_infos->robots_game[0].pc == 5);
    cr_assert(game_infos->nbr_live_exec == 1);
    free_tests(game_infos);
}

Test(live_func, bad_index_live)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {4, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {18, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 1, size_infos, args) == ERROR)
        return;
    live_func(game_infos, &game_infos->robots_game[0]);
    cr_assert(game_infos->robots_game[0].has_said_alive == false);
    cr_assert(game_infos->robots_game[0].pc == 5);
    cr_assert(game_infos->nbr_live_exec == 0);
    free_tests(game_infos);
}