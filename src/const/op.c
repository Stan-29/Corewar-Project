/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** instructions infos
*/
#include "main.h"
#include "defines.h"
#include "structs.h"
#include <unistd.h>

const op_t op_tab[] = {
    {"none", 0, {0}, 0, 1, "Nothing", NULL},
    {"live", 1, {T_DIR}, 1, 10, "alive", &live_func},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &live_func},
    {"st", 2, {T_REG, T_REG | T_IND}, 3, 5, "store", &live_func},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &live_func},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "subtraction", &live_func},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 6,
        "binary and (and  r1, r2, r3   r1&r2 -> r3", &live_func},
    {"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 7, 6,
        "binary or  (or   r1, r2, r3   r1 | r2 -> r3", &live_func},
    {"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 8, 6,
        "binary exclusive or (xor  r1, r2, r3   r1^r2 -> r3", &live_func},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &live_func},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 10, 25,
        "load indirect", &live_func},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR }, 11, 25,
        "store indirect", &live_func},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &live_func},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &live_func},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 14, 50,
        "long load indirect", &live_func},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &live_func},
    {"print", 1, {T_REG}, 16, 2, "print character", &live_func},
    {0, 0, {0}, 0, 0, 0}
};
