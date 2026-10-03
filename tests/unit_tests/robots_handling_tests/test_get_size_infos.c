/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(get_size_infos, four_args_all_sizes)
{
    robot_game_t robot_game = {0};
    unsigned char coding_byte = 222;

    get_size_infos(&robot_game, coding_byte);
    cr_assert(robot_game.instr_infos.size_infos[0] == 2);
    cr_assert(robot_game.instr_infos.size_infos[1] == 1);
    cr_assert(robot_game.instr_infos.size_infos[2] == 2);
    cr_assert(robot_game.instr_infos.size_infos[3] == 4);
}

Test(get_size_infos, two_args)
{
    robot_game_t robot_game = {0};
    unsigned char coding_byte = 224;

    get_size_infos(&robot_game, coding_byte);
    cr_assert(robot_game.instr_infos.size_infos[0] == 2);
    cr_assert(robot_game.instr_infos.size_infos[1] == 4);
    cr_assert(robot_game.instr_infos.size_infos[2] == 0);
    cr_assert(robot_game.instr_infos.size_infos[3] == 0);
}

Test(get_size_infos, one_valid_arg)
{
    robot_game_t robot_game = {0};
    unsigned char coding_byte = 128;

    get_size_infos(&robot_game, coding_byte);
    cr_assert(robot_game.instr_infos.size_infos[0] == 4);
    cr_assert(robot_game.instr_infos.size_infos[1] == 0);
    cr_assert(robot_game.instr_infos.size_infos[2] == 0);
    cr_assert(robot_game.instr_infos.size_infos[3] == 0);
}

Test(get_size_infos, three_args)
{
    robot_game_t robot_game = {0};
    unsigned char coding_byte = 104;

    get_size_infos(&robot_game, coding_byte);
    cr_assert(robot_game.instr_infos.size_infos[0] == 1);
    cr_assert(robot_game.instr_infos.size_infos[1] == 4);
    cr_assert(robot_game.instr_infos.size_infos[2] == 4);
    cr_assert(robot_game.instr_infos.size_infos[3] == 0);
}

Test(get_size_infos, three_args_with_dir_exception)
{
    robot_game_t robot_game = {0};
    unsigned char coding_byte = 104;

    robot_game.instr_infos.next_instr_id = 11;
    get_size_infos(&robot_game, coding_byte);
    cr_assert(robot_game.instr_infos.size_infos[0] == 1);
    cr_assert(robot_game.instr_infos.size_infos[1] == 2);
    cr_assert(robot_game.instr_infos.size_infos[2] == 2);
    cr_assert(robot_game.instr_infos.size_infos[3] == 0);
}