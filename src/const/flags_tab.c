/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** flags infos
*/
#include "defines.h"
#include "structs.h"
#include "main.h"
#include <unistd.h>

const flags_t flags_tab[] = {
    {DUMP_FLAG, &dump_flag},
    {LOAD_ADRESS_FLAG, &load_flag},
    {PROG_NB_FLAG, &prog_nb_flag},
    {NULL, NULL}
};
