/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "main.h"
#include "structs.h"
#include "utils.h"

void print_arena(game_infos_t *game_infos)
{
    my_put_str("Cycle: ");
    my_put_nbr(game_infos->cycle_nb);
    my_put_str("\n");
    return;
}
