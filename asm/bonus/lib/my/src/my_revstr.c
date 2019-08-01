/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** D6, function that reverses a string.
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    char str_rev[my_strlen(str)];

    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0'; i++);
    for (i = i - 1; i >= 0; i--) {
        str_rev[a] = str[i];
        a++;
    }
    str[a] = '\0';
    i = 0;
    for (i = 0; str[i] != '\0'; i++)
        str[i] = str_rev[i];
    return (str);
}
