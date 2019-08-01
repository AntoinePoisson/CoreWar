/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** game loop
*/

#include "corewar.h"

void free_champ(corewar_t *core)
{
    for (int i = 0; i < core->nb_core; i++) {
        my_free(core->champ[i]->name);
        my_free(core->champ[i]->buffer);
        my_free(core->champ[i]);
    }
    my_free(core->arena);
}

int check_live(corewar_t *core)
{
    int count = 0;

    for (int i = 0; i < core->nb_core; i++) {
        if (core->champ[i]->live <= 0) {
            core->champ[i]->live = -1;
        } else {
            if (core->champ[i]->fork == false)
                count++;
            core->champ[i]->live = 0;
        }
    }
    return (count);
}

void win_condition(corewar_t *core)
{
    if (core->last != -1)
        my_printf("The player %d(%s) has won.\n",
        core->last, core->name_id[core->last - 1]);
    free_champ(core);
}

void game_loop(corewar_t *core)
{
    int cycle_die = CYCLE_TO_DIE;
    int i = 0;

    core->cycle_die = &cycle_die;
    while (check_live(core) > 1) {
        if (core->dump != 0 && i % core->dump == 0)
            break;
        for (int j = 0; j <= cycle_die; j++) {
            i += 1;
            apply_instruct(core);
            core->nb_cycle += 1;
        }
        if (core->nb_life >= NBR_LIVE) {
            cycle_die -= CYCLE_DELTA;
            core->nb_life = 0;
        }
        display_curses(core);
    }
    win_condition(core);
    endwin();
}
