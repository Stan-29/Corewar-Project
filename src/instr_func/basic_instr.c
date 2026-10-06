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

unsigned int live_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int index_robot_live = instr_infos.usable_args[0];

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_args[index].prog_nb == index_robot_live) {
            game_infos->robots_game[index].has_said_alive = true;
            game_infos->nbr_live_exec += 1;
        }
    }
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + DIR_SIZE + 1) % MEM_SIZE;
    return 0;
}

unsigned int load_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int source = instr_infos.usable_args[0];
    unsigned int dest = instr_infos.usable_args[1];
    unsigned int pc = game_infos->robots_game[index_robot].pc;
    unsigned char value = game_infos->arena[(pc + source % IDX_MOD) % MEM_SIZE];

    game_infos->robots_game[index_robot].reg[dest] = value << 0;
    if (game_infos->robots_game[index_robot].reg[dest] == 0)
        game_infos->robots_game[index_robot].carry = 1;
    else
        game_infos->robots_game[index_robot].carry = 0;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        game_infos->robots_game[index_robot].pc +=
            instr_infos.size_infos[index];
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + 2) % MEM_SIZE;
    return 0;
}

unsigned int zjump_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int offset = instr_infos.usable_args[0];

    if (game_infos->robots_game[index_robot].carry == 1)
        game_infos->robots_game[index_robot].pc =
            (game_infos->robots_game[index_robot].pc + offset) % MEM_SIZE;
    else
        game_infos->robots_game[index_robot].pc =
            (game_infos->robots_game[index_robot].pc + IND_SIZE + 1) % MEM_SIZE;
    return 0;
}

unsigned print_func(game_infos_t *game_infos, unsigned int index_robot)
{
    instr_infos_t instr_infos =
        game_infos->robots_game[index_robot].instr_infos;
    unsigned int value = instr_infos.usable_args[0];

    my_putchar(value);
    game_infos->robots_game[index_robot].pc =
        (game_infos->robots_game[index_robot].pc + REG_SIZE + 1) % MEM_SIZE;
    return 0;
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
    return 0;
}
