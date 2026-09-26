/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
