/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "consts.h"
#include "structs.h"

int get_value_from_type(game_infos_t *game_infos,
    unsigned int index_robot, unsigned int index_arg)
{
    robot_game_t robot_game = game_infos->robots_game[index_robot];
    unsigned int value = robot_game.instr_infos.usable_args[index_arg];

    if (robot_game.instr_infos.size_infos[index_arg] == DIR_SIZE)
        return value;
    if (robot_game.instr_infos.size_infos[index_arg] == IND_SIZE) {
        if (op_tab[robot_game.instr_infos.next_instr_id].use_index)
            return value;
        else
            return game_infos->arena[
                (robot_game.pc + value % IDX_MOD) % MEM_SIZE];
    }
    if (robot_game.instr_infos.size_infos[index_arg] == REG_SIZE)
        if ((value - 1) <= 15 && (value - 1) >= 0)
            return robot_game.reg[value - 1];
    return -1;
}
