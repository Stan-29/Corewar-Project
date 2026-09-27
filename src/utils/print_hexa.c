/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include "structs.h"
#include "utils.h"
#include <ncurses.h>

bool is_pc(game_infos_t *game_infos, unsigned int index_mem)
{
    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        if (game_infos->robots_game[index].pc == index_mem)
            return true;
    }
    return false;
}

void print_char(game_infos_t *game_infos, unsigned int index_mem,
    unsigned int temp)
{
    unsigned int color = 0;

    if (game_infos->ncurse_active) {
        color = (index_mem != -1) ? game_infos->index_colors[index_mem] : 0;
        if (is_pc(game_infos, index_mem))
            attron(A_STANDOUT);
        attron(COLOR_PAIR(color));
        printw("%c", temp);
        attroff(COLOR_PAIR(color));
        if (is_pc(game_infos, index_mem))
            attroff(A_STANDOUT);
    } else
        my_putchar(temp);
}

void print_hexa(int int_value, int size, game_infos_t *game_infos,
    unsigned int index_mem)
{
    unsigned int temp = 0;

    if (size != 0) {
        temp = int_value % 16;
        int_value = int_value / 16;
        if (temp < 10)
            temp = temp + '0';
        else
            temp = temp + '7';
        print_hexa(int_value, size - 1, game_infos, index_mem);
        print_char(game_infos, index_mem, temp);
    }
}
