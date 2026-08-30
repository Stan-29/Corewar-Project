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

unsigned int dump_flag(char *value, robot_t *robots)
{
    return OK;
}

unsigned int load_flag(char *value, robot_t *robots)
{
    return OK;
}

unsigned int prog_nb_flag(char *value, robot_t *robots)
{
    return OK;
}

unsigned int find_flag(char *flag, char *value, robot_t *robots,
    unsigned int *arg_index)
{
    if (is_positive_nb(value) != true)
        return ERROR;
    for (unsigned int flag_index = 0; flags_tab[flag_index].flag != NULL;
        flag_index++) {
        if (is_same_str(flags_tab[flag_index].flag, flag) == 0)
            return flags_tab[flag_index].flag_func(value, robots);
    }
    return ERROR;
}

unsigned int handle_flags(int argc, char **argv, robot_t *robots,
    unsigned int *arg_index)
{
    if (argv[*arg_index][0] == '-') {
        if (*arg_index + 1 > argc)
            return ERROR;
        if (find_flag(argv[*arg_index], argv[*arg_index + 1],
                robots, arg_index) == ERROR)
            return ERROR;
    }
    return OK;
}
