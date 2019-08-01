/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tool of ASM
*/

#include "op.h"
#include "asm.h"

int find_type_of_arg(char const *arg, int instruct)
{
    if (arg[0] == 'r')
        return (1);
    if (arg[0] == DIRECT_CHAR) {
        if (instruct != 11 && instruct != 12 && instruct != 10 &&
            instruct != 14 && instruct != 15 && instruct != 9)
            return (4);
    }
    return (2);
}

char **free_tab_two(char **str)
{
    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        my_free(str[i]);
    my_free(str);
    str = NULL;
    return (str);
}

char *convert_dec_to_hexa(int nbr)
{
    char *new = my_malloc(sizeof(char) * 256, 1);
    int t = nbr;
    int i = 0;
    int c = 0;

    for (i = t, c = 0, t %= 16; i > 0; i /= 16, t %= 16, t = i, c++)
        if (t <= 9)
            new[c] = t + '0';
        else
            new[c] = t + 55;
    return (my_revstr(new));
}

char **tab_realloc(char **tab)
{
    char **tmp = NULL;
    int i = 0;

    for (; tab[i]; i++);
    tmp = my_malloc(sizeof(char *) * (i + 2), 2);
    if (tmp == NULL)
        exit(84);
    for (i = 0; tab[i]; i++)
        tmp[i] = tab[i];
    my_free(tab);
    return (tmp);
}
