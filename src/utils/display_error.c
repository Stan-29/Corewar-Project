/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include <unistd.h>
#include "utils.h"
#include "defines.h"
#include "consts.h"

unsigned int my_tablen(const char *tab[])
{
    unsigned int len = 0;

    if (tab == NULL)
        return 0;
    while (tab[len] != NULL) {
        len++;
    }
    return len;
}

unsigned int display_error(unsigned int error_id)
{
    const char *message = NULL;
    unsigned int tab_len = my_tablen(error_messages);

    if (error_id >= tab_len || error_id < 0)
        message = error_messages[0];
    else
        message = error_messages[error_id];
    write(2, message, my_strlen(message));
    return ERROR;
}
