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

unsigned int store_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int source = get_value_from_type(game_infos, index_robot, 0);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 1);
    unsigned char *usable_value = ui_to_uc(source, 4);

    if (game_infos->robots_game[index_robot].instr_infos.size_infos[1] == 1) {
        dest = game_infos->robots_game[index_robot].instr_infos.usable_args[1];
        game_infos->robots_game[index_robot].reg[dest - 1] = source;
    } else {
        for (unsigned int index = 0; index < 4; index++) {
            game_infos->arena[(dest % IDX_MOD + index) % MEM_SIZE] =
                usable_value[index];
            game_infos->index_colors[(dest % IDX_MOD + index) % MEM_SIZE] =
                game_infos->robots_game[index_robot].color_index;
        }
    }
    update_pc(game_infos, index_robot, 3);
    free(usable_value);
    return OK;
}

unsigned int store_ind_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int source = get_value_from_type(game_infos, index_robot, 0);
    unsigned char *usable_value = ui_to_uc(source, 4);
    unsigned int offset_a = get_value_from_type(game_infos, index_robot, 1);
    unsigned int offset_b = get_value_from_type(game_infos, index_robot, 2);
    unsigned int dest = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;

    for (unsigned int index = 0; index < 4; index++) {
        game_infos->arena[(dest + index) % MEM_SIZE] = usable_value[index];
        game_infos->index_colors[(dest + index) % MEM_SIZE] =
            game_infos->robots_game[index_robot].color_index;
    }
    update_pc(game_infos, index_robot, 11);
    free(usable_value);
    return OK;
}
