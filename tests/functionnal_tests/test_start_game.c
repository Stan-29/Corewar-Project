/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_start_game
*/
#include "main.h"
#include <criterion/criterion.h>

Test(start_game, helper_arg)
{
    int argc = 2;
    char *argv[] = {"corewar", "-h"};

    cr_assert(start_game(argc, argv) == 0);
}

Test(start_game, no_args)
{
    int argc = 1;
    char *argv[] = {"corewar"};

    cr_assert(start_game(argc, argv) == ERROR);
}

Test(start_game, two_args)
{
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/pdd.cor"};

    cr_assert(start_game(argc, argv) == 0);
}

Test(start_game, four_args)
{
    int argc = 5;
    char *argv[] = {"corewar", "./champions/bill.cor", "./champions/bill.cor", "./champions/bill.cor", "./champions/bill.cor"};

    cr_assert(start_game(argc, argv) == 0);
}

Test(start_game, four_args_with_flags)
{
    int argc = 15;
    char *argv[] = {"corewar", "-dump", "65", "./champions/bill.cor", "-a", "323", "./champions/bill.cor", "-n", "21", "./champions/bill.cor", "-a", "323", "-n", "21", "./champions/bill.cor"};

    cr_assert(start_game(argc, argv) == 0);
}

Test(start_game, not_a_flag)
{
    int argc = 2;
    char *argv[] = {"corewar", "-a"};

    cr_assert(start_game(argc, argv) == ERROR);
}