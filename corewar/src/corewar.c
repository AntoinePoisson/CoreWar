/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

int display_help(char *av)
{
    my_printf("USAGE\n\t%s [-dump nbr_cycle] [[-n prog_number]", av);
    my_printf(" [-a load_address] prog_name] ...\n\n");
    my_printf("DESCRIPTION\n\t-dump nbr_cycle\tdumps the memory after the ");
    my_printf("nbr_cycle execution (if the round isn't\n\t\t\talready over) ");
    my_printf("with the following format: 32 bytes/line in\n\t\t\thexadecimal");
    my_printf(" (A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next program's ");
    my_printf("number. By default, the first free number\n\t\t\tin the ");
    my_printf("parameter order\n\t-a load_address\tsets the next program's ");
    my_printf("loading address. When no address is\n\t\t\tspecified, optimize");
    my_printf(" the adresses so that the processes are as far\n\t\t\taway ");
    my_printf("from each other as possible. The addresses are ");
    my_printf("MEM_SIZE modulo\n");
    return (0);
}

int corewar(int ac, char **av)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};

    if (ac < 2)
        return (84);
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (display_help(av[0]));
    init_garbage_collector(&core);
    if (parsing_error(ac, av) == true)
        my_exit(84);
    core.champ = my_malloc(sizeof(player_t *) * (count_cor(av) + 1), 0);
    for (int i = 0; i < count_cor(av); i++) {
        core.champ[i] = my_malloc(sizeof(player_t), 0);
        core.champ[i + 1] = NULL;
    }
    parser(ac, av, &core);
    init_arena(&core);
    game_loop(&core);
    empty_garbage_collector();
    return (0);
}
