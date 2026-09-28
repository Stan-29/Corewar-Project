/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "utils.h"
#include <ncurses.h>

void print_header(robot_args_t *robot_arg, robot_game_t *robot_game,
    bool is_ncurse_active)
{
    print_str(robot_arg->header.prog_name, is_ncurse_active,
        robot_game->color_index);
    print_str("(", is_ncurse_active, robot_game->color_index);
    print_nbr(robot_arg->prog_nb, is_ncurse_active, robot_game->color_index);
    print_str(")", is_ncurse_active, robot_game->color_index);
    if (robot_game->is_alive)
        print_str(": alive\n", is_ncurse_active, 0);
    else
        print_str(": dead\n", is_ncurse_active, 0);
}

void print_reg(robot_game_t *robot_game, bool is_ncurse_active)
{
    for (unsigned int reg = 0; reg < REG_NUMBER; reg++) {
        print_str("r", is_ncurse_active, 0);
        print_nbr(reg, is_ncurse_active, 0);
        print_str(" : ", is_ncurse_active, 0);
        print_hexa(robot_game->reg[reg], 8, is_ncurse_active, 0);
        if (reg != 0 && reg % 6 == 0)
            print_str("\n", is_ncurse_active, 0);
        else
            print_str(" ", is_ncurse_active, 0);
    }
}

void print_robot_infos(robot_game_t *robot_game, robot_args_t *robot_arg,
    bool is_ncurse_active)
{
    print_str("\n", is_ncurse_active, 0);
    print_header(robot_arg, robot_game, is_ncurse_active);
    print_reg(robot_game, is_ncurse_active);
    print_str("\nPC: ", is_ncurse_active, 0);
    print_hexa(robot_game->pc, 8, is_ncurse_active, 0);
    print_str(" carry: ", is_ncurse_active, 0);
    print_nbr(robot_game->carry, is_ncurse_active, 0);
    print_str("\n", is_ncurse_active, 0);
}

static void print_memory_header(bool is_ncurse_active)
{
    print_str("Memory:   ", is_ncurse_active, 0);
    for (unsigned int index = 0; index < WIDTH_DISPLAY; index++) {
        print_hexa(index, 2, is_ncurse_active, 0);
        print_str(" ", is_ncurse_active, 0);
    }
    print_str("        ", is_ncurse_active, 0);
    for (unsigned int index = 0; index < WIDTH_DISPLAY; index++)
        print_str("  -", is_ncurse_active, 0);
    print_str("\n", is_ncurse_active, 0);
}

void print_memory(game_infos_t *game_infos, bool is_ncurse_active)
{
    print_memory_header(is_ncurse_active);
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        print_hexa(index, 8, is_ncurse_active, 0);
        print_str(":", is_ncurse_active, 0);
        for (unsigned int index_mem = index; index_mem < index + WIDTH_DISPLAY
            && index_mem < MEM_SIZE; index_mem++) {
            print_str(" ", is_ncurse_active, 0);
            print_hexa(game_infos->arena[index_mem], 2, is_ncurse_active,
                game_infos->index_colors[index_mem]);
        }
        print_str("\n", is_ncurse_active, 0);
        index += WIDTH_DISPLAY;
    }
}

void print_arena(game_infos_t *game_infos, bool is_ncurse_active)
{
    print_str("Cycle: ", is_ncurse_active, 0);
    print_nbr(game_infos->cycle_infos.cycle_nb, is_ncurse_active, 0);
    print_str("\n", is_ncurse_active, 0);
    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        print_robot_infos(&game_infos->robots_game[index],
            &game_infos->robots_args[index], is_ncurse_active);
    }
    print_str("\n", is_ncurse_active, 0);
    print_memory(game_infos, is_ncurse_active);
    return;
}
