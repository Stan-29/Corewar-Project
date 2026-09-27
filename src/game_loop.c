/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** game_loop
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include "consts.h"
#include <ncurses.h>

int get_id_instr(game_infos_t *game_infos, unsigned int index_robot)
{
    unsigned int instr_id = game_infos->arena[
        game_infos->robots_game[index_robot].pc];

    if (instr_id > NBR_INSTR || instr_id < 1) {
        game_infos->robots_game[index_robot].pc =
            (game_infos->robots_game[index_robot].pc + 1) % MEM_SIZE;
        return -1;
    }
    return instr_id;
}

void manage_cycles(game_infos_t *game_infos, unsigned int index,
    unsigned int temp_cycle, unsigned int instr_id)
{
    if (temp_cycle == -1) {
        game_infos->robots_game[index].cycle_remaining =
            op_tab[instr_id].nbr_cycles - 1;
        game_infos->robots_game[index].next_instr_id = instr_id;
    }
    if (temp_cycle == 0) {
        op_tab[game_infos->robots_game[index].next_instr_id].func(game_infos);
        game_infos->robots_game[index].cycle_remaining = -1;
        game_infos->robots_game[index].pc += 1;
    }
    if (temp_cycle != -1 && temp_cycle != 0)
        game_infos->robots_game[index].cycle_remaining -= 1;
}

void manage_instructions(game_infos_t *game_infos)
{
    int temp_cycle = 0;
    int instr_id = 0;

    for (unsigned int index = 0; index < game_infos->nb_robots; index++) {
        temp_cycle = game_infos->robots_game[index].cycle_remaining;
        instr_id = get_id_instr(game_infos, index);
        if (instr_id == -1 && temp_cycle == -1)
            continue;
        manage_cycles(game_infos, index, temp_cycle, instr_id);
    }
    return;
}

bool check_robots_alive(game_infos_t *game_infos)
{
    unsigned int nb_robots_alive = 0;

    for (unsigned int index_robot = 0; index_robot < game_infos->nb_robots;
        index_robot++) {
        if (game_infos->robots_game[index_robot].is_alive &&
            game_infos->robots_game[index_robot].has_said_alive)
            nb_robots_alive += 1;
        else
            game_infos->robots_game[index_robot].is_alive = false;
        game_infos->robots_game[index_robot].has_said_alive = false;
    }
    game_infos->cycle_infos.cycle_to_die = CYCLE_TO_DIE -
        CYCLE_DELTA * game_infos->nbr_live_exec % NBR_LIVE;
    if (nb_robots_alive <= 1)
        return 1;
    return 0;
}

void game_loop(game_infos_t *game_infos)
{
    if (game_infos->cycle_infos.cycle_to_die == 0)
        if (check_robots_alive(game_infos) == 1)
            return;
    if (game_infos->ncurse_active) {
        clear();
        print_arena(game_infos, game_infos->ncurse_active);
        timeout(game_infos->ncurse_timer);
    }
    manage_instructions(game_infos);
    if (game_infos->cycle_infos.cycle_nb == game_infos->cycle_infos.dump_cycle)
        print_arena(game_infos, 0);
    game_infos->cycle_infos.cycle_nb += 1;
    game_infos->cycle_infos.cycle_to_die -= 1;
    if ((game_infos->ncurse_active && getch() != 'q') ||
        !game_infos->ncurse_active)
        game_loop(game_infos);
}
