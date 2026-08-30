/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "main.h"

unsigned int handle_file(char *filepath, robot_t *robots,
    unsigned int *robot_index, unsigned int *arg_index)
{
    if (filepath[0] == '-') {
        *arg_index -= 1;
        return OK;
    }
    *robot_index += 1;
    return OK;
}
