/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** store index
*/

#include "corewar.h"

void exec_sti(corewar_t *core, char **tab, int i)
{
    int second_param = 0;
    int third_param = 0;
    int value = 0;

    if (register_or_not(tab[2]))
        second_param = core->champ[i]->r[my_atoi(tab[2])];
    else
        second_param = my_atoi(tab[2]);
    if (register_or_not(tab[3]))
        third_param = core->champ[i]->r[my_atoi(tab[3])];
    else
        third_param = my_atoi(tab[3]);
    value = ((second_param + third_param) % IDX_MOD) % MEM_SIZE;
    write_value(core->champ[i]->r[my_atoi(tab[1])],
    core->arena, (core->champ[i]->r[0] + value) % MEM_SIZE);
}

void sti(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 4)
        return;
    if (check_only_register(tab[1]) == false)
        return;
    if (check_number_or_register(tab[2]) == false)
        return;
    if (check_number_or_register(tab[3]) == false)
        return;
    exec_sti(core, tab, i);
}
