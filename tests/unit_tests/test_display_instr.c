/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_instr
*/
#include "main.h"
#include <criterion/criterion.h>

Test(display_instr, same_simple_str)
{
    cr_assert(display_instr() == 0);
}
