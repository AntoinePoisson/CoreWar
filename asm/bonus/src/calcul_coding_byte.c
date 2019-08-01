/*
** EPITECH PROJECT, 2019
** calcul_coding_bye.c
** File description:
** calcul_coding_bye
*/

#include "op.h"
#include "asm.h"

int check_register_(char const *regist)
{
    if (my_strlen(regist) > 3 || my_strlen(regist) <= 1)
        return (0);
    if (regist[0] != 'r')
        return (0);
    for (int i = 1; regist[i]; i++)
        if (!(regist[i] >= '0' && regist[i] <= '9'))
            return (0);
    return (1);
}

int check_direct_(char const *direct)
{
    if (my_strlen(direct) <= 1)
        return (0);
    if (direct[0] != DIRECT_CHAR)
        return (0);
    if (direct[1] == LABEL_CHAR)
        return (1);
    if ((direct[1] >= '0' && direct[1] <= '9') || (direct[1] == '-'))
        return (1);
    return (0);
}

static char *find_good_parameter(char const *para, int *i_two, char *result)
{
    if (check_register_(para)) {
        result[*i_two] = '0';
        result[*i_two + 1] = '1';
        *i_two += 2;
    }
    else if (check_direct_(para)) {
        result[*i_two] = '1';
        result[*i_two + 1] = '0';
        *i_two += 2;
    } else {
        result[*i_two] = '1';
        result[*i_two + 1] = '1';
        *i_two += 2;
    }
    return (result);
}

static char decalage_bytes(char bit, int i)
{
    char add = 0x01;

    bit |= (add << i);
    return (bit);
}

char calcul_coding_byte(char **arg)
{
    char **para = arg;
    char *result = my_malloc(sizeof(char) * 10, 1);
    char bit = 0x00;
    int i = 0;
    int count = 0;

    for (i = 0; i < 8; result[i] = '0', i++);
    for (i = 0; para[i]; i++)
        result = find_good_parameter(para[i], &count, result);
    for (i = my_strlen(result) - 1, count = 0; i >= 0; i--, count++)
        if (result[i] == '1')
            bit = decalage_bytes(bit, count);
    my_free(result);
    return (bit);
}
