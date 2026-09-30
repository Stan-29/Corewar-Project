/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_check_helper
*/
#include "main.h"
#include "structs.h"
#include <criterion/criterion.h>

Test(get_usable_args, one_arg)
{
    robot_game_t robot_game = {0};

    robot_game.instr_infos.size_infos[0] = 1;
    robot_game.instr_infos.size_infos[1] = 0;
    robot_game.instr_infos.args[0][0] = 222;
    get_usable_args(&robot_game);
    cr_assert(robot_game.instr_infos.usable_args[0] == 222);
    cr_assert(robot_game.instr_infos.usable_args[1] == 0);
    cr_assert(robot_game.instr_infos.usable_args[2] == 0);
    cr_assert(robot_game.instr_infos.usable_args[3] == 0);
}

Test(get_usable_args, three_args_with_diff_sizes)
{
    robot_game_t robot_game = {0};

    robot_game.instr_infos.size_infos[0] = 1;
    robot_game.instr_infos.size_infos[1] = 2;
    robot_game.instr_infos.size_infos[2] = 4;
    robot_game.instr_infos.size_infos[3] = 0;
    robot_game.instr_infos.args[0][0] = 222;
    robot_game.instr_infos.args[1][0] = 18;
    robot_game.instr_infos.args[1][1] = 132;
    robot_game.instr_infos.args[2][0] = 0;
    robot_game.instr_infos.args[2][1] = 132;
    robot_game.instr_infos.args[2][2] = 32;
    robot_game.instr_infos.args[2][3] = 243;
    get_usable_args(&robot_game);
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        printf("usable value: %i\n", robot_game.instr_infos.usable_args[index]);
    }
    cr_assert(robot_game.instr_infos.usable_args[0] == 222);
    cr_assert(robot_game.instr_infos.usable_args[1] == 4740);
    cr_assert(robot_game.instr_infos.usable_args[2] == 8659187);
    cr_assert(robot_game.instr_infos.usable_args[3] == 0);
}
