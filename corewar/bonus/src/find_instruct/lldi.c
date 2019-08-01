/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** init arena with all the instruction
*/

#include "corewar.h"

char *is_extension_read_lldi(char *map, int *new_posi, char *coding_byte)
{
    char *one = NULL;
    char *two = NULL;

    if (coding_byte[0] == '0' && coding_byte[1] == '1')
        one = read_char(map, new_posi, 1);
    else {
        one = read_short(map, new_posi);
        if (coding_byte[0] == '1' && coding_byte[1] == '0') {
            two = my_strcat(one, "%");
            my_free(one);
            return (two);
        }
    }
    return (one);
}

char *is_extension_read_lldi_(char *map, int *new_posi, char *coding_byte)
{
    char *one = NULL;
    char *two = NULL;

    if (coding_byte[2] == '0' && coding_byte[3] == '1')
        one = read_char(map, new_posi, 1);
    else {
        one = read_short(map, new_posi);
        if (coding_byte[2] == '1' && coding_byte[3] == '0') {
            two = my_strcat(one, "%");
            my_free(one);
            return (two);
        }
    }
    return (one);
}

char **read_lldi(char *map, int *new_posi, int instruct)
{
    char **result = create_tab_two(5);
    char *coding_byte = NULL;

    coding_byte = char_to_binary_str(read_coding_byte(map, new_posi));
    if (coding_byte == NULL || result == NULL)
        my_exit(my_puterror("Failure Malloc.\n"));
    result[0] = my_itoa(instruct);
    result[1] = is_extension_read_lldi(map, new_posi, coding_byte);
    result[2] = is_extension_read_lldi_(map, new_posi, coding_byte);
    result[3] = read_char(map, new_posi, 1);
    my_free(coding_byte);
    return (result);
}