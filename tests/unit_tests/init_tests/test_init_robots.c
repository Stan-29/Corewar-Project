/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_instr
*/
#include "main.h"
#include <criterion/criterion.h>

Test(init_robots, check_not_null)
{
    robot_t *robots = init_robots();

    cr_assert(robots != NULL);
}

Test(init_robots, check_inside_init_values)
{
    robot_t *robots = init_robots();

    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[3].prog_nb == 0);
}

Test(init_robots, check_inside_values)
{
    robot_t *robots = init_robots();

    robots[0].load_adress = 300;
    robots[3].prog_nb = 1;
    cr_assert(robots[0].load_adress == 300);
    cr_assert(robots[3].prog_nb == 1);
}

unsigned int test_modify_value(robot_t *robots)
{
    robots[0].load_adress = 300;
    robots[3].prog_nb = 1;
    return OK;
}

Test(init_robots, check_inside_values_from_adress)
{
    robot_t *robots = init_robots();

    test_modify_value(robots);
    cr_assert(robots[0].load_adress == 300);
    cr_assert(robots[3].prog_nb == 1);
}
