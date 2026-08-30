/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(handle_args, one_valid_flags)
{
    int argc = 5;
    char *argv[] = {"corewar", "-a", "264", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    cr_assert(robots[0].load_adress == 264);
    free(robots);
}

Test(handle_args, no_flags_four_robots)
{
    int argc = 5;
    char *argv[] = {"corewar", "robot1", "robot2", "robot3", "robot4"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    free(robots);
}

Test(handle_args, no_flags_two_robots)
{
    int argc = 3;
    char *argv[] = {"corewar", "robot1", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    free(robots);
}

Test(handle_args, several_valid_flags)
{
    int argc = 9;
    char *argv[] = {"corewar", "-dump", "0", "-a", "264", "robot1", "-n", "41", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    cr_assert(robots[0].dump == 0);
    cr_assert(robots[0].load_adress == 264);
    cr_assert(robots[1].prog_nb == 41);
    free(robots);
}

Test(handle_args, more_than_one_flags_following)
{
    int argc = 11;
    char *argv[] = {"corewar", "-dump", "0", "-a", "264", "-a", "123",  "robot1", "-n", "41", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}

Test(handle_args, more_than_one_flags_seperated)
{
    int argc = 11;
    char *argv[] = {"corewar", "-a", "264", "-dump", "0", "-a", "123",  "robot1", "-n", "41", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}

Test(handle_args, same_flag_different_robot)
{
    int argc = 11;
    char *argv[] = {"corewar", "-dump", "0", "-a", "123",  "robot1", "-n", "41", "-a", "123", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == 0);
    cr_assert(robots[0].dump == 0);
    cr_assert(robots[0].load_adress == 123);
    cr_assert(robots[1].prog_nb == 41);
    cr_assert(robots[1].load_adress == 123);
    free(robots);
}

Test(handle_args, flag_without_value_at_begiinnig)
{
    int argc = 10;
    char *argv[] = {"corewar", "-a", "-dump", "0", "-a", "123",  "robot1", "-n", "41", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}

Test(handle_args, flag_without_value_at_end)
{
    int argc = 8;
    char *argv[] = {"corewar", "-dump", "0", "-a", "123",  "robot1", "-n", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}

Test(handle_args, not_a_flag)
{
    int argc = 8;
    char *argv[] = {"corewar", "-dumpi", "0", "-a", "123",  "robot1", "-n", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}

Test(handle_args, too_many_dump_flag)
{
    int argc = 9;
    char *argv[] = {"corewar", "-dump", "0", "-a", "123",  "robot1", "-dump", "0", "robot2"};
    robot_t *robots = init_robots();

    if (robots == NULL)
        return;
    cr_assert(handle_args(argc, argv, robots) == ERROR);
    free(robots);
}
