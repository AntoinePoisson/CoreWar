/*
** EPITECH PROJECT, 2019
** find_instruction.c
** File description:
** find_instruction
*/

#include "corewar.h"

char *reword_neg_read_int(char *result)
{
    char *final_result = NULL;

    final_result = my_itoa(char_to_int(result[0], result[1], result[2],
        result[3]));
    my_free(result);
    return (final_result);
}

char *read_int(char *map, int *pc)
{
    char *result = my_malloc(sizeof(char) * (5 + 1), 1);

    if (result == NULL)
        my_exit(my_puterror("Failure Malloc.\n"));
    if (*pc >= MEM_SIZE)
        *pc = 0;
    for (int i = 0; i < 4;) {
        result[i] = map[*pc];
        *pc += 1;
        i++;
        if (*pc >= MEM_SIZE)
            *pc = 0;
    }
    return (reword_neg_read_int(result));
}

char **create_tab_two(int nbr_parametre)
{
    char **tab = my_malloc((sizeof(char *) * (nbr_parametre + 1)), 2);

    if (tab == NULL)
        my_exit(my_puterror("Failure Malloc.\n"));
    return (tab);
}

char **special_case(char *map, int *new_posi, int instruct)
{
    if (map || *new_posi) {
    }
    switch (instruct) {
        case 1: return (read_live(map, new_posi, instruct));
        case 9: return (read_zjmp(map, new_posi, instruct));
        case 12: return (read_fork(map, new_posi, instruct));
        case 15: return (read_lfork(map, new_posi, instruct));
        case 10: return (read_ldi(map, new_posi, instruct));
        case 11: return (read_sti(map, new_posi, instruct));
        case 14: return (read_lldi(map, new_posi, instruct));
        default : return (NULL);
    }
}

int find_posi_new_pc_instruction(char *map, int pc, int *new_posi)
{
    int instruct = 0;

    *new_posi = pc;
    if (*new_posi < 0)
        *new_posi *= -1;
    while (*new_posi >= MEM_SIZE)
        *new_posi -= MEM_SIZE;
    if (*new_posi < 0)
        *new_posi *= -1;
    for (int cicle = 0; map && cicle < 5;) {
        instruct = map[*new_posi];
        if (instruct >= 1 && instruct <= 16)
            return (instruct);
        *new_posi += 1;
        if (*new_posi >= MEM_SIZE) {
            *new_posi = 0;
            cicle += 1;
        }
    }
    return (84);
}
