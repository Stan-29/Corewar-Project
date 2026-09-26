/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_put_nbr, simple_nbr, .init = cr_redirect_stdout)
{
    my_put_nbr(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr, zero, .init = cr_redirect_stdout)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, complex_nbr, .init = cr_redirect_stdout)
{
    my_put_nbr(123);
    cr_assert_stdout_eq_str("123");
}

Test(my_put_nbr, negative_nbr, .init = cr_redirect_stdout)
{
    my_put_nbr(-12);
    cr_assert_stdout_eq_str("-12");
}
