/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** live
*/

#include "corewar.h"

void reduce_cycle(corewar_t *core)
{
    if (core->nb_life >= NBR_LIVE) {
        *(core->cycle_die) -= CYCLE_DELTA;
        core->nb_life = 0;
    }
}

void exec_live(corewar_t *core, char **tab, int i)
{
    int first_param = my_atoi(tab[1]);

    (void)i;
    for (int j = 0; j < core->nb_core; j++) {
        if (first_param == core->id[j]) {
            core->champ[j]->live = 1;
            core->last = first_param;
            my_printf("The player %d(%s) is alive.\n",
            core->id[j], core->name_id[j]);
            reduce_cycle(core);
        }
    }
    core->nb_life++;
}

void live(corewar_t *core, char **tab, int i)
{
    if (my_tablen(tab) != 2)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    exec_live(core, tab, i);
}
