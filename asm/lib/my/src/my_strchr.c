/*
** EPITECH PROJECT, 2019
** lib
** File description:
** mstrchr.c
*/

#include "my.h"

char *my_strchr(char *s, int c)
{
    int a;

    for (a = 0; s[a] != c && s[a]; a++);
    if (a > my_strlen(my_str_to_selec_array(s, ' ')[0]))
        return (s);
    return (s[a]) ? (&s[a + 1]) : (s);
}
