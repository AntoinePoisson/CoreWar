/*
** EPITECH PROJECT, 2019
** my_puterror
** File description:
** my_puterror
*/

#include "my.h"

int my_puterror(char const *str)
{
    int i = 0;

    if (str == NULL) {
        my_puterror("(null)");
        return (0);
    }
    for (; str[i]; i++);
    if (i > 0)
        write(2, str, sizeof(char) * i);
    return (84);
}
