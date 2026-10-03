/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_helper
*/
#include "main.h"
#include <criterion/criterion.h>

Test(display_helper, same_simple_str)
{
    cr_assert(display_helper() == 1);
}
