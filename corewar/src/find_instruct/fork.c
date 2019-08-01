/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** init arena with all the instruction
*/

#include "corewar.h"

char **read_fork(char *map, int *new_posi, int instruct)
{
    char **result = create_tab_two(3);

    result[0] = my_itoa(instruct);
    result[1] = read_short(map, new_posi);
    return (result);
}