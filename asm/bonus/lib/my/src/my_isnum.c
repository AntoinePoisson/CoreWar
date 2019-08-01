/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_isnum.c
*/

int my_isnum(char const *s)
{
    int i = 0;

    i += (s[0] == '-') ? 1 : 0;
    for (; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return (84);
    return (0);
}
