/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "main.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

void get_next_id(robot_args_t *robots, unsigned int nb_robots, unsigned int *id)
{
    unsigned int actual_id = *id;

    for (unsigned int index = 0; index < nb_robots; index++) {
        if (robots[index].prog_nb == *id)
            *id += 1;
    }
    if (actual_id != *id)
        get_next_id(robots, nb_robots, id);
}

void manage_robots_id(robot_args_t *robots, unsigned int nb_robots)
{
    unsigned int id = 1;

    for (unsigned int index = 0; index < nb_robots; index++) {
        get_next_id(robots, nb_robots, &id);
        if (robots[index].prog_nb == -1)
            robots[index].prog_nb = id;
    }
}
