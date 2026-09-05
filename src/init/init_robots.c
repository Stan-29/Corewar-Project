/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

robot_args_t *init_robots(void)
{
    robot_args_t *robots = malloc(sizeof(robot_args_t) * MAX_ARGS_NUMBER);

    if (!robots)
        return NULL;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (!&robots[index]) {
            return NULL;
        }
        robots[index].instr_list = NULL;
        robots[index].len_instr = 0;
        robots[index].load_adress = -1;
        robots[index].prog_nb = -1;
        robots[index].dump = -1;
    }
    return robots;
}
