/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int const n)
{
    int a = 0;

    while (a < n && s1[a] == s2[a] && s1[a] && s2[a])
        a += 1;
    return (s1[a] - s2[a]);
}

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] && s2[a])
        a += 1;
    return (s1[a] - s2[a]);
}
