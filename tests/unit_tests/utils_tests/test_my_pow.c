/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(my_pow, simple_nb)
{
    cr_assert(my_pow(2, 2) == 4);
}

Test(my_pow, power_zero)
{
    cr_assert(my_pow(2, 0) == 1);
}

Test(my_pow, power_one)
{
    cr_assert(my_pow(2, 1) == 2);
}

Test(my_pow, complex_number)
{
    cr_assert(my_pow(22, 5) == 5153632);
}