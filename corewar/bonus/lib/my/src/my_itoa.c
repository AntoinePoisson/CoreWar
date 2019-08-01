/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** my_itoa
*/

#include "my.h"

int my_intlen(int nb)
{
    int i = 0;

    if (!nb)
        return (1);
    if (nb < 0)
        i += 1;
    for (; nb; nb /= 10, i++);
    return (i);
}

char *my_zero(char *str)
{
    str[0] = '0';
    str[1] = '\0';
    return (str);
}

char *my_itoa(long nb)
{
    char *str = my_malloc(sizeof(char) * (my_intlen(nb) + 1), 0);
    int i = 0;
    int neg = (nb < 0) ? 1 : 0;

    nb *= (nb < 0) ? -1 : 1;
    if (!nb)
        return (my_zero(str));
    for (; nb; nb /= 10, i++) {
        str[i] = nb % 10 + '0';
        str[i + 1] = '\0';
    }
    if (neg) {
        str[i] = '-';
        str[i + 1] = '\0';
    }
    return (my_revstr(str));
}
