/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_files, valid_file)
{
    char *filepath = "./champions/bill.cor";
    unsigned int arg_index = 1;
    unsigned int robot_index = 0;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_file(filepath, robots, &arg_index, &robot_index) == OK);
    cr_assert(arg_index == 2);
    cr_assert(robot_index == 1);
    free(robots);
}

Test(handle_files, not_a_file)
{
    char *filepath = "robot1";
    unsigned int arg_index = 1;
    unsigned int robot_index = 0;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_file(filepath, robots, &arg_index, &robot_index) == ERROR);
    cr_assert(arg_index == 1);
    cr_assert(robot_index == 0);
    free(robots);
}

Test(handle_files, not_a_robot_file)
{
    char *filepath = "./main.c";
    unsigned int arg_index = 1;
    unsigned int robot_index = 0;
    robot_args_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_file(filepath, robots, &arg_index, &robot_index) == ERROR);
    cr_assert(arg_index == 1);
    cr_assert(robot_index == 0);
    free(robots);
}