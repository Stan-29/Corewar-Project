/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include <stdio.h>

int my_get_nb(char *str)
{
    int result = 0;
    int sign = 1;
    unsigned int index = 0;

    if (str == NULL)
        return result;
    if (str[0] == '-') {
        sign = -1;
        index++;
    }
    while (str[index] <= '9' && str[index] >= '0') {
        result *= 10;
        result += str[index] - '0';
        index++;
    }
    return result * sign;
}
