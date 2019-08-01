/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** libmy
*/

#include "my.h"

int my_tablen(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    for (; tab[i] != NULL; i++);
    return (i);
}
