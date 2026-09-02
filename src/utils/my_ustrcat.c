/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "utils.h"
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int fill_str2(unsigned char *new_str, unsigned char *str2,
    unsigned int len2, unsigned int index_new_str)
{
    if (str2 == NULL) {
        new_str[index_new_str] = '\0';
        return ERROR;
    }
    for (unsigned int index2 = 0; index2 < len2; index2++) {
        new_str[index_new_str] = str2[index2];
        index_new_str++;
    }
    new_str[index_new_str] = '\0';
    return OK;
}

unsigned char *my_ustrcat(unsigned char *str1, unsigned int len1,
    unsigned char *str2, unsigned int len2)
{
    unsigned char *new_str = NULL;
    unsigned int index_new_str = 0;
    unsigned int final_len = len1 + len2;

    new_str = malloc(sizeof(unsigned char) * (final_len + 1));
    if (new_str == NULL)
        return NULL;
    if (str1 != NULL) {
        for (unsigned int index1 = 0; index1 < len1; index1++) {
            new_str[index_new_str] = str1[index1];
            index_new_str++;
        }
        free(str1);
    }
    if (fill_str2(new_str, str2, len2, index_new_str) == ERROR)
        return NULL;
    return new_str;
}
