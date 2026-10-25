/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>

unsigned int store_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int source = get_value_from_type(game_infos, robot, 0);
    unsigned int dest = get_value_from_type(game_infos, robot, 1);
    unsigned char *usable_value = NULL;

    if (source == -1 || dest == -1)
        return update_pc(game_infos, robot, 3, true);
    if (robot->instr_infos.size_infos[1] == 1) {
        dest = robot->instr_infos.usable_args[1];
        robot->reg[dest - 1] = source;
    } else {
        usable_value = ui_to_uc(source, 4);
        for (unsigned int index = 0; index < 4; index++) {
            game_infos->arena[(dest % IDX_MOD + index) % MEM_SIZE] =
                usable_value[index];
            game_infos->index_colors[(dest % IDX_MOD + index) % MEM_SIZE] =
                robot->color_index;
        }
        free(usable_value);
    }
    return update_pc(game_infos, robot, 3, false);
}

unsigned int store_ind_func(game_infos_t *game_infos, robot_game_t *robot)
{
    unsigned int source = get_value_from_type(game_infos, robot, 0);
    unsigned char *usable_value = ui_to_uc(source, 4);
    unsigned int offset_a = get_value_from_type(game_infos, robot, 1);
    unsigned int offset_b = get_value_from_type(game_infos, robot, 2);
    unsigned int dest = (robot->pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;

    if (source == -1 || offset_a == -1 || offset_b == -1) {
        free(usable_value);
        return update_pc(game_infos, robot, 11, true);
    }
    for (unsigned int index = 0; index < 4; index++) {
        game_infos->arena[(dest + index) % MEM_SIZE] = usable_value[index];
        game_infos->index_colors[(dest + index) % MEM_SIZE] =
            robot->color_index;
    }
    free(usable_value);
    return update_pc(game_infos, robot, 11, false);
}
