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
#include <unistd.h>
#include <ncurses.h>

unsigned int start_game(int argc, char **argv)
{
    robot_args_t *robots = init_robots();
    game_infos_t *game_infos = NULL;

    if (!robots)
        return display_error(MALLOC_FAIL);
    if (handle_args(argc, argv, robots) == ERROR)
        return ERROR;
    if (prepare_infos(robots, &game_infos) == ERROR)
        return ERROR;
    if (game_infos->ncurse_active)
        initscr();
    game_loop(game_infos);
    if (game_infos->ncurse_active)
        endwin();
    free_game_infos(game_infos);
    return OK;
}
