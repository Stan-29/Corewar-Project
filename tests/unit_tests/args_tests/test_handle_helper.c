/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_helper, helper_arg)
{
    int argc = 2;
    char *argv[] = {"corewar", "-h"};

    cr_assert(handle_helper(argc, argv) == 0);
}

Test(handle_helper, two_args)
{
    int argc = 3;
    char *argv[] = {"corewar", "exemple1", "exemple2"};

    cr_assert(handle_helper(argc, argv) == 0);
}

Test(handle_helper, not_a_flag)
{
    int argc = 2;
    char *argv[] = {"corewar", "-a"};

    cr_assert(handle_helper(argc, argv) == 84);
}