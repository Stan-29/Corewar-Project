/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_error
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"
#include "consts.h"

Test(display_error, args_needed, .init = cr_redirect_stderr)
{
    cr_assert(display_error(1) == ERROR);
    cr_assert_stderr_eq_str(error_messages[1]);
}

Test(display_error, invalid_id, .init = cr_redirect_stderr)
{
    cr_assert(display_error(-2) == ERROR);
    cr_assert_stderr_eq_str(error_messages[0]);
}

Test(display_error, id_zero, .init = cr_redirect_stderr)
{
    cr_assert(display_error(0) == ERROR);
    cr_assert_stderr_eq_str(error_messages[0]);
}

Test(display_error, off_limit_id, .init = cr_redirect_stderr)
{
    cr_assert(display_error(12553) == ERROR);
    cr_assert_stderr_eq_str(error_messages[0]);
}