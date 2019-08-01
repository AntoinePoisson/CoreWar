/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** jump if zero
*/

#include "corewar.h"

void exec_zjmp(corewar_t *core, char **tab, int i)
{
    int first_param = my_atoi(tab[1]);

    if (core->champ[i]->carry == 1)
        core->champ[i]->r[0] = (core->champ[i]->r[0] +
        (first_param % IDX_MOD)) % MEM_SIZE;
}

void zjmp(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 2)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    exec_zjmp(core, tab, i);
}
