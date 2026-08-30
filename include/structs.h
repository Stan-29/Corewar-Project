/*
** EPITECH PROJECT, 2025
** asm
** File description:
** Header for the operations
*/
#include "defines.h"

#ifndef OP_H_
    #define OP_H_

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

typedef struct robot_s {
    header_t header;
    int dump;
    int prog_nb;
    int load_adress;
    char *instr_list;
} robot_t;

typedef struct flags_s {
    char *flag;
    unsigned int (*flag_func)(char *, robot_t *);
} flags_t;

#endif /* OP_H_ */
