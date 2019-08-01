/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"

int my_strncpy(char *dest, char const *src, int const nb)
{
    int i = 0;

    if (!src || !dest || nb < 1)
        return (0);
    for (; src[i] && (i < nb); dest[i] = src[i], i++);
    dest[i] = '\0';
    return (i);
}

int my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src || !dest)
        return (0);
    for (; src[i]; dest[i] = src[i], i++);
    dest[i] = '\0';
    return (i);
}
