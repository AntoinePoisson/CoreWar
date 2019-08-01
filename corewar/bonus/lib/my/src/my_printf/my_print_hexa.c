/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include "my.h"

void my_print_hexa_char(unsigned char c)
{
    char const *str = "0123456789ABCDEF";
    unsigned tmp = c;

    if (tmp >= 16) {
        tmp /= 16;
        my_putchar(str[tmp]);
    } else {
        my_putchar('0');
    }
    my_putchar(str[c % 16]);
}
