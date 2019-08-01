/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#include "my.h"

bool my_str_isnum(char *str)
{
    unsigned int i = 0;

    if (str == NULL)
        return (false);
    if (str[0] == '\0')
        return (false);
    if ((str[0] == '-' || str[0] == '+') && (str[1] < '0' || str[1] > '0'))
        return (false);
    if (str[0] == '-' || str[0] == '+')
        i += 1;
    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}
