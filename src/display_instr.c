/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include <unistd.h>
#include "utils.h"

int display_instr(void)
{
    char *message = "USAGE\n"
        "./corewar [-dump nbr_cycle] [[-n prog_number]"
        "[-a load_address] prog_name] ...\n"
        "DESCRIPTION\n"
        "-dump nbr_cycle dumps the state of the virtual machine"
        " after the nbr_cycle execution\n"
        "-n prog_number sets the next program's number."
        "By default, the first free number in the parameter order\n"
        "-a load_address sets the next program's loading address."
        " When no address is specified,"
        " optimize the addresses so that the processes are as far"
        " away from each other as possible."
        " The addresses are MEM_SIZE modulo.";

    write(1, message, my_strlen(message));
    return 0;
}
