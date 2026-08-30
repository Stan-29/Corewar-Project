/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_flags, dump_flag)
{
    int argc = 4;
    char *argv[] = {"corewar", "-dump", "0", "robot1", "robot2"};
    unsigned int arg_index = 1;
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, robots, &arg_index) == 0);
    free(robots);
}

Test(handle_flags, valid_load_adress_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "1234", "robot1", "robot2"};
    unsigned int arg_index = 1;
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, robots, &arg_index) == 0);
    free(robots);
}

Test(handle_flags, valid_prog_nb_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-n", "1", "robot1", "robot2"};
    unsigned int arg_index = 1;
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, robots, &arg_index) == 0);
    free(robots);
}

Test(handle_flags, wrong_flag)
{
    int argc = 5;
    char *argv[] = {"corewar", "-z", "1", "robot1", "robot2"};
    unsigned int arg_index = 1;
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_flags(argc, argv, robots, &arg_index) == 84);
    free(robots);
}
