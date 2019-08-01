/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** long load index
*/

#include "corewar.h"

void exec_lldi(corewar_t *core, char **tab, int i)
{
    int first_param = 0;
    int second_param = 0;
    int value = 0;

    if (tab[1][my_strlen(tab[1]) - 1] == DIRECT_CHAR)
        first_param = my_atoi(tab[1]);
    else
        first_param = (core->champ[i]->r[0] + my_atoi(tab[1])) % MEM_SIZE;
    if (tab[2][my_strlen(tab[2]) - 1] == DIRECT_CHAR)
        second_param = my_atoi(tab[2]);
    else
        second_param = (core->champ[i]->r[0] + my_atoi(tab[2])) % MEM_SIZE;
    value = first_param + second_param;
    core->champ[i]->r[my_atoi(tab[3])] =
    (core->champ[i]->r[0] + value) % MEM_SIZE;
    if (value == 0)
        core->champ[i]->carry = 1;
    else
        core->champ[i]->carry = 0;
}

void lldi(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 4)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    if (check_only_register(tab[3]) == false)
        return;
    exec_lldi(core, tab, i);
}
