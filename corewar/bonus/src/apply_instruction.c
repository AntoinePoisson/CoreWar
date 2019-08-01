/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** apply all instruction
*/

#include "corewar.h"

void move_pc(corewar_t *core, int j)
{
    if (!(my_atoi(core->champ[j]->instruct->cmd[0]) == 9
    && core->champ[j]->carry == 1))
        core->champ[j]->r[0] = core->champ[j]->instruct->new_pc;
}

void instruction_call(corewar_t *core, char **tab, int j)
{
    switch (my_atoi(tab[0])) {
        case 1: return (live(core, tab, j));
        case 2: return (ld(core, tab, j));
        case 3: return (st(core, tab, j));
        case 4: return (add(core, tab, j));
        case 5: return (sub(core, tab, j));
        case 6: return (and(core, tab, j));
        case 7: return (or(core, tab, j));
        case 8: return (xor(core, tab, j));
        case 9: return (zjmp(core, tab, j));
        case 10: return (ldi(core, tab, j));
        case 11: return (sti(core, tab, j));
        case 12: return (my_fork(core, tab, j));
        case 13: return (lld(core, tab , j));
        case 14: return (lldi(core, tab, j));
        case 15: return (lfork(core, tab, j));
        case 16: return (aff(core, tab, j));
        default: return;
    }
}

void cycle_or_not(corewar_t *core, int j)
{
    if (core->champ[j]->cycle <= 0) {
        if (check_instruct_always_true(core, j)) {
            instruction_call(core, core->champ[j]->instruct->cmd, j);
            move_pc(core, j);
        }
        core->champ[j]->instruct = find_instruction(core,
        core->champ[j]->r[0], core->champ[j]->instruct, j);
    } else
        core->champ[j]->cycle -= 1;
}

void apply_instruct(corewar_t *core)
{
    int nb_core = core->nb_core;

    for (int j = 0; j < nb_core; j++)
        if (core->champ[j]->live != -1)
            cycle_or_not(core, j);
}
