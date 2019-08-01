/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** init arena with all the instruction
*/

#include "corewar.h"

int check_cor(char *av)
{
    char *temp = my_revstr(my_strdup(av));

    if (my_strncmp("roc.", temp, 3) == 0) {
        my_free(temp);
        return (1);
    }
    my_free(temp);
    return (0);
}

int count_cor(char **av)
{
    char *temp = NULL;
    int count = 0;

    for (int i = 1; av[i]; i++) {
        temp = my_revstr(my_strdup(av[i]));
        if (my_strncmp("roc.", temp, 3) == 0)
            count++;
        my_free(temp);
    }
    return (count);
}

void create_instruction(corewar_t *war)
{
    instruct_t *node = NULL;

    for (int j = 0; j < war->nb_core; j++) {
        node = my_malloc(sizeof(*node), 0);
        if (node == NULL)
            my_exit(my_puterror("Failure Malloc.\n"));
        node->old_pc = 0;
        node->new_pc = 0;
        node->cmd = NULL;
        war->champ[j]->instruct = find_instruction(war,
            war->champ[j]->r[0], node, j);
    }
}

void create_id_player(corewar_t *core)
{
    core->id = my_malloc((sizeof(int) * core->nb_core), 0);
    core->name_id = my_malloc((sizeof(char *) * (core->nb_core + 1)), 2);
    for (int i = 0; i < core->nb_core; i++) {
        if (core->champ[i]->n != -1) {
            core->champ[i]->r[1] = core->champ[i]->n;
            core->id[i] = core->champ[i]->n;
        } else {
            core->champ[i]->r[1] = i + 1;
            core->id[i] = i + 1;
        }
        core->name_id[i] = my_strdup(core->champ[i]->name);
        for (int j = 2; j <= REG_NUMBER; j++)
            core->champ[i]->r[j] = 0;
    }
}

void init_arena(corewar_t *core)
{
    int lenght = MEM_SIZE / core->nb_core;
    int j = 0;
    int m = 0;
    int k = 0;

    core->last = -1;
    if ((core->arena = my_malloc((sizeof(char) * (MEM_SIZE + 1)), 1)) == NULL)
        my_exit(84);
    create_id_player(core);
    for (int i = 0; j < core->nb_core; i = i + lenght, j++) {
        m = (core->champ[j]->a == -1) ? i : core->champ[j]->a;
        core->champ[j]->r[0] = m;
        for (k = 0;
            k < (core->champ[j]->size - core->size_header + 1); k++, m++)
            core->arena[m] = core->champ[j]->instruc[k];
        core->champ[j]->cycle = 0;
        core->champ[j]->live = 1;
    }
    create_instruction(core);
}
