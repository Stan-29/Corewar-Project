/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "utils.h"
#include "structs.h"
#include "main.h"
#include <stdlib.h>

unsigned int parse_args(int argc, char **argv, robot_t *robots)
{
    unsigned int robot_index = 0;

    for (unsigned int arg_index = 1; arg_index < argc; arg_index++) {
        if (handle_flags(argc, argv, &robots[robot_index], &arg_index) == ERROR)
            return FLAG_ERROR;
        if (arg_index < argc && handle_file(argv[arg_index], robots,
                &robot_index, &arg_index) == ERROR)
            return FILE_ERROR;
    }
    return OK;
}

unsigned int handle_args(int argc, char **argv, robot_t *robots)
{
    unsigned int return_value = 0;

    if (argc < 2)
        return display_error(ARGS_NEEDED);
    return_value = handle_helper(argc, argv);
    if (return_value == ERROR)
        return ERROR;
    else if (return_value == 1) {
        free(robots);
        exit(OK);
    }
    return_value = parse_args(argc, argv, robots);
    if (return_value != OK)
        return display_error(return_value);
    return OK;
}
