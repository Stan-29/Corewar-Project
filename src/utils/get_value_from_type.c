/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "consts.h"
#include "structs.h"
#include <stdio.h>

int get_value_from_type(game_infos_t *game_infos,
    robot_game_t *robot, unsigned int index_arg)
{
    unsigned int value = robot->instr_infos.usable_args[index_arg];

    if (robot->instr_infos.size_infos[index_arg] == DIR_SIZE)
        return value;
    if (robot->instr_infos.size_infos[index_arg] == IND_SIZE) {
        if (op_tab[robot->instr_infos.next_instr_id].use_index)
            return value % IDX_MOD;
        else
            return game_infos->arena[
                (robot->pc + value % IDX_MOD) % MEM_SIZE];
    }
    if (robot->instr_infos.size_infos[index_arg] == REG_SIZE) {
        if ((value - 1) <= 15 && (value - 1) >= 0)
            return robot->reg[value - 1];
    }
    return -1;
}
