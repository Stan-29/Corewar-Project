/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_args, dump_flag)
{
    int argc = 4;
    char *argv[] = {"corewar", "-dump", "0", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    free(robots);
}


Test(handle_args, valid_load_adress_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "1234", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    free(robots);
}

Test(handle_args, valid_prog_nb_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-n", "1", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    free(robots);
}

Test(handle_args, wrong_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-z", "1", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 84);
    free(robots);
}
