/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "main.h"
#include "utils.h"
#include "defines.h"

unsigned int start_game(int argc, char **argv)
{
    if (argc < 2)
        return display_error(ARGS_NEEDED);
    if (handle_helper(argc, argv) == 84)
        return 84;
    return 0;
}
