/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

void print_hexa(int int_value, int size)
{
    unsigned int temp = 0;

    if (size != 0) {
        temp = int_value % 16;
        int_value = int_value / 16;
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        print_hexa(int_value, size - 1);
        my_putchar(temp);
    }
}
