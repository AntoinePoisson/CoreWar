/*
** EPITECH PROJECT, 2019
** find_instruction.c
** File description:
** find_instruction
*/

#include "corewar.h"

int read_coding_byte(char *map, int *pc)
{
    int result = '\0';

    if (*pc >= MEM_SIZE)
        *pc = 0;
    result = map[*pc];
    *pc += 1;
    if (*pc >= MEM_SIZE)
        *pc = 0;
    return (result);
}

char **interpret_coding_byte(char *map, int *new_posi, int instruct)
{
    char *coding_byte = NULL;
    char **result = create_tab_two(6);
    int count = 1;

    result[0] = my_itoa(instruct);
    if (!(coding_byte = char_to_binary_str(read_coding_byte(map, new_posi)))
        || !result)
        return (NULL);
    for (int i = 0; coding_byte[i]; i += 2, count += 1) {
        if (coding_byte[i] == '0' && coding_byte[i + 1] == '1')
            result[count] = read_char(map, new_posi, 1);
        if (coding_byte[i] == '1' && coding_byte[i + 1] == '0')
            result[count] = read_int(map, new_posi);
        if (coding_byte[i] == '1' && coding_byte[i + 1] == '1')
            result[count] = read_short(map, new_posi);
    }
    return (result);
}

char *read_char(char *map, int *pc, int cas)
{
    char *result = NULL;
    char *two = NULL;

    if (*pc >= MEM_SIZE)
        *pc = 0;
    result = my_itoa(map[*pc]);
    if (my_atoi(result) == 0) {
        my_free(result);
        result = my_strdup("2");
    }
    *pc += 1;
    if (*pc >= MEM_SIZE)
        *pc = 0;
    if (cas == 1) {
        two = my_strcat(result, "r");
        my_free(result);
        return (two);
    }
    return (result);
}

char *reword_neg_read_short(char *result)
{
    char *final_result = NULL;

    final_result = my_itoa(char_to_short(result[0], result[1]));
    my_free(result);
    return (final_result);
}

char *read_short(char *map, int *pc)
{
    char *result = my_malloc(sizeof(char) * (3 + 1), 1);

    if (result == NULL)
        my_exit(my_puterror("Failure Malloc.\n"));
    if (*pc >= MEM_SIZE)
        *pc = 0;
    result[0] = map[*pc];
    *pc += 1;
    if (*pc >= MEM_SIZE)
        *pc = 0;
    result[1] = map[*pc];
    *pc += 1;
    if (*pc >= MEM_SIZE)
        *pc = 0;
    return (reword_neg_read_short(result));
}