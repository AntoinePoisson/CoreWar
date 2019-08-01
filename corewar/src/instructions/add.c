/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void exec_add(corewar_t *core, char **tab, int i)
{
    int first_parameter = core->champ[i]->r[my_atoi(tab[1])];
    int second_parameter = core->champ[i]->r[my_atoi(tab[2])];

    core->champ[i]->r[my_atoi(tab[3])] = first_parameter + second_parameter;
    if (core->champ[i]->r[my_atoi(tab[3])] == 0)
        core->champ[i]->carry = 1;
    else
        core->champ[i]->carry = 0;
}

void add(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 4)
        return;
    if (check_only_register(tab[1]) == false)
        return;
    if (check_only_register(tab[2]) == false)
        return;
    if (check_only_register(tab[3]) == false)
        return;
    exec_add(core, tab, i);
}
