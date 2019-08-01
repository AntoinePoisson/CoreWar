/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void exec_or(corewar_t *core, char **tab, int i)
{
    int first_parameter = 0;
    int second_parameter = 0;

    if (register_or_not(tab[1]))
        first_parameter = core->champ[i]->r[my_atoi(tab[1])];
    else
        first_parameter = my_atoi(tab[1]);
    if (register_or_not(tab[2]))
        second_parameter = core->champ[i]->r[my_atoi(tab[2])];
    else
        second_parameter = my_atoi(tab[2]);
    core->champ[i]->r[my_atoi(tab[3])] = first_parameter | second_parameter;
    if (core->champ[i]->r[my_atoi(tab[3])] == 0)
        core->champ[i]->carry = 1;
    else
        core->champ[i]->carry = 0;
}

void or(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 4)
        return;
    if (check_number_or_register(tab[1]) == false)
        return;
    if (check_number_or_register(tab[2]) == false)
        return;
    if (check_only_register(tab[3]) == false)
        return;
    exec_or(core, tab, i);
}
