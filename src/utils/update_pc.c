/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "consts.h"

void update_pc(game_infos_t *game_infos, robot_game_t *robot,
    unsigned int index_instr, bool failed_args)
{
    unsigned int new_pc = robot->pc;
    unsigned int size = 1;

    if (failed_args) {
        robot->pc = (new_pc + 1) % MEM_SIZE;
        return;
    }
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        new_pc = (new_pc + robot->instr_infos.size_infos[index]) % MEM_SIZE;
    if (op_tab[index_instr].has_coding_byte)
        size = 2;
    new_pc = (new_pc + size) % MEM_SIZE;
    robot->pc = new_pc;
}
