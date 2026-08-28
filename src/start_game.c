/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"
#include "main.h"
#include "defines.h"

int start_game(int argc, char **argv)
{
    if (argc <= 1)
        return display_error(ARGS_NEEDED);
    if (argc > 5)
        return display_error(TOO_MANY_ARGS);
    if (argc == 2 && is_same_str(argv[1], "-h") == 0)
        return display_instr();
    return 0;
}
