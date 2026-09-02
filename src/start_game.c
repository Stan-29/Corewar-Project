/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "utils.h"

unsigned int start_game(int argc, char **argv)
{
    robot_t *robots = init_robots();

    if (!robots)
        return display_error(MALLOC_FAIL);
    if (handle_args(argc, argv, robots) == ERROR)
        return ERROR;
    free_robots(robots);
    return OK;
}
