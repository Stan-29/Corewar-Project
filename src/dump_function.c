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

static void print_str(char *str, bool is_ncurse_active)
{
    if (is_ncurse_active)
        printw("%s", str);
    else
        my_put_str(str);
}

static void print_nbr(int nbr, bool is_ncurse_active)
{
    if (is_ncurse_active)
        printw("%i", nbr);
    else
        my_put_nbr(nbr);
}

void print_header(char *name, unsigned int id, bool is_alive,
    bool is_ncurse_active)
{
    print_str(name, is_ncurse_active);
    print_str("(", is_ncurse_active);
    print_nbr(id, is_ncurse_active);
    print_str(")", is_ncurse_active);
    if (is_alive)
        print_str(": alive\n", is_ncurse_active);
    else
        print_str(": dead\n", is_ncurse_active);
}

void print_reg(robot_game_t *robot_game, bool is_ncurse_active)
{
    for (unsigned int reg = 0; reg < REG_NUMBER; reg++) {
        print_str("r", is_ncurse_active);
        print_nbr(reg, is_ncurse_active);
        print_str(" : ", is_ncurse_active);
        print_hexa(robot_game->reg[reg], 8, is_ncurse_active);
        if (reg != 0 && reg % 6 == 0)
            print_str("\n", is_ncurse_active);
        else
            print_str(" ", is_ncurse_active);
    }
}

void print_robot_infos(robot_game_t *robot_game, robot_args_t *robot_arg,
    bool is_ncurse_active)
{
    print_str("\n", is_ncurse_active);
    print_header(robot_arg->header.prog_name, robot_arg->prog_nb,
        robot_game->is_alive, is_ncurse_active);
    print_reg(robot_game, is_ncurse_active);
    print_str("\nPC: ", is_ncurse_active);
    print_hexa(robot_game->pc, 8, is_ncurse_active);
    print_str(" carry: ", is_ncurse_active);
    print_nbr(robot_game->carry, is_ncurse_active);
    print_str("\n", is_ncurse_active);
}

void print_memory(game_infos_t *game_infos, bool is_ncurse_active)
{
    print_str("Memory:   ", is_ncurse_active);
    for (unsigned int index = 0; index < WIDTH_DISPLAY; index++) {
        print_hexa(index, 2, is_ncurse_active);
        print_str(" ", is_ncurse_active);
    }
    print_str("\n        ", is_ncurse_active);
    for (unsigned int index = 0; index < WIDTH_DISPLAY; index++)
        print_str("  -", is_ncurse_active);
    print_str("\n", is_ncurse_active);
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        print_hexa(index, 8, is_ncurse_active);
        print_str(":", is_ncurse_active);
        for (unsigned int index_mem = index; index_mem < index + WIDTH_DISPLAY;
            index_mem++) {
            print_str(" ", is_ncurse_active);
            print_hexa(game_infos->arena[index_mem], 2, is_ncurse_active);
        }
        print_str("\n", is_ncurse_active);
        index += WIDTH_DISPLAY;
    }
}

void print_arena(game_infos_t *game_infos, bool is_ncurse_active)
{
    print_str("Cycle: ", is_ncurse_active);
    print_nbr(game_infos->cycle_nb, is_ncurse_active);
    print_str("\n", is_ncurse_active);
    print_str("Registers:\n", is_ncurse_active);
    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        print_robot_infos(&game_infos->robots_game[index],
            &game_infos->robots_args[index], is_ncurse_active);
    }
    print_str("\n", is_ncurse_active);
    print_memory(game_infos, is_ncurse_active);
    return;
}
