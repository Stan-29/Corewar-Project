/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/

unsigned int uc_to_ui(unsigned char value[4], unsigned int size)
{
    unsigned int res = 0;

    for (unsigned int index = 0; index < size; index++)
        res += value[size - index - 1] << (index * 8);
    return res;
}
