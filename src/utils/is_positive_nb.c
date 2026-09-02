/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include "utils.h"
#include <stdlib.h>

bool is_positive_nb(char *str)
{
    if (str == NULL || my_strlen(str) == 0)
        return false;
    for (unsigned int index = 0; str[index] != '\0'; index++) {
        if (str[index] < '0' || str[index] > '9')
            return false;
    }
    return true;
}
