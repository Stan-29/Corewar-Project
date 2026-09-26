/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "main.h"
#include "utils.h"
#include <ncurses.h>

void print_str(char *str, bool is_ncurse_active, int color_index)
{
    if (is_ncurse_active) {
        attron(COLOR_PAIR(color_index));
        printw("%s", str);
        attroff(COLOR_PAIR(color_index));
    } else
        my_put_str(str);
}

void print_nbr(int nbr, bool is_ncurse_active, int color_index)
{
    if (is_ncurse_active) {
        attron(COLOR_PAIR(color_index));
        printw("%i", nbr);
        attroff(COLOR_PAIR(color_index));
    } else
        my_put_nbr(nbr);
}
