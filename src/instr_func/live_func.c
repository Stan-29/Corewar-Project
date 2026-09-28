/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int live_func(game_infos_t *game_infos, unsigned int index_robot)
{
    game_infos->robots_game[index_robot].pc += 1;
    return 0;
}
