/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "main.h"

unsigned int find_flags(char *flag, char *value, robot_t *robots,
    unsigned int *arg_index)
{
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
        if (find_flags(argv[*arg_index], argv[*arg_index + 1],
                robots, arg_index) == ERROR)
            return ERROR;
    }
    return OK;
}
