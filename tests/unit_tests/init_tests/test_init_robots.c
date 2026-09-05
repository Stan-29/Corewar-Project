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
    robot_args_t *robots = init_robots();

    cr_assert(robots != NULL);
    free_robot_args(robots);
}

Test(init_robots, check_inside_init_values)
{
    robot_args_t *robots = init_robots();

    cr_assert(robots[0].load_adress == -1);
    cr_assert(robots[3].prog_nb == -1);
    cr_assert(robots[1].dump == -1);
    cr_assert(robots[1].len_instr == 0);
    cr_assert(robots[3].instr_list == NULL);
    free_robot_args(robots);
}

Test(init_robots, check_inside_values)
{
    robot_args_t *robots = init_robots();

    robots[0].load_adress = 300;
    robots[3].prog_nb = 1;
    cr_assert(robots[0].load_adress == 300);
    cr_assert(robots[3].prog_nb == 1);
    free_robot_args(robots);
}

void test_modify_value(robot_args_t *robots)
{
    robots[0].load_adress = 300;
    robots[3].prog_nb = 1;
    robots[1].dump = 100;
    robots[2].instr_list = malloc(sizeof(char) * 10);
}

Test(init_robots, check_inside_values_from_other_function)
{
    robot_args_t *robots = init_robots();

    test_modify_value(robots);
    cr_assert(robots[0].load_adress == 300);
    cr_assert(robots[3].prog_nb == 1);
    cr_assert(robots[1].dump == 100);
    cr_assert(robots[2].instr_list != NULL);
    free_robot_args(robots);
}
