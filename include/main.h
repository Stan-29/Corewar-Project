/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** main includes
*/
#include "structs.h"

#ifndef MAIN_H_
    #define MAIN_H_

    #include "defines.h"

unsigned int display_helper(void);
unsigned int start_game(int, char **);
void game_loop(game_infos_t *);
void kill_robot(game_infos_t *, unsigned int);
unsigned int check_robots_alive(game_infos_t *);
unsigned int get_size_infos(robot_game_t *, unsigned char);

//args
unsigned int handle_args(int, char **, robot_args_t *);
unsigned int handle_helper(int, char **);
unsigned int find_flag(char *, char *, robot_args_t *, unsigned int *);
unsigned int handle_flags(int, char **, robot_args_t *, unsigned int *);
unsigned int handle_file(char *, robot_args_t *, unsigned int *,
    unsigned int *);
unsigned int dump_flag(int, robot_args_t *);
unsigned int load_flag(int, robot_args_t *);
unsigned int prog_nb_flag(int, robot_args_t *);
unsigned int ncurse_flag(int, robot_args_t *);

//init
void reset_instr_args(robot_game_t *, unsigned int);
robot_args_t *init_robots(void);
unsigned int init_game_infos(robot_args_t *, game_infos_t *);

//free
void free_robot_args(robot_args_t *);
void free_game_infos(game_infos_t *);

//setup infos
unsigned int prepare_infos(robot_args_t *, game_infos_t **);
void manage_robots_id(robot_args_t *, unsigned int);
unsigned int manage_load_pos(robot_args_t *, unsigned int);

//dump
void print_arena(game_infos_t *, bool);
void print_header(robot_args_t *, robot_game_t *, bool);

//instr_func
void manage_robots(game_infos_t *);
void manage_cycles(game_infos_t *, unsigned int,
    unsigned int, unsigned int);
void get_instr_infos(robot_game_t *, unsigned char *, unsigned int);
void get_usable_args(robot_game_t *);
unsigned int pending_func(game_infos_t *, unsigned int);
unsigned int live_func(game_infos_t *, unsigned int);
unsigned int load_func(game_infos_t *, unsigned int);
unsigned int zjump_func(game_infos_t *, unsigned int);
unsigned int print_func(game_infos_t *, unsigned int);
unsigned int store_ind(game_infos_t *, unsigned int);
unsigned int store_func(game_infos_t *, unsigned int);
unsigned int add_func(game_infos_t *, unsigned int);

//ncurse
void init_ncurse(game_infos_t *);
void print_dashboard(game_infos_t *);
unsigned int get_ncurse_events(game_infos_t *);
void manage_ncurse(game_infos_t *);
unsigned int exit_event_ncurse(game_infos_t *);
unsigned int pause_start_ncurse(game_infos_t *);
unsigned int next_cycle_ncurse(game_infos_t *);
unsigned int speed_up_ncurse(game_infos_t *);
unsigned int speed_down_ncurse(game_infos_t *);

#endif
