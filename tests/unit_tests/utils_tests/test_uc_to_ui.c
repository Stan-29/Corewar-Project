/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** test_is_positive_nb
*/
#include "utils.h"
#include <criterion/criterion.h>

Test(uc_to_ui, zero)
{
    unsigned char tab[4] = {0, 0, 0, 0};

    cr_assert(uc_to_ui(tab, 4) == 0);
}

Test(uc_to_ui, basic_number)
{
    unsigned char tab[4] = {0, 0, 0, 22};

    cr_assert(uc_to_ui(tab, 4) == 22);
}

Test(uc_to_ui, two_char_number)
{
    unsigned char tab[4] = {0, 0, 16, 22};

    cr_assert(uc_to_ui(tab, 4) == 4118);
}

Test(uc_to_ui, complex_number)
{
    unsigned char tab[4] = {16, 1, 16, 22};

    cr_assert(uc_to_ui(tab, 4) == 268505110);
}