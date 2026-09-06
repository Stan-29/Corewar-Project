/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_manage_robots_id
*/
#include "main.h"
#include <criterion/criterion.h>

Test(manage_load_pos, two_empty_load_adress)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[1].len_instr = 10;
    manage_load_pos(robots, 2);
    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[1].load_adress == 3072);
    free_robot_args(robots);
}

Test(manage_load_pos, four_empty_load_adress)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[1].len_instr = 10;
    robots[2].len_instr = 10;
    robots[3].len_instr = 10;
    manage_load_pos(robots, 4);
    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[1].load_adress == 3072);
    cr_assert(robots[2].load_adress == 1536);
    cr_assert(robots[3].load_adress == 4608);
    free_robot_args(robots);
}

Test(manage_load_pos, one_empty_load_adress_with_other)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[0].load_adress = 0;
    robots[1].len_instr = 10;
    robots[1].load_adress = 3072;
    robots[2].len_instr = 10;
    robots[2].load_adress = 1536;
    robots[3].len_instr = 10;
    manage_load_pos(robots, 4);
    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[1].load_adress == 3072);
    cr_assert(robots[2].load_adress == 1536);
    cr_assert(robots[3].load_adress == 4608);
    free_robot_args(robots);
}

Test(manage_load_pos, two_empty_load_adress_with_other)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[0].load_adress = 0;
    robots[1].len_instr = 10;
    robots[1].load_adress = 3072;
    robots[2].len_instr = 10;
    robots[3].len_instr = 10;
    manage_load_pos(robots, 4);
    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[1].load_adress == 3072);
    cr_assert(robots[2].load_adress == 1536);
    cr_assert(robots[3].load_adress == 4608);
    free_robot_args(robots);
}

Test(manage_load_pos, no_zero_load_adress_for_modulo)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[0].load_adress = 100;
    robots[1].len_instr = 10;
    robots[1].load_adress = 3172;
    robots[2].len_instr = 10;
    robots[2].load_adress = 1636;
    robots[3].len_instr = 10;
    manage_load_pos(robots, 4);
    cr_assert(robots[0].load_adress == 100);
    cr_assert(robots[1].load_adress == 3172);
    cr_assert(robots[2].load_adress == 1636);
    cr_assert(robots[3].load_adress == 4708);
    free_robot_args(robots);
}

Test(manage_load_pos, full_given_load_adress)
{
    robot_args_t *robots = init_robots();

    robots[0].len_instr = 10;
    robots[0].load_adress = 0;
    robots[1].len_instr = 10;
    robots[1].load_adress = 5372;
    robots[2].len_instr = 10;
    robots[2].load_adress = 2436;
    robots[3].len_instr = 10;
    robots[3].load_adress = 6123;
    manage_load_pos(robots, 4);
    cr_assert(robots[0].load_adress == 0);
    cr_assert(robots[1].load_adress == 5372);
    cr_assert(robots[2].load_adress == 2436);
    cr_assert(robots[3].load_adress == 6123);
    free_robot_args(robots);
}