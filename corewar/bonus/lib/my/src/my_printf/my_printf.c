/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** recreation of printf
*/

#include "my.h"
#include "my_printf.h"

int check_char_present(char c, char const *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

int format_compute(const char *format, va_list va, int i)
{
    char *table_reference = "sdcx";
    void (*table[4])(va_list) = {my_printf_str, my_printf_int,
    my_printf_char, my_printf_hexa};

    if (check_char_present(format[i], table_reference) == -1)
        return (1);
    (*table[check_char_present(format[i], table_reference)])(va);
    return (1);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list va;

    va_start(va, format);
    for (; format[i] != '\0'; i += 1) {
        if ((format[i] == '%' && format[i + 1] == '%')) {
            my_putchar('%');
            i += 1;
        } else if (format[i] == '%' && format[i + 1] != '\0') {
            i += format_compute(format, va, i + 1);
        }
        else
            my_putchar(format[i]);
    }
    va_end(va);
    return (0);
}
