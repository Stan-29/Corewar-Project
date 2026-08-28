/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"
#include "main.h"
#include "defines.h"
#include <stdbool.h>

unsigned int check_helper(int argc, char **argv)
{
    if (argc == 2) {
        if (is_same_str(argv[1], "-h") == 0)
            return display_instr();
        else
            return display_error(ARGS_NEEDED);
    }
    return 0;
}

unsigned int check_args(int argc, char **argv)
{
    if (argc < 2)
        return display_error(ARGS_NEEDED);
    else if (argc > 5)
        return display_error(TOO_MANY_ARGS);
    else
        return check_helper(argc, argv);
    return 0;
}
