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
#include <criterion/redirect.h>


Test(print_func, basic_print, .init = cr_redirect_stdout)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {2, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 16, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[1] = 48;
    print_func(game_infos, &game_infos->robots_game[0]);
    cr_assert_stdout_eq_str("0");
    cr_assert(game_infos->robots_game[0].pc == 2);
    free_tests(game_infos);
}

Test(print_func, print_one, .init = cr_redirect_stdout)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {1, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {2, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 16, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[0].reg[1] = 49;
    print_func(game_infos, &game_infos->robots_game[0]);
    cr_assert_stdout_eq_str("1");
    cr_assert(game_infos->robots_game[0].pc == 2);
    free_tests(game_infos);
}