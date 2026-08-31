/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int handle_file(char *filepath, robot_t *robots,
    unsigned int *robot_index, unsigned int *arg_index)
{
    FILE *fp = fopen(filepath, "r");

    if (fp == NULL)
        return ERROR;
    *robot_index += 1;
    *arg_index += 1;
    fclose(fp);
    return OK;
}
