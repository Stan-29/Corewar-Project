/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "consts.h"
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "consts.h"
#include "utils.h"
#include <stdlib.h>

void get_usable_args(robot_game_t *robot)
{
    unsigned char arg = 0;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        robot->instr_infos.usable_args[index] = 0;
    for (unsigned int index = 0; robot->instr_infos.size_infos[index] != 0
        && index < MAX_ARGS_NUMBER; index++) {
        for (unsigned int index_arg = 0;
            index_arg < robot->instr_infos.size_infos[index]; index_arg++) {
            arg = robot->instr_infos.args[index]
                [robot->instr_infos.size_infos[index] - index_arg - 1];
            robot->instr_infos.usable_args[index] += arg << (index_arg * 8);
        }
    }
}

void fill_size_infos(robot_game_t *robot, char *bin)
{
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        robot->instr_infos.size_infos[index] = 0;
    for (unsigned int index = 0; index < 8; index++) {
        if (bin[index] == '0' && bin[index + 1] == '1')
            robot->instr_infos.size_infos[index / 2] = REG_SIZE;
        if (bin[index] == '1' && bin[index + 1] == '0' &&
            !op_tab[robot->instr_infos.next_instr_id].dir_exeption)
            robot->instr_infos.size_infos[index / 2] = DIR_SIZE;
        if (bin[index] == '1' && bin[index + 1] == '0' &&
            op_tab[robot->instr_infos.next_instr_id].dir_exeption)
            robot->instr_infos.size_infos[index / 2] = IND_SIZE;
        if (bin[index] == '1' && bin[index + 1] == '1')
            robot->instr_infos.size_infos[index / 2] = IND_SIZE;
        index++;
    }
}

unsigned int get_size_infos(robot_game_t *robot, unsigned char coding_byte)
{
    char *bin = malloc(sizeof(char) * 8);
    unsigned int value = 0;

    if (bin == NULL)
        return ERROR;
    for (unsigned int index = 0; index < 8; index++)
        bin[index] = '0';
    for (unsigned int index = 0; index < 8 && coding_byte > 0; index++) {
        value = my_pow(2, 7 - index);
        if ((int)(coding_byte - value) >= 0) {
            bin[index] = '1';
            coding_byte -= value;
        }
    }
    fill_size_infos(robot, bin);
    free(bin);
    return OK;
}

unsigned int handle_coding_byte(robot_game_t *robot,
    unsigned char *arena, unsigned int instr_id, unsigned int *index_arena)
{
    if (instr_id == -1)
        return 1;
    robot->instr_infos.next_instr_id = instr_id;
    if (op_tab[instr_id].has_coding_byte == true) {
        if (get_size_infos(robot, arena[*index_arena]) == ERROR)
            return 1;
        *index_arena += 1;
    } else {
        robot->instr_infos.size_infos[0] = op_tab[instr_id].type[0];
    }
    robot->instr_infos.cycle_remaining = op_tab[instr_id].nbr_cycles - 1;
    return OK;
}

void get_instr_infos(robot_game_t *robot, unsigned char *arena,
    unsigned int instr_id)
{
    unsigned int index_arena = robot->pc + 1;

    if (handle_coding_byte(robot, arena, instr_id, &index_arena) == 1) {
        robot->pc = (robot->pc + 1) % MEM_SIZE;
        return;
    }
    for (unsigned int index = 0; robot->instr_infos.size_infos[index] != 0 &&
        index < MAX_ARGS_NUMBER; index++) {
        for (unsigned int index_arg = 0;
            index_arg < robot->instr_infos.size_infos[index]; index_arg++) {
            robot->instr_infos.args[index][index_arg] = arena[index_arena];
            index_arena = (index_arena + 1) % MEM_SIZE;
        }
    }
    get_usable_args(robot);
}
