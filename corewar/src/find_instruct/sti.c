/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** init arena with all the instruction
*/

#include "corewar.h"

char **read_sti(char *map, int *new_posi, int instruct)
{
    char *coding_byte = NULL;
    char **result = create_tab_two(5);

    coding_byte = char_to_binary_str(read_coding_byte(map, new_posi));
    if (coding_byte == NULL)
        my_exit(my_puterror("Failure Malloc.\n"));
    result[0] = my_itoa(instruct);
    result[1] = read_char(map, new_posi, 1);
    if (coding_byte[2] == '0' && coding_byte[3] == '1')
        result[2] = read_char(map, new_posi, 1);
    else
        result[2] = read_short(map, new_posi);
    if (coding_byte[4] == '0' && coding_byte[5] == '1')
        result[3] = read_char(map, new_posi, 1);
    else
        result[3] = read_short(map, new_posi);
    my_free(coding_byte);
    return (result);
}