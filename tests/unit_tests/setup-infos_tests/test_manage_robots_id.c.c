/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_manage_robots_id
*/
#include "main.h"
#include <criterion/criterion.h>

Test(manage_robots_id, with_all_id_empty)
{
    robot_args_t *robots = init_robots();

    manage_robots_id(robots, 4);
    cr_assert(robots[0].prog_nb == 1);
    cr_assert(robots[1].prog_nb == 2);
    cr_assert(robots[2].prog_nb == 3);
    cr_assert(robots[3].prog_nb == 4);
    free_robot_args(robots);
}

Test(manage_robots_id, with_all_id_done)
{
    robot_args_t *robots = init_robots();

    robots[0].prog_nb = 1;
    robots[1].prog_nb = 2;
    robots[2].prog_nb = 3;
    robots[3].prog_nb = 4;
    manage_robots_id(robots, 4);
    cr_assert(robots[0].prog_nb == 1);
    cr_assert(robots[1].prog_nb == 2);
    cr_assert(robots[2].prog_nb == 3);
    cr_assert(robots[3].prog_nb == 4);
    free_robot_args(robots);
}

Test(manage_robots_id, with_id_mixed)
{
    robot_args_t *robots = init_robots();

    robots[0].prog_nb = 3;
    robots[3].prog_nb = 2;
    manage_robots_id(robots, 4);
    cr_assert(robots[0].prog_nb == 3);
    cr_assert(robots[1].prog_nb == 1);
    cr_assert(robots[2].prog_nb == 4);
    cr_assert(robots[3].prog_nb == 2);
    free_robot_args(robots);
}

Test(manage_robots_id, with_big_id)
{
    robot_args_t *robots = init_robots();

    robots[0].prog_nb = 32;
    robots[3].prog_nb = 42;
    manage_robots_id(robots, 4);
    cr_assert(robots[0].prog_nb == 32);
    cr_assert(robots[1].prog_nb == 1);
    cr_assert(robots[2].prog_nb == 2);
    cr_assert(robots[3].prog_nb == 42);
    free_robot_args(robots);
}

Test(manage_robots_id, two_robots)
{
    robot_args_t *robots = init_robots();

    robots[0].prog_nb = 32;
    manage_robots_id(robots, 4);
    cr_assert(robots[0].prog_nb == 32);
    cr_assert(robots[1].prog_nb == 1);
    free_robot_args(robots);
}