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

unsigned int display_error(unsigned int error_id)
{
    const char *message = NULL;

    if (error_id > NBR_ERROR_MESSAGES || error_id == 0)
        message = error_messages[0];
    else
        message = error_messages[error_id];
    write(2, message, my_strlen(message));
    return 84;
}
