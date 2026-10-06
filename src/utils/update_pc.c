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
    unsigned int new_pc = game_infos->robots_game[index_robot].pc;
    unsigned int size = 1;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        new_pc = (new_pc + instr_infos.size_infos[index]) % MEM_SIZE;
    if (op_tab[index_instr].has_coding_byte)
        size = 2;
    new_pc = (new_pc + size) % MEM_SIZE;
    game_infos->robots_game[index_robot].pc = new_pc;
}
