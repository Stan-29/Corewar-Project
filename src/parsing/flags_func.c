/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "utils.h"
#include "consts.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

static unsigned int manage_flag_value(char *value, int *robot_value)
{
    if (*robot_value != -1)
        return ERROR;
    else
        *robot_value = my_get_nb(value);
    return OK;
}

unsigned int dump_flag(char *value, robot_args_t *robot)
{
    if (manage_flag_value(value, &robot->dump) == ERROR)
        return ERROR;
    if (robot->dump > CYCLE_TO_DIE)
        return ERROR;
    return OK;
}

unsigned int load_flag(char *value, robot_args_t *robot)
{
    if (manage_flag_value(value, &robot->load_adress) == ERROR)
        return ERROR;
    if (robot->load_adress > MEM_SIZE)
        return ERROR;
    return OK;
}

unsigned int prog_nb_flag(char *value, robot_args_t *robot)
{
    return manage_flag_value(value, &robot->prog_nb);
}

unsigned int ncurse_flag(char *value, robot_args_t *robot)
{
    return manage_flag_value(value, &robot->ncurse_active);
}
