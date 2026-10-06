/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "structs.h"
#include "consts.h"

unsigned int add_func(game_infos_t *game_infos, unsigned int index_robot)
{
    robot_game_t robot_game = game_infos->robots_game[index_robot];
    unsigned int reg_a = robot_game.instr_infos.usable_args[0] - 1;
    unsigned int reg_b = robot_game.instr_infos.usable_args[1] - 1;
    unsigned int dest = robot_game.instr_infos.usable_args[2] - 1;
    unsigned int sum = robot_game.reg[reg_a] + robot_game.reg[reg_b];

    game_infos->robots_game[index_robot].reg[dest] = sum;
    if (sum == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return 0;
}
