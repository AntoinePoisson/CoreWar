/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    long nb = 0;
    int i = 0;
    int neg = 1;

    if (!str || !str[0])
        return (0);
    if (str[0] == '-')
        neg = -1;
    if (str[0] == '+' || str[0] == '-')
        i += 1;
    for (; str[i]; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    nb *= neg;
    return (nb);
}
