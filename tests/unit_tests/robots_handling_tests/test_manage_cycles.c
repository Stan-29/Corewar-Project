/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(manage_cycles, temp_cycle_minus_one_instr_live)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = -1;
    game_infos->robots_game[0].pc = 0;
    game_infos->arena[1] = 0;
    game_infos->arena[2] = 0;
    game_infos->arena[3] = 0;
    game_infos->arena[4] = 1;
    manage_cycles(game_infos, 0, -1, 1);
    cr_assert(game_infos->robots_game[0].instr_infos.next_instr_id == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[0] == 4);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[1] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.cycle_remaining == 9);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][1] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][2] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][3] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.args[1][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[0] == 1);
    free_game_infos(game_infos);
}

Test(manage_cycles, temp_cycle_minus_one_instr_minus_one)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = -1;
    game_infos->robots_game[0].pc = 0;
    game_infos->arena[0] = 18;
    game_infos->arena[1] = 0;
    game_infos->arena[2] = 0;
    game_infos->arena[3] = 0;
    game_infos->arena[4] = 1;
    manage_cycles(game_infos, 0, -1, -1);
    cr_assert(game_infos->robots_game[0].instr_infos.next_instr_id == -1);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[1] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.cycle_remaining == -1);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][1] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][2] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][3] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[1][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[0] == 0);
    cr_assert(game_infos->robots_game[0].pc == 1);
    free_game_infos(game_infos);
}

Test(manage_cycles, temp_cycle_minus_one_instr_load)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = -1;
    game_infos->robots_game[0].pc = 0;
    game_infos->arena[0] = 2;
    game_infos->arena[1] = 208;
    game_infos->arena[2] = 0;
    game_infos->arena[3] = 1;
    game_infos->arena[4] = 1;
    manage_cycles(game_infos, 0, -1, 2);
    cr_assert(game_infos->robots_game[0].instr_infos.next_instr_id == 2);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[0] == 2);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[1] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.size_infos[2] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.cycle_remaining == 4);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][1] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][2] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[1][0] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.args[2][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[0] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[1] == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[2] == 0);
    free_game_infos(game_infos);
}

Test(manage_cycles, temp_cycle_random)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].pc = 0;
    game_infos->robots_game[0].instr_infos.cycle_remaining = 128;
    manage_cycles(game_infos, 0, 128, 1);
    cr_assert(game_infos->robots_game[0].instr_infos.cycle_remaining == 127);
    cr_assert(game_infos->robots_game[0].pc == 0);
    free_game_infos(game_infos);
}

Test(manage_cycles, temp_cycle_zero)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].instr_infos.next_instr_id = 1;
    game_infos->robots_game[0].instr_infos.args[0][0] = 0;
    game_infos->robots_game[0].instr_infos.args[0][1] = 0;
    game_infos->robots_game[0].instr_infos.args[0][2] = 0;
    game_infos->robots_game[0].instr_infos.args[0][3] = 1;
    game_infos->robots_game[0].instr_infos.usable_args[0] = 1;
    game_infos->robots_game[0].instr_infos.usable_args[1] = 0;
    manage_cycles(game_infos, 0, 0, 1);
    cr_assert(game_infos->robots_game[0].instr_infos.next_instr_id == -1);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][1] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][2] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.args[0][3] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[0] == 0);
    cr_assert(game_infos->robots_game[0].instr_infos.usable_args[1] == 0);
    free_game_infos(game_infos);
}