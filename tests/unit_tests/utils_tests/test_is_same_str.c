/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_is_same_str
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(is_same_str, same_simple_str)
{
    cr_assert(is_same_str("123", "123") == 0);
}

Test(is_same_str, same_hard_str)
{
    cr_assert(is_same_str("ab12!", "ab12!") == 0);
}

Test(is_same_str, not_same_simple)
{
    cr_assert(is_same_str("123", "122") == 1);
}

Test(is_same_str, not_same_hard)
{
    cr_assert(is_same_str("12ab!", "12ab?") == 1);
}

Test(is_same_str, not_same_beginning)
{
    cr_assert(is_same_str("a23", "123") == 1);
}

Test(is_same_str, not_same_end)
{
    cr_assert(is_same_str("123", "12&") == 1);
}

Test(is_same_str, different_len)
{
    cr_assert(is_same_str("123", "12&az") == 1);
}
