/*
** EPITECH PROJECT, 2019
** management_tab.c
** File description:
** management_tab.c
*/

#include "asm.h"

static bool check_useless_charac(char const *str)
{
    int i = 0;

    if (!str)
        return (false);
    for (; (str[i] && str[i] == ' ') || (str[i] == '\t' && str[i]); i++) {
    }
    if (str[i] == COMMENT_CHAR || str[i] == '\0')
        return (true);
    return (false);
}

static char **rework_tab(char **tab, int *i)
{
    for (int a = *i; tab[a]; a++) {
        if (a == *i)
            my_free(tab[a]);
        tab[a] = tab[a + 1];
    }
    *i -= 1;
    return (tab);
}

static bool check_rework_end_of_line(char const *str)
{
    for (int i = 0; str && str[i]; i++)
        if (str[i] == COMMENT_CHAR)
            return (true);
    return (false);
}

static char *rework_end_of_line(char *str)
{
    int i = 0;
    char *cpy = my_strdup(str);

    if (cpy == NULL)
        exit(my_puterror("Failure Malloc.\n"));
    for (i = 0; str && str[i] && str[i] != COMMENT_CHAR; i++);
    if (!str || str[i] != COMMENT_CHAR || str[i] == '\0')
        return (str);
    for (; cpy[i]; i++)
        str[i] = '\0';
    my_free(cpy);
    return (str);
}

char **management_tab(char **tab)
{
    if (tab == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        if (check_useless_charac(tab[i]))
            tab = rework_tab(tab, &i);
        if (i >= 0 && check_rework_end_of_line(tab[i]))
            tab[i] = rework_end_of_line(tab[i]);
    }
    return (tab);
}
