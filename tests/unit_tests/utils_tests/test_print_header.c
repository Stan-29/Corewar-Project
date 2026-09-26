/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_my_get_nb
*/
#include "main.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>

Test(print_header, alive_robot, .init = cr_redirect_stdout)
{
    print_header("Abel", 1, true, false);
    cr_assert_stdout_eq_str("Abel(1): alive\n");
}

Test(print_header, dead_robot, .init = cr_redirect_stdout)
{
    print_header("pdd", 2, false, false);
    cr_assert_stdout_eq_str("pdd(2): dead\n");
}

Test(print_header, empty_name, .init = cr_redirect_stdout)
{
    print_header("", 3, false, false);
    cr_assert_stdout_eq_str("(3): dead\n");
}

Test(print_header, null_nme, .init = cr_redirect_stdout)
{
    print_header(NULL, 4, false, false);
    cr_assert_stdout_eq_str("(4): dead\n");
}
