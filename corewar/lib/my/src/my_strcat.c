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

char *my_strcat(char *dest, char *src)
{
    char *result = NULL;
    int i = 0;
    int a = 0;

    for (a = 0; dest != NULL && dest[a] != '\0'; a++);
    for (i = 0; src != NULL && src[i] != '\0'; a++, i++);
    if ((result = my_malloc(sizeof(char) * (a + 3), 0)) == NULL)
        return (NULL);
    if (dest != NULL)
        for (i = 0; dest[i] != '\0'; i++)
            result[i] = dest[i];
    if (src != NULL)
        for (a = 0; src[a] != '\0'; a++, i++)
            result[i] = src[a];
    result[i] = '\0';
    return (result);
}
