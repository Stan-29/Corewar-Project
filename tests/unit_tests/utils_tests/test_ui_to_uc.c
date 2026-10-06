/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_is_positive_nb
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(ui_to_uc, zero)
{
    unsigned int value = 0;
    unsigned char *tab = NULL;

    tab = ui_to_uc(value, 4);
    cr_assert(tab[0] == 0);
    cr_assert(tab[1] == 0);
    cr_assert(tab[2] == 0);
    cr_assert(tab[3] == 0);
}

Test(ui_to_uc, basic_number)
{
    unsigned int value = 22;
    unsigned char *tab = NULL;

    tab = ui_to_uc(value, 4);
    cr_assert(tab[0] == 0);
    cr_assert(tab[1] == 0);
    cr_assert(tab[2] == 0);
    cr_assert(tab[3] == 22);
}

Test(ui_to_uc, size_two_nbr)
{
    unsigned int value = 4118;
    unsigned char *tab = NULL;

    tab = ui_to_uc(value, 4);
    cr_assert(tab[0] == 0);
    cr_assert(tab[1] == 0);
    cr_assert(tab[2] == 16);
    cr_assert(tab[3] == 22);
}

Test(ui_to_uc, complex_number)
{
    unsigned int value = 268505110;
    unsigned char *tab = NULL;

    tab = ui_to_uc(value, 4);
    cr_assert(tab[0] == 16);
    cr_assert(tab[1] == 1);
    cr_assert(tab[2] == 16);
    cr_assert(tab[3] == 22);
}
