/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include <stdlib.h>

void free_robots(robot_t *robots)
{
    if (robots == NULL)
        return;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (robots[index].instr_list != NULL)
            free(robots[index].instr_list);
    }
    free(robots);
}
