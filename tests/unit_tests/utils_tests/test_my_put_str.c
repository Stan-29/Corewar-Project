/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_put_str, simple_str, .init = cr_redirect_stdout)
{
    my_put_str("hello");
    cr_assert_stdout_eq_str("hello");
}

Test(my_put_str, null_str, .init = cr_redirect_stdout)
{
    my_put_str(NULL);
    cr_assert_stdout_eq_str("");
}