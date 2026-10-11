/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** instructions infos
*/
#include "instr.h"
#include "defines.h"
#include "structs.h"
#include <unistd.h>

const op_t op_tab[] = {
    {"none", 0, {0}, 0, 1, "Nothing", NULL, false, false, false},
    {"live", 1, {DIR_SIZE}, 1, 10,
        "alive", &live_func, false, false, false},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5,
        "load", &load_func, true, false, false},
    {"st", 2, {T_REG, T_REG | T_IND}, 3, 5,
        "store", &store_func, true, false, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10,
        "addition", &add_func, true, false, false},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10,
        "subtraction", &sub_func, true, false, false},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 6,
        "binary and (and  r1, r2, r3   r1&r2 -> r3",
        &and_func, true, false, false},
    {"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 7, 6,
        "binary or  (or   r1, r2, r3   r1 | r2 -> r3",
        &or_func, true, false, false},
    {"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 8, 6,
        "binary exclusive or (xor  r1, r2, r3   r1^r2 -> r3",
        &xor_func, true, false, false},
    {"zjmp", 1, {T_DIR}, 9, 20,
        "jump if zero", &zjump_func, false, true, true},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 10, 25,
        "load indirect", &load_ind_func, true, true, true},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR }, 11, 25,
        "store indirect", &store_ind_func, true, true, true},
    {"fork", 1, {T_DIR}, 12, 800,
        "fork", &pending_func, false, true, true},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10,
        "long load", &pending_func, true, false, false},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 14, 50,
        "long load indirect", &live_func, true, true, true},
    {"lfork", 1, {T_DIR}, 15, 1000,
        "long fork", &pending_func, false, true, true},
    {"print", 1, {T_REG}, 16, 2,
        "print character", &print_func, true, false, false},
    {0, 0, {0}, 0, 0, 0, 0, 0, 0, 0}
};
