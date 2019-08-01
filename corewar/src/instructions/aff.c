/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** aff
*/

#include "corewar.h"

void exec_aff(corewar_t *core, char **tab, int i)
{
    unsigned char c = core->champ[i]->r[my_atoi(tab[1])] % 256;

    write(1, &c, 1);
}

void aff(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 2)
        return;
    if (check_only_register(tab[1]) == false)
        return;
    exec_aff(core, tab, i);
}
