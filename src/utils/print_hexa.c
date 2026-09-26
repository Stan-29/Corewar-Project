/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include "utils.h"
#include <ncurses.h>

void print_hexa(int int_value, int size, bool is_ncurse_active)
{
    unsigned int temp = 0;

    if (size != 0) {
        temp = int_value % 16;
        int_value = int_value / 16;
        if (temp < 10)
            temp = temp + '0';
        else
            temp = temp + '7';
        print_hexa(int_value, size - 1, is_ncurse_active);
        if (is_ncurse_active)
            printw("%c", temp);
        else
            my_putchar(temp);
    }
}
