/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_flags, valid_dump_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-dump", "0", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == OK);
    cr_assert(robots[0].dump == 0);
    free(robots);
}

Test(handle_flags, unvalid_dump_flag_bacause_two_flags)
{
    int argc = 5;
    char *argv[] = {"corewar", "-dump", "1", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    robots[0].dump = 2;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, unvalid_dump_flag_with_negative_value)
{
    int argc = 5;
    char *argv[] = {"corewar", "-dump", "-20", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, unvalid_dump_flag_with_no_value)
{
    int argc = 4;
    char *argv[] = {"corewar", "-dump", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, unvalid_dump_flag_with_greater_value_than_max)
{
    int argc = 4;
    char *argv[] = {"corewar", "-dump", "120093", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, valid_load_adress_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "123", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == OK);
    cr_assert(robots[0].load_adress == 123);
    free(robots);
}

Test(handle_flags, unvalid_load_adress_flag_with_greater_than_max)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "123273", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, unvalid_load_adress_flag_baceause_two_flags)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "1", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    robots[0].load_adress = 2;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, valid_prog_nb_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-n", "1", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == OK);
    cr_assert(robots[0].prog_nb == 1);
    free(robots);
}

Test(handle_flags, unvalid_prog_nb_flag_baceause_two_flags)
{
    int argc = 5;
    char *argv[] = {"corewar", "-n", "1", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    robots[0].prog_nb = 2;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, unvalid_flag_because_nothing_after)
{
    int argc = 3;
    char *argv[] = {"corewar", "./champions/bill.cor", "-dump"};
    unsigned int arg_index = 2;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == ERROR);
    free(robots);
}

Test(handle_flags, wrong_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-z", "1", "./champions/bill.cor", "./champions/pdd.cor"};
    unsigned int arg_index = 1;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, &robots[0], &arg_index) == 84);
    free(robots);
}
