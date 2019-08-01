/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void get_cor_options(int *i, char **av, corewar_t *core, int count)
{
    int cor = *i + 1;

    core->champ[count]->n = -1;
    core->champ[count]->a = -1;
    for (; *i > 0 && check_cor(av[*i]) == 0; *i = *i - 1) {
        if (!my_strcmp(av[*i], "-a"))
            core->champ[count]->a = my_atoi(av[*i + 1]);
        if (!my_strcmp(av[*i], "-n"))
            core->champ[count]->n = my_atoi(av[*i + 1]);
        if (!my_strcmp(av[*i], "-dump") && av[*i + 1])
            core->dump = my_atoi(av[*i + 1]);
    }
    if ((core->champ[count]->buffer = get_file(av[cor],
        &core->champ[count]->size, &core->champ[count]->name)) == NULL)
        my_exit(84);
    core->champ[count]->carry = 0;
    core->champ[count]->fork = false;
}

void parser(int ac, char **av, corewar_t *core)
{
    int count = count_cor(av) - 1;

    core->nb_core = count_cor(av);
    core->size_header = PROG_NAME_LENGTH + COMMENT_LENGTH + 17;
    for (int i = ac - 1; i > 0;) {
        if (check_cor(av[i]) == 1) {
            i--;
            get_cor_options(&i, av, core, count);
            core->champ[count]->instruc = my_malloc((sizeof(char) *
            (core->champ[count]->size - core->size_header + 1)), 1);
            core->champ[count]->live = 1;
            for (int j = 0; j <
                (core->champ[count]->size - core->size_header + 1); j++)
                core->champ[count]->instruc[j] =
                    core->champ[count]->buffer[core->size_header + j - 1];
            count--;
        } else
            i--;
    }
}
