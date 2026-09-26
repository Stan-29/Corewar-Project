/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include <stdio.h>
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "utils.h"

void print_header(char *name, unsigned int id, bool is_alive)
{
    my_put_str(name);
    my_putchar('(');
    my_put_nbr(id);
    my_putchar(')');
    if (is_alive)
        my_put_str(": alive\n");
    else
        my_put_str(": dead\n");
}

void print_reg(robot_game_t *robot_game)
{
    for (unsigned int reg = 0; reg < REG_NUMBER; reg++) {
        my_putchar('r');
        my_put_nbr(reg);
        my_put_str(" : ");
        print_hexa(robot_game->reg[reg], 8);
        if (reg != 0 && reg % 6 == 0)
            my_putchar('\n');
        else
            my_putchar(' ');
    }
}

void print_robot_infos(robot_game_t *robot_game, robot_args_t *robot_arg)
{
    my_putchar('\n');
    print_header(robot_arg->header.prog_name, robot_arg->prog_nb,
        robot_game->is_alive);
    print_reg(robot_game);
    my_put_str("\nPC: ");
    print_hexa(robot_game->pc, 8);
    my_put_str(" carry: ");
    my_put_nbr(robot_game->carry);
    my_putchar('\n');
}

void print_memory(game_infos_t *game_infos)
{
    my_put_str("Memory: ");
    for (unsigned int index = 0; index < 32; index++) {
        print_hexa(index, 2);
        my_putchar(' ');
    }
    my_putchar('\n');
    for (unsigned int index = 0; index < 32; index++)
        my_put_str("  -");
    my_putchar('\n');
    for (unsigned int index = 0; index < MEM_SIZE; index++) {
        print_hexa(index, 8);
        my_putchar(':');
        for (unsigned int index_mem = index; index_mem < index + 32;
            index_mem++) {
            my_putchar(' ');
            print_hexa(game_infos->arena[index_mem], 2);
        }
        my_putchar('\n');
        index += 31;
    }
}

void print_arena(game_infos_t *game_infos)
{
    my_put_str("Cycle: ");
    my_put_nbr(game_infos->cycle_nb);
    my_put_str("\n");
    my_put_str("Registers:\n");
    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        print_robot_infos(&game_infos->robots_game[index],
            &game_infos->robots_args[index]);
    }
    my_putchar('\n');
    print_memory(game_infos);
    return;
}
