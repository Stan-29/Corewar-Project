/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"

unsigned int store_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int source = game_infos->robots_game[index_robot].
        reg[instr_infos.usable_args[0]];
    unsigned int dest = instr_infos.usable_args[1];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        dest % IDX_MOD) % MEM_SIZE;

    game_infos->arena[index_mem] = source;
    game_infos->index_colors[index_mem] =
        game_infos->robots_game[index_robot].color_index;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + 2) % MEM_SIZE;
    return 0;
}

unsigned int store_ind(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int source = game_infos->robots_game[index_robot].
        reg[instr_infos.usable_args[0]];
    unsigned int offset_a = instr_infos.usable_args[1];
    unsigned int offset_b = instr_infos.usable_args[2];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;

    game_infos->arena[index_mem] = source;
    game_infos->index_colors[index_mem] =
        game_infos->robots_game[index_robot].color_index;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + 2) % MEM_SIZE;
    return 0;
}
