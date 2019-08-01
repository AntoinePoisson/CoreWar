/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

char *char_to_binary_str(unsigned char c)
{
    char *str = my_malloc(sizeof(char) * 9, 0);

    if (str == NULL)
        my_exit(my_puterror("Faileure Malloc.\n"));
    for (short i = 0; i < 8; str[i] = '0', i++);
    str[8] = '\0';
    for (short i = 7; i >= 0; i--) {
        str[i] = c % 2 + '0';
        c = c >> 1;
    }
    return (str);
}

short char_to_short(char one, char two)
{
    short result = 0x0000;

    result |= one;
    result = result << 8;
    result |= two;
    return (result);
}

int char_to_int(char one, char two, char three, char four)
{
    int result = 0x00000000;

    result |= one;
    result = result << 8;
    result |= two;
    result = result << 8;
    result |= three;
    result = result << 8;
    result |= four;
    return (result);
}
