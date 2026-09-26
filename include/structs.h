/*
** EPITECH PROJECT, 2025
** asm
** File description:
** Header for the operations
*/

#ifndef OP_H_
    #define OP_H_

    #include <stdbool.h>
    #include "defines.h"

typedef char args_type_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    char padding[3];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
    char padding2[3];
} header_t;

typedef struct robot_args_s {
    header_t header;
    int dump;
    int ncurse_active;
    int prog_nb;
    int load_adress;
    unsigned char *instr_list;
    unsigned int len_instr;
} robot_args_t;

typedef struct robot_game_s {
    unsigned int cycle_remaining;
    bool has_said_alive;
    bool is_alive;
    int *reg;
    unsigned int pc;
    bool carry;
    unsigned int color_index;
} robot_game_t;

typedef struct cycle_infos_s {
    int dump_cycle;
    unsigned int cycle_to_die;
    unsigned int cycle_nb;
} cycle_infos_t;

typedef struct game_info_s {
    robot_args_t *robots_args;
    robot_game_t *robots_game;
    unsigned int nb_robots;
    cycle_infos_t cycle_infos;
    bool ncurse_active;
    int ncurse_timer;
    unsigned int nbr_live_exec;
    unsigned int last_to_live;
    unsigned char *arena;
    unsigned int *index_colors;
} game_infos_t;

typedef struct flags_s {
    char *flag;
    unsigned int (*flag_func)(int, robot_args_t *);
} flags_t;

#endif /* OP_H_ */
