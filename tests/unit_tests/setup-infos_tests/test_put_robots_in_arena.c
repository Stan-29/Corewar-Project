/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_manage_robots_id
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(put_robots_in_arena, two_args)
{
    int argc = 3;
    char *argv[] = {"corewar", "./champions/abel.cor", "-a", "63", "./champions/tyron.cor"};
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;

    if (!robots)
        return;
    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    cr_assert(game_infos->arena[0] == 11);
    cr_assert(game_infos->arena[21] == 244);
    cr_assert(game_infos->arena[22] == 0);
    cr_assert(game_infos->arena[62] == 0);
    cr_assert(game_infos->arena[63] == 11);
    cr_assert(game_infos->arena[84] == 244);
    cr_assert(game_infos->arena[85] == 0);
    free_game_infos(game_infos);
}