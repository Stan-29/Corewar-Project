/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "consts.h"

void update_pc(game_infos_t *game_infos, unsigned int index_robot,
    unsigned int index_instr)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int size = 1;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    if (op_tab[index_instr].has_coding_byte)
        size = 2;
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + size) % MEM_SIZE;
}
