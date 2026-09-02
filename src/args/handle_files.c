/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "structs.h"
#include "main.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int my_htonl(int val)
{
    int result = 0;

    result = (val >> 24) & 0xFF;
    result += (val >> 8) & 0xFF00;
    result += (val << 8) & 0xFF0000;
    result += (val << 24) & 0xFF000000;
    return result;
}

unsigned int check_file(FILE *fp, robot_t *robots, unsigned int *robot_index)
{
    unsigned char *buffer = malloc(sizeof(unsigned char) * BYTE_READ);

    if (buffer == NULL)
        return ERROR;
    if (fread(&robots[*robot_index].header, sizeof(header_t), 1, fp) == 0)
        return ERROR;
    if (my_htonl(robots[*robot_index].header.magic) != COREWAR_EXEC_MAGIC)
        return display_error(MAGIC_ERROR);
    while (fread(buffer, sizeof(unsigned char), BYTE_READ, fp) != 0) {
        robots[*robot_index].instr_list = my_ustrcat(robots[*robot_index].
            instr_list, robots[*robot_index].len_instr_list, buffer, BYTE_READ);
        if (robots[*robot_index].instr_list == NULL)
            return ERROR;
        robots[*robot_index].len_instr_list += BYTE_READ;
    }
    free(buffer);
    return OK;
}

unsigned int handle_file(char *filepath, robot_t *robots,
    unsigned int *robot_index, unsigned int *arg_index)
{
    FILE *fp = fopen(filepath, "r");

    if (fp == NULL)
        return ERROR;
    if (check_file(fp, robots, robot_index) == ERROR) {
        fclose(fp);
        return ERROR;
    }
    *robot_index += 1;
    *arg_index += 1;
    fclose(fp);
    return OK;
}
