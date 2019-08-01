/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fork
*/

#include "corewar.h"

player_t *realloc_fork(corewar_t *core, char **tab, int i)
{
    player_t *player = my_malloc(sizeof(player_t), 0);
    int *id_tab = my_malloc(sizeof(int) * (core->nb_core + 1), 0);
    char **id_name = my_malloc(sizeof(char *) * (core->nb_core + 2), 2);
    int j = 0;

    if (player == NULL)
        my_exit(84);
    for (j = 0; j < core->nb_core;
    id_tab[j] = core->id[j], id_name[j] = core->name_id[j], j++);
    id_tab[j] = core->champ[i]->r[1];
    id_name[j] = my_strdup(core->name_id[core->champ[i]->r[1]]);
    my_free(core->id);
    my_free(core->name_id);
    core->name_id = id_name;
    core->id = id_tab;
    *player = *(core->champ[i]);
    player->r[0] = (player->r[0] + (my_atoi(tab[1]) % IDX_MOD)) % MEM_SIZE;
    player->fork = true;
    return (player);
}

void exec_my_fork(corewar_t *core, char **tab, int i)
{
    player_t *player = NULL;
    player_t **tmp = NULL;
    int j = 0;

    player = realloc_fork(core, tab, i);
    for (j = 0; core->champ[j]; j++);
    tmp = my_malloc(sizeof(player_t *) * (j + 2), 0);
    for (j = 0; core->champ[j]; j++)
        tmp[j] = core->champ[j];
    tmp[j] = player;
    tmp[j + 1] = NULL;
    my_free(core->champ);
    core->champ = tmp;
    core->nb_core += 1;
}

void my_fork(corewar_t *core, char **tab, int i)
{
    int register_champ = 0;

    if (my_tablen(tab) != 2)
        return;
    if (check_only_number(tab[1]) == false)
        return;
    register_champ = core->champ[i]->r[1];
    if (register_champ >= core->nb_core)
        return;
    exec_my_fork(core, tab, i);
}
