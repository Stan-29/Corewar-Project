/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_instr
*/
#include "main.h"
#include <criterion/criterion.h>

Test(init_game_infos, check_not_null)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    init_game_infos(robots, game_infos);
    cr_assert(game_infos != NULL);
    free_game_infos(game_infos);
}

Test(init_game_infos, free_game_with_robot_args_null)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    init_game_infos(robots, game_infos);
    cr_assert(game_infos != NULL);
    free_robot_args(game_infos->robots_args);
    game_infos->robots_args = NULL;
    free_game_infos(game_infos);
}

static void test_init_values(robot_args_t *robots)
{
    robots[0].dump = 100;
    robots[0].instr_list = malloc(sizeof(char) * 10);
    robots[1].instr_list = malloc(sizeof(char) * 10);
    robots[2].dump = 100;
    robots[2].instr_list = malloc(sizeof(char) * 10);
}

Test(init_game_infos, check_inside_init_values)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    test_init_values(robots);
    init_game_infos(robots, game_infos);
    cr_assert(game_infos->nb_robots == 3);
    cr_assert(game_infos->cycle_nb == 0);
    cr_assert(game_infos->robots_args[0].dump == 100);
    cr_assert(game_infos->robots_args[2].dump == 100);
    free_game_infos(game_infos);
}

Test(init_game_infos, check_inside_values)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    test_init_values(robots);
    init_game_infos(robots, game_infos);
    game_infos->cycle_nb = 12;
    game_infos->robots_args[0].load_adress = 300;
    game_infos->robots_args[3].prog_nb = 1;
    cr_assert(game_infos->cycle_nb == 12);
    cr_assert(game_infos->robots_args[0].load_adress == 300);
    cr_assert(game_infos->robots_args[3].prog_nb == 1);
    free_game_infos(game_infos);
}

static void modify_some_values(game_infos_t *game_infos)
{
    game_infos->dump = 20;
    game_infos->robots_args[0].load_adress = 166;
    game_infos->robots_args[3].len_instr = 8;
}

Test(init_game_infos, check_inside_values_from_other_function)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));

    if (game_infos == NULL)
        return;
    test_init_values(robots);
    init_game_infos(robots, game_infos);
    modify_some_values(game_infos);
    cr_assert(game_infos->dump == 20);
    cr_assert(game_infos->robots_args[0].load_adress == 166);
    cr_assert(game_infos->robots_args[3].len_instr = 8);
    free_game_infos(game_infos);
}
