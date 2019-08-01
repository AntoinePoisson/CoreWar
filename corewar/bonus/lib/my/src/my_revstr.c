/*
** EPITECH PROJECT, 2018
** my revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int index = 0;
    int end = 0;
    char tempor = '\0';

    if (!str || !str[0])
        return (str);
    for (; str[end + 1]; end++);
    while (index < end) {
        tempor = str[end];
        str[end] = str[index];
        str[index] = tempor;
        index++;
        end--;
    }
    return (str);
}
