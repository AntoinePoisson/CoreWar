/*
** EPITECH PROJECT, 2019
** lib
** File description:
** misnum.c
*/

int my_isnum(char const *s)
{
    int i = 0;

    i += (s[0] == '-') ? 1 : 0;
    for (; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return (-1);
    return (0);
}
