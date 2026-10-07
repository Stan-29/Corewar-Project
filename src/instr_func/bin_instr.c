/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"

unsigned int add_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value1 = get_value_from_type(game_infos, index_robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int res = value1 + value2;

    game_infos->robots_game[index_robot].reg[dest] = res;
    if (res == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return OK;
}

unsigned int sub_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value1 = get_value_from_type(game_infos, index_robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    int res = value1 - value2;

    game_infos->robots_game[index_robot].reg[dest] = res;
    if (res < 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return OK;
}

unsigned int and_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value1 = get_value_from_type(game_infos, index_robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int res = 0;

    game_infos->robots_game[index_robot].reg[dest] = value1 & value2;
    if (res < 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return OK;
}

unsigned int or_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value1 = get_value_from_type(game_infos, index_robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int res = 0;

    game_infos->robots_game[index_robot].reg[dest] = value1 | value2;
    if (res < 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return OK;
}

unsigned int xor_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value1 = get_value_from_type(game_infos, index_robot, 0);
    unsigned int value2 = get_value_from_type(game_infos, index_robot, 1);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 2);
    unsigned int res = 0;

    game_infos->robots_game[index_robot].reg[dest] = value1 ^ value2;
    if (res < 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    return OK;
}
