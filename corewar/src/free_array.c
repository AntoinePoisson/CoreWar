/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** free an double array
*/

#include "corewar.h"

void free_array(char **tab)
{
    for (int i = 0; tab && tab[i]; i++)
        my_free(tab[i]);
    my_free(tab);
}
