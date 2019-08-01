/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** D5, an recursive function, who can calcul power
*/

int my_compute_power_rec(int nb, int p)
{
    int i = 1;
    int a = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    for (i = 1; i != p; i = i + 1)
        nb = nb * a;
    return (nb);
}
