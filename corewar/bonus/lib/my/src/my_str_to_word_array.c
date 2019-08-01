/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

int check_char_str(char c, char const *delimiter)
{
    int is_present = 0;

    for (int i = 0; *(delimiter + i); i++) {
        if (*(delimiter + i) == c)
            is_present = 1;
    }
    return (is_present);
}

void fill_word(char const *str, char **tmp, char const *delimiter)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (*(str + i)) {
        j = 0;
        while (*(str + i) && check_char_str(*(str + i), delimiter))
            i++;
        tmp[count][j] = '\0';
        while (str[i] && check_char_str(*(str + i), delimiter) == 0) {
            tmp[count][j] = *(str + i);
            tmp[count][j + 1] = '\0';
            i += 1;
            j += 1;
        }
        while (*(str + i) && check_char_str(*(str + i), delimiter))
            i++;
        count += 1;
    }
}

void malloc_word(char const *str, char **tmp, char const *delimiter)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (*(str + i)) {
        j = 0;
        while (str[i] && check_char_str(str[i], delimiter))
            i++;
        while (str[i] && check_char_str(str[i], delimiter) == 0) {
            i++;
            j++;
        }
        tmp[count] = my_malloc(sizeof(char) * (j + 1), 0);
        while (str[i] && check_char_str(str[i], delimiter))
            i++;
        count += 1;
    }
}

int count_word(char const *str, char const *delimiter)
{
    int count = 0;
    int i = 0;
    int find = 0;

    if (str == NULL)
        return (0);
    while (str[i]) {
        while (str[i] && check_char_str(str[i], delimiter))
            i++;
        while (str[i] && check_char_str(str[i], delimiter) == 0) {
            i++;
            find += 1;
        }
        while (str[i] && check_char_str(str[i], delimiter))
            i++;
        count = (find) ? count + 1 : 0;
    }
    return (count);
}

char **my_str_to_word_array(char const *str, char const *delimiter)
{
    char **tmp = NULL;
    int count = count_word(str, delimiter);

    if (count == 0) {
        tmp = my_malloc(sizeof(char *) * 1, 0);
        tmp[0] = NULL;
        return (tmp);
    }
    tmp = my_malloc(sizeof(char *) * (count + 1), 0);
    tmp[count] = NULL;
    malloc_word(str, tmp, delimiter);
    fill_word(str, tmp, delimiter);
    return (tmp);
}
