/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print_str, simple_str, .init = cr_redirect_stdout)
{
    print_str("01", false, 0);
    cr_assert_stdout_eq_str("01");
}

Test(print_str, empty_str, .init = cr_redirect_stdout)
{
    print_str("", false, 0);
    cr_assert_stdout_eq_str("");
}

Test(print_str, null_str, .init = cr_redirect_stdout)
{
    print_str(NULL, false, 0);
    cr_assert_stdout_eq_str("");
}

Test(print_nbr, zero_nbr, .init = cr_redirect_stdout)
{
    print_nbr(0, false, 0);
    cr_assert_stdout_eq_str("0");
}

Test(print_nbr, simple_nbr, .init = cr_redirect_stdout)
{
    print_nbr(133, false, 0);
    cr_assert_stdout_eq_str("133");
}

Test(print_nbr, negative_nbr, .init = cr_redirect_stdout)
{
    print_nbr(-23, false, 0);
    cr_assert_stdout_eq_str("-23");
}
