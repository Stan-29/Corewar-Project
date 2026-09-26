/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print_hexa, simple_nbr, .init = cr_redirect_stdout)
{
    print_hexa(1, 2, 0, 0);
    cr_assert_stdout_eq_str("01");
}

Test(print_hexa, simple_nbr_long_size, .init = cr_redirect_stdout)
{
    print_hexa(1, 8, 0, 0);
    cr_assert_stdout_eq_str("00000001");
}

Test(print_hexa, complex_number, .init = cr_redirect_stdout)
{
    print_hexa(3745, 4, 0, 0);
    cr_assert_stdout_eq_str("0EA1");
}

Test(print_hexa, zero, .init = cr_redirect_stdout)
{
    print_hexa(0, 2, 0, 0);
    cr_assert_stdout_eq_str("00");
}

Test(print_hexa, size_zero, .init = cr_redirect_stdout)
{
    print_hexa(0, 0, 0, 0);
    cr_assert_stdout_eq_str("");
}