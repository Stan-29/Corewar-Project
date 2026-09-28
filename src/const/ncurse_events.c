/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** ncurse_events
*/
#include "defines.h"
#include "structs.h"
#include "main.h"
#include <unistd.h>

const ncurse_event_t ncurse_events[] = {
    {PAUSE_START_EVENT, &pause_start_ncurse},
    {NEXT_CYCLE_EVENT, &next_cycle_ncurse},
    {EXIT_EVENT, &exit_event_ncurse},
    {SPEED_DOWN_EVENT, &speed_down_ncurse},
    {SPEED_UP_EVENT, &speed_up_ncurse},
    {END_EVENT_CODE, NULL}
};
