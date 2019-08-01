/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void print_map(char const *str)
{
    unsigned short i = 0;
    unsigned int j = 0;

    while (j < MEM_SIZE) {
        for (i = 0; i < 32; i++, j++) {
            my_printf((str[j]) ? "\033[1;33m" : "");
            my_printf("%c%x", (i == 0) ? '\0' : ' ', str[j]);
            my_printf("\033[0m");
        }
        my_printf("\n");
    }
    my_printf("\n");
}
