/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** load index
*/

#include "corewar.h"

void is_extension_exec_ldi(corewar_t *core, int i, int value)
{
    if (value == 0)
        core->champ[i]->carry = 1;
    else
        core->champ[i]->carry = 0;
}

void exec_ldi(corewar_t *core, char **tab, int i)
{
    int first_param = 0;
    int second_param = 0;
    int value = 0;

    if (tab[1][my_strlen(tab[1]) - 1] == DIRECT_CHAR)
        first_param = my_atoi(tab[1]);
    else
        first_param = (((core->champ[i]->r[0]
        + (my_atoi(tab[1]) % IDX_MOD))) % MEM_SIZE);
    if (tab[2][my_strlen(tab[2]) - 1] == DIRECT_CHAR)
        second_param = my_atoi(tab[2]);
    else
        second_param = ((core->champ[i]->r[0]
        + (my_atoi(tab[2]) % IDX_MOD)) % MEM_SIZE);
    value = first_param + second_param;
    core->champ[i]->r[my_atoi(tab[3])] =
    (core->champ[i]->r[0] + (value % IDX_MOD)) % MEM_SIZE;
    is_extension_exec_ldi(core, i, value);
}

void ldi(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 4)
        return;
    if (check_only_register(tab[1]) == true)
        return;
    if (check_only_register(tab[2]) == true)
        return;
    if (check_only_register(tab[3]) == false)
        return;
    exec_ldi(core, tab, i);
}
