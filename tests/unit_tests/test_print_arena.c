/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_helper
*/
#include "main.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print_arena, same_simple_str, .init = cr_redirect_stdout)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    print_arena(game_infos, false);
    cr_assert_stdout_neq_str("");
}
