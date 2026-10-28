/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_helper
*/
#include "main.h"
#include "structs.h"
#include "tests.h"
#include "instr.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print_arena, simple_arena_printing, .init = cr_redirect_stdout)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {0, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    print_arena(game_infos, false);
    cr_assert_stdout_neq_str("");
    free_tests(game_infos);
}

Test(print_arena, simple_arena_printing_with_dead_robots, .init = cr_redirect_stdout)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {0, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    game_infos->robots_game[1].is_alive = false;
    print_arena(game_infos, false);
    cr_assert_stdout_neq_str("");
    free_tests(game_infos);
}

Test(print_arena, arena_printing_with_one_fork, .init = cr_redirect_stdout)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    unsigned int size_infos[MAX_ARGS_NUMBER] = {0, 0, 0, 0};
    unsigned int args[MAX_ARGS_NUMBER] = {0, 0, 0, 0};

    if (!game_infos || init_test_infos(game_infos, 4, size_infos, args) == ERROR)
        return;
    fork_func(game_infos, &game_infos->robots_game[1]);
    print_arena(game_infos, false);
    cr_assert_stdout_neq_str("");
    free_tests(game_infos);
}
