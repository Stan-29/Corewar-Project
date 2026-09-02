/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_error
*/
#include <criterion/criterion.h>
#include "utils.h"

Test(my_ustrcat, valid_str)
{
    unsigned char *str1 = malloc(sizeof(unsigned char) * 2);
    unsigned char *str2 = malloc(sizeof(unsigned char) * 2);
    unsigned char *result = NULL;

    str1[0] = 'a';
    str1[1] = 'b';
    str2[0] = 'c';
    str2[1] = 'd';
    result = my_ustrcat(str1, 2, str2, 2);
    if (result == NULL)
        return;
    cr_assert(result[0] == 'a');
    cr_assert(result[1] == 'b');
    cr_assert(result[2] == 'c');
    cr_assert(result[3] == 'd');
    free(result);
}

Test(my_ustrcat, str1_null)
{
    unsigned char *str1 = NULL;
    unsigned char *str2 = malloc(sizeof(unsigned char) * 2);
    unsigned char *result = NULL;

    str2[0] = 'c';
    str2[1] = 'd';
    result = my_ustrcat(str1, 0, str2, 2);
    if (result == NULL)
        return;
    cr_assert(result[0] == 'c');
    cr_assert(result[1] == 'd');
    free(result);
}

Test(my_ustrcat, str2_null)
{
    unsigned char *str1 = malloc(sizeof(unsigned char) * 2);
    unsigned char *str2 = NULL;
    unsigned char *result = NULL;

    str1[0] = 'a';
    str1[1] = 'b';
    result = my_ustrcat(str1, 2, str2, 0);
    if (result == NULL)
        return;
    cr_assert(result[0] == 'a');
    cr_assert(result[1] == 'b');
    free(result);
}

Test(my_ustrcat, both_str_null)
{
    unsigned char *str1 = NULL;
    unsigned char *str2 = NULL;
    unsigned char *result = NULL;

    result = my_ustrcat(str1, 0, str2, 0);
    cr_assert(result == NULL);
}