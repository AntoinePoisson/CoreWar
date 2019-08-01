/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_int_value.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "corewar.h"

int write_value(int value, char *mem, unsigned int index)
{
    int pos = ((index + 3) > MEM_SIZE) ? index + 3 - MEM_SIZE : index + 3;
    int sign = (value >= 0) ? P : N;

    if (value > 1020 || value < -1020)
        return (84);
    for (int b = 0; b ^ 4; b++) {
        mem[pos] = ((sign == P && value < 255) ||
        (sign == N && value > -255)) ? value : 255 * sign;
        value += (sign == N) ? 255 : -255;
        value = ((sign == P && value < 0) ||
        (sign == N && value > 0)) ? 0 : value;
        pos = ((pos - 1) < 0) ? MEM_SIZE - 1 : pos - 1;
    }
    return (0);
}
