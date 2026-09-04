/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main function
*/
#include "defines.h"
#include "main.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned int get_nb_robots_to_place(robot_args_t *robots,
    unsigned int nb_robots)
{
    unsigned int nb_robots_placed = 0;

    for (unsigned int index = 0; index < nb_robots; index++)
        if (robots[index].load_adress != -1)
            nb_robots_placed += 1;
    return nb_robots - nb_robots_placed;
}

static void free_gap_list(int **gap_list, unsigned int nb_of_gaps)
{
    if (gap_list == NULL)
        return;
    for (unsigned int index = 0; index < nb_of_gaps; index++)
        free(gap_list[index]);
    free(gap_list);
}

static unsigned int init_gap_list(int ***gap_list, unsigned int nb_of_gaps)
{
    if ((*gap_list) == NULL)
        return ERROR;
    for (unsigned int index = 0; index < nb_of_gaps; index++) {
        (*gap_list)[index] = malloc(sizeof(int) * 3);
        if ((*gap_list)[index] == NULL)
            return ERROR;
        (*gap_list)[index][0] = -1;
        (*gap_list)[index][1] = -1;
        (*gap_list)[index][2] = -1;
    }
    return OK;
}

void fill_size_gaps(robot_args_t *robots, int **gap_list,
    unsigned int nb_of_gaps)
{
    unsigned int next_gap = 0;

    for (unsigned int index = 0; index < nb_of_gaps; index++) {
        for (unsigned int index2 = 0; index2 < nb_of_gaps; index2++) {
            next_gap = gap_list[index2][1] - gap_list[index][1] -
                robots[gap_list[index][0]].len_instr;
            gap_list[index][2] = (gap_list[index2][1] > gap_list[index][1] &&
                gap_list[index][2] > next_gap) ? next_gap : gap_list[index][2];
        }
        if (gap_list[index][2] != -1)
            continue;
        gap_list[index][2] = MEM_SIZE - robots[gap_list[index][0]].len_instr;
        for (unsigned int index2 = 0; index2 < nb_of_gaps;
            index2++) {
            next_gap = MEM_SIZE - gap_list[index][1] -
                robots[gap_list[index][0]].len_instr + gap_list[index2][1];
            gap_list[index][2] = (gap_list[index][2] > next_gap) ?
                next_gap : gap_list[index][2];
        }
    }
}

int **fill_gap_list(robot_args_t *robots, unsigned int nb_robots,
    unsigned int left_to_place)
{
    unsigned int nb_of_gaps = nb_robots - left_to_place;
    unsigned int index_list = 0;
    int **gap_list = NULL;

    gap_list = malloc(sizeof(int *) * nb_of_gaps);
    if (init_gap_list(&gap_list, nb_of_gaps) == ERROR)
        return NULL;
    for (unsigned int index = 0; index < nb_robots; index++) {
        if (robots[index].load_adress != -1) {
            gap_list[index_list][1] = robots[index].load_adress;
            gap_list[index_list][0] = index;
            index_list += 1;
        }
    }
    fill_size_gaps(robots, gap_list, nb_of_gaps);
    return gap_list;
}

static void add_load_pos(robot_args_t *robots, int **gap_list,
    unsigned int nb_of_gaps, unsigned int index_robot)
{
    unsigned int max_gap_id = 0;

    for (unsigned int index = 0; index < nb_of_gaps; index++) {
        if (gap_list[index][2] > max_gap_id)
            max_gap_id = index;
    }
    robots[index_robot].load_adress = gap_list[max_gap_id][1] +
        robots[gap_list[max_gap_id][0]].len_instr + (gap_list[max_gap_id]
        [2] / 2 - robots[index_robot].len_instr / 2) % MEM_SIZE;
}

unsigned int find_best_place(robot_args_t *robots, unsigned int nb_robots,
    unsigned int left_to_place, unsigned int index_robot)
{
    int **gap_list = NULL;

    if (nb_robots == left_to_place) {
        robots[0].load_adress = 0;
        left_to_place -= 1;
    }
    if (robots[index_robot].load_adress != -1 && left_to_place > 1 &&
        index_robot + 1 < nb_robots) {
        find_best_place(robots, nb_robots, left_to_place, index_robot + 1);
        return OK;
    }
    gap_list = fill_gap_list(robots, nb_robots, left_to_place);
    if (gap_list == NULL)
        return ERROR;
    add_load_pos(robots, gap_list, nb_robots - left_to_place, index_robot);
    free_gap_list(gap_list, nb_robots - left_to_place);
    if (left_to_place > 1 && index_robot + 1 < nb_robots)
        find_best_place(robots, nb_robots, left_to_place - 1, index_robot + 1);
    return OK;
}

unsigned int manage_load_pos(robot_args_t *robots, unsigned int nb_robots)
{
    unsigned int left_to_place = get_nb_robots_to_place(robots, nb_robots);

    if (left_to_place == 0)
        return OK;
    if (find_best_place(robots, nb_robots, left_to_place, 0) == ERROR)
        return ERROR;
    return OK;
}
