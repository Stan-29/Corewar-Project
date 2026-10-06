/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <stdlib.h>

unsigned char *ui_to_uc(unsigned int value, unsigned int size)
{
    unsigned char *res = malloc(sizeof(unsigned char) * size);

    if (res == NULL)
        return NULL;
    for (unsigned int index = 0; index < size; index++)
        res[size - index - 1] = value >> (index * 8);
    return res;
}
