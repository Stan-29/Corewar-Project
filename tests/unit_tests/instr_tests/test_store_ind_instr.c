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

Test(store_ind, basic_store)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    robot_args_t *robots = init_robots();
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    if (game_infos == NULL)
        return;
    game_infos->robots_game[0].instr_infos.size_infos[0] = 1;
    game_infos->robots_game[0].instr_infos.size_infos[1] = 2;
    game_infos->robots_game[0].instr_infos.size_infos[2] = 2;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 4;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 5;
    game_infos->robots_game[0].instr_infos.usable_args[2] = 5;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].reg[3] = 22;
    for (unsigned int index = 10; index < 14; index++)
        game_infos->arena[index] = 0;
    store_ind(game_infos, 0);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_game_infos(game_infos);
}


Test(store_ind, complex_store)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    robot_args_t *robots = init_robots();
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    if (game_infos == NULL)
        return;
    game_infos->robots_game[0].instr_infos.size_infos[0] = 1;
    game_infos->robots_game[0].instr_infos.size_infos[1] = 2;
    game_infos->robots_game[0].instr_infos.size_infos[2] = 2;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 4;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 5;
    game_infos->robots_game[0].instr_infos.usable_args[2] = 5;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].reg[3] = 287341;
    for (unsigned int index = 10; index < 14; index++)
        game_infos->arena[index] = 0;
    store_ind(game_infos, 0);
    cr_assert(game_infos->robots_game[0].reg[3] == 287341);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 4);
    cr_assert(game_infos->arena[12] == 98);
    cr_assert(game_infos->arena[13] == 109);
    free_game_infos(game_infos);
}


Test(store_ind, basic_store_with_idx_mod)
{
    game_infos_t *game_infos = malloc(sizeof(game_infos_t));
    robot_args_t *robots = init_robots();
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    if (game_infos == NULL)
        return;
    game_infos->robots_game[0].instr_infos.size_infos[0] = 1;
    game_infos->robots_game[0].instr_infos.size_infos[1] = 2;
    game_infos->robots_game[0].instr_infos.size_infos[2] = 2;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 4;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 10;
    game_infos->robots_game[0].instr_infos.usable_args[2] = 512;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].reg[3] = 22;
    for (unsigned int index = 10; index < 14; index++)
        game_infos->arena[index] = 0;
    store_ind(game_infos, 0);
    cr_assert(game_infos->robots_game[0].reg[3] == 22);
    cr_assert(game_infos->robots_game[0].pc == 7);
    cr_assert(game_infos->arena[10] == 0);
    cr_assert(game_infos->arena[11] == 0);
    cr_assert(game_infos->arena[12] == 0);
    cr_assert(game_infos->arena[13] == 22);
    free_game_infos(game_infos);
}
