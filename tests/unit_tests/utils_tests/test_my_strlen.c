/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_strlen
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(my_strlen, one_len)
{
    cr_assert(my_strlen("1") == 1);
}

Test(my_strlen, one_len_with_end)
{
    cr_assert(my_strlen("1\0") == 1);
}

Test(my_strlen, more_than_one_len)
{
    cr_assert(my_strlen("1234") == 4);
}

Test(my_strlen, zero_len)
{
    cr_assert(my_strlen("") == 0);
}

Test(my_strlen, zero_len_with_end)
{
    cr_assert(my_strlen("\0") == 0);
}

Test(my_strlen, null_str)
{
    cr_assert(my_strlen(NULL) == 0);
}
