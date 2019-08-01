/*
** EPITECH PROJECT, 2019
** lib
** File description:
** mstrchr.c
*/

#include <stddef.h>

char *my_strchr(char *s, int c)
{
    int a = 0;

    for (a = 0; s[a] != c && s[a]; a++);
    return (s[a]) ? (&s[a]) : (NULL);
}
