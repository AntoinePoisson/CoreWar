/*
** EPITECH PROJECT, 2018
** my_str_to_selec_array
** File description:
** my_str_to_selec_array
*/

#include "my.h"
#include <stdlib.h>

static int f(char const *str, char element)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; (str[i] == ' ' && str[i] != '\0') ||
        (str[i] == '\t' && str[i] != '\0') ||
        (str[i] == element && str[i] != '\0'); i++) {
    }
    return (i);
}

static char *my_strcpy_sele(char *dest, char const *src, int start, int limit)
{
    int i = 0;

    for (; i != limit; i++, start++)
        dest[i] = src[start];
    dest[i] = '\0';
    dest[i + 1] = '\0';
    return (dest);
}

static int word_count_(char const *str, char element)
{
    int count = 1;

    if (str == NULL)
        return (1);
    for (int i = f(str, element); str[i] != '\0'; i++)
        if ((str[i] == ' ' && str[i + 1] != ' ') ||
            (str[i] == '\t' && str[i + 1] != '\t') ||
            (str[i] == element && str[i + 1] != element))
            count++;
    return (count);
}

char **my_str_to_selec_array(char const *str, char e)
{
    char **array = my_malloc(sizeof(char *) * (word_count_(str, e) + 1), 0);
    int a = 0;
    int length = 0;
    int start = f(str, e);

    if (str == NULL) {
        my_free(array);
        return (NULL);
    }
    for (int i = f(str, e); str[i] != '\0'; a++, length = 0, start = i) {
        for (; str[i] != ' ' && str[i] && str[i] != e && str[i] != '\t'; i++)
            length++;
        if ((array[a] = my_malloc(sizeof(char) * (length + 2), 0)) == NULL)
            return (NULL);
        my_strcpy_sele(array[a], str, start, length);
        for (; (str[i] == ' ' && str[i]) || (str[i] == e &&
            str[i]) || (str[i] == '\t' && str[i]); i++);
    }
    array[a] = NULL;
    return (array);
}
