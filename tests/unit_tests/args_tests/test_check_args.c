/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_args
*/
#include "main.h"
#include <criterion/criterion.h>

Test(check_args, helper_arg)
{
    int argc = 2;
    char *argv[] = {"corewar", "-h"};

    cr_assert(check_args(argc, argv) == 0);
}

Test(check_args, no_args)
{
    int argc = 1;
    char *argv[] = {"corewar"};

    cr_assert(check_args(argc, argv) == 84);
}

Test(check_args, two_args)
{
    int argc = 3;
    char *argv[] = {"corewar", "exemple1", "exemple2"};

    cr_assert(check_args(argc, argv) == 0);
}

Test(check_args, too_many_args)
{
    int argc = 6;
    char *argv[] = {"corewar", "exemple1", "exemple2", "exemple3",
        "exemple4", "exemple5"};

    cr_assert(check_args(argc, argv) == 84);
}

Test(check_args, not_a_flag)
{
    int argc = 2;
    char *argv[] = {"corewar", "-a"};

    cr_assert(check_args(argc, argv) == 84);
}