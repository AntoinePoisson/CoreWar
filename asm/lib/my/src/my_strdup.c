/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strndup(char const *str, int nb)
{
    int i = 0;
    char *tmp = NULL;

    if (!str || nb < 1)
        return (NULL);
    for (; str[i] && i < nb; i++);
    if ((tmp = my_malloc(sizeof(char) * (i + 1), 0)) == NULL)
        return (NULL);
    for (i = 0; str[i] && i < nb; tmp[i] = str[i], i++);
    tmp[i] = '\0';
    return (tmp);
}

char *my_strdup(char const *str)
{
    int i = 0;
    char *tmp = NULL;

    if (!str)
        return (NULL);
    for (; str[i]; i++);
    if ((tmp = my_malloc(sizeof(char) * (i + 1), 0)) == NULL)
        return (NULL);
    for (i = 0; str[i]; tmp[i] = str[i], i++);
    tmp[i] = '\0';
    return (tmp);
}
