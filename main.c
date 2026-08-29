/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "main.h"

int main(int argc, char **argv)
{
    if (start_game(argc, argv) == ERROR)
        return ERROR;
    return OK;
}
