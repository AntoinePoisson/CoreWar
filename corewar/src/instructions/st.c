/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** store
*/

#include "corewar.h"

void exec_st(corewar_t *core, char **tab, int i)
{
    int second_parameter = 0;
    unsigned int pc = core->champ[i]->r[0];

    if (!register_or_not(tab[2])) {
        second_parameter = my_atoi(tab[2]);
        write_value(core->champ[i]->r[my_atoi(tab[1])], core->arena,
        (pc + (second_parameter % IDX_MOD)) % MEM_SIZE);
    } else
        core->champ[i]->r[my_atoi(tab[2])] = core->champ[i]->r[my_atoi(tab[1])];
}

void st(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 3)
        return;
    if (check_only_register(tab[1]) == false)
        return;
    if (check_number_or_register(tab[2]) == false)
        return;
    exec_st(core, tab, i);
}
