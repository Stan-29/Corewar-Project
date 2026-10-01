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
    {"live", 1, {T_REG}, 1, 10, "alive", &live_func, false},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &load_func, true},
    {"st", 2, {T_REG, T_REG | T_IND}, 3, 5, "store", &pending_func, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &pending_func, true},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "subtraction",
        &pending_func, true},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 6,
        "binary and (and  r1, r2, r3   r1&r2 -> r3", &pending_func, true},
    {"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 7, 6,
        "binary or  (or   r1, r2, r3   r1 | r2 -> r3", &pending_func, true},
    {"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 8, 6,
        "binary exclusive or (xor  r1, r2, r3   r1^r2 -> r3",
        &pending_func, true},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &pending_func, false},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 10, 25,
        "load indirect", &pending_func, true},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR }, 11, 25,
        "store indirect", &pending_func, true},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &pending_func, false},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load",
        &pending_func, true},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 14, 50,
        "long load indirect", &live_func, true},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &pending_func, false},
    {"print", 1, {T_REG}, 16, 2, "print character", &pending_func, true},
    {0, 0, {0}, 0, 0, 0}
};
