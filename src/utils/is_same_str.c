/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/
#include "utils.h"
#include "defines.h"

unsigned int is_same_str(const char *word1, const char *word2)
{
    unsigned int len1 = my_strlen(word1);

    if (len1 != my_strlen(word2))
        return 1;
    for (unsigned int index = 0; index < len1; index++) {
        if (word1[index] != word2[index])
            return 1;
    }
    return OK;
}
