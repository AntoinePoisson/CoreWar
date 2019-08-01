/*
** EPITECH PROJECT, 2019
** find_instruction.c
** File description:
** find_instruction
*/

#include "corewar.h"

char **find_data(char *map, int *pc, int *new_posi)
{
    int instruct = find_posi_new_pc_instruction(map, *pc, new_posi);
    char **result = NULL;

    *pc = *new_posi;
    if (instruct == 84)
        return (NULL);
    *new_posi += 1;
    if (*new_posi >= MEM_SIZE)
        *new_posi = 0;
    if (instruct == 1 || instruct == 9 || instruct == 12
        || instruct == 15 || instruct == 10 || instruct == 11
        || instruct == 14)
        result = special_case(map, new_posi, instruct);
    else
        result = interpret_coding_byte(map, new_posi, instruct);
    return (result);
}

int find_instruct_to_cycle(int nbr)
{
    switch (nbr) {
        case 1: return (10);
        case 2: return (5);
        case 3: return (5);
        case 4: return (10);
        case 5: return (10);
        case 6: return (6);
        case 7: return (6);
        case 8: return (6);
        case 9: return (20);
        case 10: return (25);
        case 11: return (25);
        case 12: return (800);
        case 13: return (10);
        case 14: return (50);
        case 15: return (1000);
        case 16: return (2);
    }
    return (84);
}

int check_instruct_always_true(corewar_t *core, int i)
{
    if (core->arena[core->champ[i]->instruct->old_pc] !=
        my_atoi(core->champ[i]->instruct->cmd[0]))
        return (0);
    return (1);
}

instruct_t *find_instruction(corewar_t *core, int pc,
    instruct_t *instruct, int i)
{
    int new_posi = 0;
    int old_posi = pc;
    char **cmd = find_data(core->arena, &old_posi, &new_posi);

    free_array(instruct->cmd);
    if (cmd == NULL)
        return (NULL);
    if (instruct == NULL)
        return (NULL);
    instruct->new_pc = new_posi;
    instruct->old_pc = old_posi;
    instruct->cmd = cmd;
    core->champ[i]->cycle = find_instruct_to_cycle(my_atoi(cmd[0]));
    return (instruct);
}
