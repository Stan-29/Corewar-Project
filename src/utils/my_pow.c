/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** utils
*/

int my_pow(int value, int power)
{
    int result = 1;

    if (power == 0)
        return result;
    for (unsigned int index = 0; index < power; index++) {
        result = result * value;
    }
    return result;
}
