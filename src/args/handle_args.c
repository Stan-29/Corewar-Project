/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"
#include "structs.h"
#include "main.h"

unsigned int handle_args(int argc, char **argv, robot_t **robots)
{
    if (argc < 2)
        return display_error(ARGS_NEEDED);
    if (handle_helper(argc, argv) == ERROR)
        return ERROR;
    return OK;
}
