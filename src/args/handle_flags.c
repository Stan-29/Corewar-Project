/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "utils.h"
#include "main.h"
#include <stdbool.h>

unsigned int find_flag(char *flag, char *value, robot_t *robots,
    unsigned int *arg_index)
{
    if (is_positive_nb(value) != true)
        return ERROR;
    if (flag[1] != 'a' && flag[1] != 'n' && flag[1] != 'd')
        return ERROR;
    return OK;
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
