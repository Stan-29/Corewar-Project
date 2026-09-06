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
#include <stdio.h>

unsigned int check_dump_flag(robot_args_t *robots)
{
    unsigned int nb_dump_flag = 0;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (robots[index].dump != -1)
            nb_dump_flag++;
    }
    if (nb_dump_flag > 1)
        return ERROR;
    return OK;
}

unsigned int parse_args(int argc, char **argv, robot_args_t *robots)
{
    unsigned int robot_index = 0;
    unsigned int arg_index = 1;

    while (arg_index < argc) {
        if (handle_flags(argc, argv, &robots[robot_index], &arg_index) == ERROR)
            return FLAG_ERROR;
        if (arg_index < argc && argv[arg_index][0] != '-' &&
            handle_file(argv[arg_index], robots,
                &robot_index, &arg_index) == ERROR)
            return FILE_ERROR;
    }
    if (robot_index < 2 || robot_index > 4)
        return ROBOT_ERROR;
    if (check_dump_flag(robots) == ERROR)
        return DUMP_FLAG_ERROR;
    return OK;
}

unsigned int handle_args(int argc, char **argv, robot_args_t *robots)
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
