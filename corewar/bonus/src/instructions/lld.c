/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** long load
*/

#include "corewar.h"

void exec_lld(corewar_t *core, char **tab, int i)
{
    int first_parameter = 0;
    int pc = core->champ[i]->r[0];

    first_parameter = my_atoi(tab[1]);
    core->champ[i]->r[my_atoi(tab[2])] = (pc + first_parameter) % MEM_SIZE;
    if (my_atoi(tab[1]) == 0)
        core->champ[i]->carry = 1;
    else
        core->champ[i]->carry = 0;
}

void lld(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 3)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    if (check_only_register(tab[2]) == false)
        return;
    exec_lld(core, tab, i);
}
