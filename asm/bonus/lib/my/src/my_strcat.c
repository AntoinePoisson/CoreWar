/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = 0;
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; dest[size]; size++);
    for (i = 0; i < nb && src[i]; i++)
        dest[size + i] = src[i];
    dest[size + i] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int size = 0;
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; dest[size]; size++);
    for (i = 0; src[i]; i++)
        dest[size + i] = src[i];
    dest[size + i] = '\0';
    return (dest);
}
