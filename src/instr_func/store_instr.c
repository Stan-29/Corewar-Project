/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "utils.h"

unsigned int store_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int source = game_infos->robots_game[index_robot].
        reg[instr_infos.usable_args[0]];
    unsigned char *usable_value = ui_to_uc(source, 4);
    unsigned int dest = instr_infos.usable_args[1];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        dest % IDX_MOD) % MEM_SIZE;

    for (unsigned int index = 0; index < 4; index++) {
        game_infos->arena[index_mem] = usable_value[index];
        game_infos->index_colors[index_mem] =
            game_infos->robots_game[index_robot].color_index;
        index_mem += 1;
    }
    update_pc(game_infos, index_robot, 3);
    return 0;
}

unsigned int store_ind(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int source = game_infos->robots_game[index_robot].
        reg[instr_infos.usable_args[0]];
    unsigned char *usable_value = ui_to_uc(source, 4);
    unsigned int offset_a = instr_infos.usable_args[1];
    unsigned int offset_b = instr_infos.usable_args[2];
    unsigned int index_mem = (game_infos->robots_game[index_robot].pc +
        (offset_a + offset_b) % IDX_MOD) % MEM_SIZE;

    for (unsigned int index = 0; index < 4; index++) {
        game_infos->arena[index_mem] = usable_value[index];
        game_infos->index_colors[index_mem] =
            game_infos->robots_game[index_robot].color_index;
        index_mem += 1;
    }
    update_pc(game_infos, index_robot, 11);
    return 0;
}
