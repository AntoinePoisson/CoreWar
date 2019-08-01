/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return (0);
    }
    for (; str[i]; i++);
    if (i > 0)
        write(1, str, i);
    return (i);
}
