/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_is_positive_nb
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(is_positive_nb, small_positive_number)
{
    cr_assert(is_positive_nb("0") == true);
}

Test(is_positive_nb, big_positive_number)
{
    cr_assert(is_positive_nb("12334559") == true);
}

Test(is_positive_nb, small_negative_number)
{
    cr_assert(is_positive_nb("-1") == false);
}

Test(is_positive_nb, big_negative_number)
{
    cr_assert(is_positive_nb("-12334559") == false);
}

Test(is_positive_nb, not_a_number)
{
    cr_assert(is_positive_nb("adzjl(§')-=") == false);
}

Test(is_positive_nb, empty_str)
{
    cr_assert(is_positive_nb("") == false);
}

Test(is_positive_nb, null_value)
{
    cr_assert(is_positive_nb(NULL) == false);
}