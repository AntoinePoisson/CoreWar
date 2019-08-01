/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** tools for operation
*/

#include "corewar.h"

int register_or_not(char *str)
{
    char *rev = NULL;

    if (str == NULL)
        return (0);
    rev = my_strdup(str);
    rev = my_revstr(rev);
    if (rev && rev[0] == 'r') {
        my_free(rev);
        return (1);
    }
    my_free(rev);
    return (0);
}

bool check_only_register(char *str)
{
    int number = 0;

    if (str == NULL)
        return (false);
    if (str[0] == '\0')
        return (false);
    if (register_or_not(str)) {
        number = my_atoi(str);
        if (number < 1 || number > 16)
            return (false);
        else
            return (true);
    } else
        return (false);
}

bool check_only_number(char *str)
{
    if (str == NULL)
        return (false);
    if (str[0] == '\0')
        return (false);
    if (register_or_not(str))
        return (false);
    else
        return (true);
}

bool check_number_or_register(char *str)
{
    if (str == NULL)
        return (false);
    if (str[0] == '\0')
        return (false);
    if (check_only_register(str) || check_only_number(str))
        return (true);
    else
        return (false);
}
