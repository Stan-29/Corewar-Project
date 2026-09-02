/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_display_error
*/
#include <criterion/criterion.h>
#include "utils.h"

Test(display_error, normal_tab)
{
    const char *tab[] = {"one", "two", NULL};

    cr_assert(my_tablen(tab) == 2);
}

Test(display_error, empty_tab)
{
    const char *tab[] = {NULL};

    cr_assert(my_tablen(tab) == 0);
}

Test(display_error, null_tab)
{
    cr_assert(my_tablen(NULL) == 0);
}