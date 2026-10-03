/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "consts.h"
#include <ncurses.h>

unsigned int get_ncurse_events(game_infos_t *game_infos)
{
    int input = 0;

    if (!game_infos->ncurse_infos.ncurse_active)
        return OK;
    input = getch();
    if (input == -1)
        return OK;
    for (unsigned int index = 0; ncurse_events[index].code != END_EVENT_CODE;
        index++) {
        if (input == ncurse_events[index].code)
            return ncurse_events[index].event_func(game_infos);
    }
    return OK;
}

void print_dashboard(game_infos_t *game_infos)
{
    double speed = game_infos->ncurse_infos.ncurse_timer;

    speed = 10 - speed / 100;
    printw("Speed = x%.2f\t", speed);
    if (!game_infos->ncurse_infos.ncurse_stop) {
        attron(A_STANDOUT);
        printw("|>");
        attroff(A_STANDOUT);
        printw("  ||");
    } else {
        printw("|>  ");
        attron(A_STANDOUT);
        printw("||");
        attroff(A_STANDOUT);
    }
    printw("\n");
    return;
}

void manage_ncurse(game_infos_t *game_infos)
{
    if (!game_infos->ncurse_infos.ncurse_active)
        return;
    clear();
    print_dashboard(game_infos);
    print_arena(game_infos, game_infos->ncurse_infos.ncurse_active);
    timeout(game_infos->ncurse_infos.ncurse_timer);
}
