/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(manage_robots, all_three_temp_cylce)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor", "./champions/tyron.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    //forced modif
    game_infos->nb_robots = 4;
    game_infos->robots_game[2].is_alive = true;
    //robot1
    game_infos->robots_game[0].instr_infos.cycle_remaining = -1;
    game_infos->robots_game[0].instr_infos.next_instr_id = -1;
    game_infos->robots_game[0].pc = 0;
    game_infos->arena[game_infos->robots_game[0].pc] = 1;
    //robot2
    game_infos->robots_game[1].instr_infos.cycle_remaining = 0;
    game_infos->robots_game[1].instr_infos.next_instr_id = 1;
    game_infos->robots_game[1].instr_infos.usable_args[0] = 1;
    game_infos->robots_game[1].pc = 0;
    game_infos->arena[game_infos->robots_game[1].pc] = 1;
    //robot3
    game_infos->robots_game[2].instr_infos.cycle_remaining = 123;
    manage_robots(game_infos);
    //robot1
    cr_assert(game_infos->robots_game[0].instr_infos.next_instr_id == 1);
    cr_assert(game_infos->robots_game[0].instr_infos.cycle_remaining == 9);
    //robot2
    cr_assert(game_infos->robots_game[1].instr_infos.next_instr_id == -1);
    //robot3
    cr_assert(game_infos->robots_game[2].instr_infos.cycle_remaining == 122);
    //free_game_infos(game_infos);
}

Test(manage_robots, temp_cycle_minus_one_instr_live)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;
    int argc = 3;
    char *argv[] = {"./corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    if (handle_args(argc, argv, robots) == ERROR)
        return;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return;
    game_infos->robots_game[0].pc = 10;
    game_infos->arena[game_infos->robots_game[0].pc] = 31;
    manage_robots(game_infos);
    cr_assert(game_infos->robots_game[0].pc == 11);
    free_game_infos(game_infos);
}