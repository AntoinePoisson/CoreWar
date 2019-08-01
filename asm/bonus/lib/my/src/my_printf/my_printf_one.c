/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** recreation of printf
*/

#include "my.h"
#include "my_printf.h"

void my_printf_str(va_list va)
{
    my_putstr(va_arg(va, char *));
}

void my_printf_char(va_list va)
{
    my_putchar(va_arg(va, int));
}

void my_printf_int(va_list va)
{
    my_put_nbr(va_arg(va, int));
}
