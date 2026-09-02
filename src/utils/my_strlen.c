/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <stdio.h>

unsigned int my_strlen(const char *word)
{
    unsigned int len = 0;

    if (!word)
        return 0;
    for (unsigned int index = 0; word[index] != '\0'; index++)
        len += 1;
    return len;
}
