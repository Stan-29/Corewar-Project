/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include "utils.h"
#include "consts.h"

void my_put_str(char *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}
