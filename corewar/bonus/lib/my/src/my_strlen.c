/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (; str[i]; i++);
    return (i);
}
