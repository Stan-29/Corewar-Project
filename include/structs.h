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
    int prog_nb;
    int load_adress;
    unsigned char *instr_list;
    unsigned int len_instr_list;
} robot_args_t;

typedef struct robot_game_s {
    unsigned int cycle_remaining;
    bool has_said_alive;
    bool is_alive;
    unsigned char *reg;
    unsigned int pc;
    bool carry;
} robot_game_t;

typedef struct game_info_s {
    robot_args_t *robots_args;
    robot_game_t *robots_game;
    unsigned int nb_robots;
    unsigned int cycle_nb;
    unsigned char *arena;
    int dump;
} game_infos_t;

typedef struct flags_s {
    char *flag;
    unsigned int (*flag_func)(char *, robot_args_t *);
} flags_t;

#endif /* OP_H_ */
