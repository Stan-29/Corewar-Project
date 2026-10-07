/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "consts.h"
#include "utils.h"
#include <stdio.h>

unsigned int live_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int robot_live = get_value_from_type(game_infos, index_robot, 0);

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_args[index].prog_nb == robot_live) {
            game_infos->robots_game[index].has_said_alive = true;
            game_infos->nbr_live_exec += 1;
            my_put_str(game_infos->robots_args[index].header.prog_name);
            my_put_str(" has said alive.\n");
        }
    }
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + 1 + DIR_SIZE) % MEM_SIZE;
    return OK;
}

unsigned int load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value = get_value_from_type(game_infos, index_robot, 0);
    unsigned int dest = get_value_from_type(game_infos, index_robot, 1);

    game_infos->robots_game[index_robot].reg[dest] = value;
    if (value == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    update_pc(game_infos, index_robot, 2);
    return OK;
}

unsigned int zjump_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int offset = get_value_from_type(game_infos, index_robot, 0);
    unsigned int pc = game_infos->robots_game[index_robot].pc;

    if (game_infos->robots_game[index_robot].carry == 1)
        game_infos->robots_game[index_robot].pc =
            (pc + offset) % MEM_SIZE;
    else
        game_infos->robots_game[index_robot].pc =
            (pc + IND_SIZE + 1) % MEM_SIZE;
    return OK;
}

unsigned print_func(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int value = get_value_from_type(game_infos, index_robot, 0);
    unsigned int pc = game_infos->robots_game[index_robot].pc;

    my_putchar(value + '0');
    game_infos->robots_game[index_robot].pc =
        (pc + REG_SIZE + 1) % MEM_SIZE;
    return OK;
}

unsigned int pending_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    if (op_tab[instr_infos.next_instr_id].has_coding_byte)
        game_infos->robots_game[index_robot].pc =
            (game_infos->robots_game[index_robot].pc + 1) % MEM_SIZE;
    return OK;
}
