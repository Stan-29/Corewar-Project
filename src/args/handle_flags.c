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

unsigned int dump_flag(char *value, robot_t *robot)
{
    if (manage_flag_value(value, &robot->dump) == ERROR)
        return ERROR;
    if (robot->dump > CYCLE_TO_DIE)
        return ERROR;
    return OK;
}

unsigned int load_flag(char *value, robot_t *robot)
{
    if (manage_flag_value(value, &robot->load_adress) == ERROR)
        return ERROR;
    if (robot->load_adress > MEM_SIZE)
        return ERROR;
    return OK;
}

unsigned int prog_nb_flag(char *value, robot_t *robot)
{
    return manage_flag_value(value, &robot->prog_nb);
}

unsigned int find_flag(char *flag, char *value, robot_t *robot,
    unsigned int *arg_index)
{
    if (is_positive_nb(value) != true)
        return ERROR;
    for (unsigned int flag_index = 0; flags_tab[flag_index].flag != NULL;
        flag_index++) {
        if (is_same_str(flags_tab[flag_index].flag, flag) == 0)
            return flags_tab[flag_index].flag_func(value, robot);
    }
    return ERROR;
}

unsigned int handle_flags(int argc, char **argv, robot_t *robot,
    unsigned int *arg_index)
{
    if (argv[*arg_index][0] == '-') {
        if (*arg_index + 1 > argc)
            return ERROR;
        if (find_flag(argv[*arg_index], argv[*arg_index + 1],
                robot, arg_index) == ERROR)
            return ERROR;
    }
    return OK;
}
