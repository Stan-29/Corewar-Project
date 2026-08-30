/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(my_get_nb, simple_nb)
{
    cr_assert(my_get_nb("123") == 123);
}

Test(my_get_nb, simple_negative_nb)
{
    cr_assert(my_get_nb("-123") == -123);
}

Test(my_get_nb, edge_nb)
{
    cr_assert(my_get_nb("190") == 190);
}

Test(my_get_nb, nb_in_string)
{
    cr_assert(my_get_nb("123abhd") == 123);
}

Test(my_get_nb, several_nb_in_string)
{
    cr_assert(my_get_nb("123ajk23") == 123);
}

Test(my_get_nb, null_str)
{
    cr_assert(my_get_nb(NULL) == 0);
}
Test(my_get_nb, empty_str)
{
    cr_assert(my_get_nb("") == 0);
}