/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(kill_robot, basic_kill)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].is_alive = true;
    game_infos->robots_game[0].pc = 10;
    game_infos->robots_game[0].color_index = 2;
    game_infos->index_colors[0] = game_infos->robots_game[0].color_index;
    kill_robot(game_infos, 0);
    cr_assert(game_infos->robots_game[0].is_alive == false);
    cr_assert(game_infos->robots_game[0].pc == MEM_SIZE + 1);
    cr_assert(game_infos->index_colors[0] == 0);
    cr_assert(game_infos->robots_game[0].color_index == 0);
}