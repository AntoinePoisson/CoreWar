/*
** EPITECH PROJECT, 2018
** my put nbr
** File description:
** print any number
*/

#include "my.h"

void print_nb(long nb)
{
    char nbr = '\0';

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    } if (nb > 0) {
        nbr = nb % 10 + '0';
        print_nb(nb / 10);
        my_putchar(nbr);
    }
}

void my_put_nbr(long nb)
{
    if (nb != 0)
        print_nb(nb);
    else
        my_putchar('0');
}
