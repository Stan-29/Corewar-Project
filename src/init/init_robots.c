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

robot_t *init_robots(void)
{
    robot_t *robots = malloc(sizeof(robot_t) * MAX_ARGS_NUMBER);

    if (!robots)
        return NULL;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (!&robots[index]) {
            return NULL;
        }
        robots[index].intr_list = NULL;
        robots[index].load_adress = 0;
        robots[index].prog_nb = 0;
    }
    return robots;
}
