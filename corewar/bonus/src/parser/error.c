/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

bool check_dump(char **av, int *i)
{
    if (!av[*i])
        return (false);
    if (!my_strcmp(av[*i], "-dump")) {
        if (!(av[*i + 1] && my_str_isnum(av[*i + 1]) == true)) {
            my_puterror("Invalid dump arguments (-dump nbr_cycle)\n");
            return (true);
        }
        *i += 2;
        return (false);
    } else {
        return (false);
    }
}

bool check_valid_champion(char **av,
int *i, unsigned short *player_count)
{
    for (; av[*i] && (!my_strcmp(av[*i], "-n") || !my_strcmp(av[*i], "-a"));
        *i += 2) {
        if (!(av[*i + 1] && my_str_isnum(av[*i + 1])))
            return (true);
    }
    if (av[*i] && check_cor(av[*i]) == 1) {
        *player_count += 1;
        *i += 1;
    } else
        return (true);
    return (false);
}

bool check_champions(char **av,
int *i, unsigned short *player_count)
{
    if (!av[*i])
        return (false);
    if (!my_strcmp(av[*i], "-n") || !my_strcmp(av[*i], "-a")) {
        if (check_valid_champion(av, i, player_count)) {
            my_puterror("Invalid champion arguments ");
            my_puterror("(-n prog_number -a load_address prog_name)\n");
            return (true);
        }
    }
    return (false);
}

bool parsing_error(int ac, char **av)
{
    unsigned short player_count = 0;

    for (int i = 0; i < ac && av[i]; i++) {
        if (check_dump(av, &i))
            return (true);
        if (i >= ac)
            break;
        if (check_champions(av, &i, &player_count))
            return (true);
        if (i >= ac)
            break;
        if (av[i] && check_cor(av[i]) == 1)
            player_count += 1;
    }
    if (player_count < 2) {
        my_puterror("Not enough champions\n");
        return (true);
    }
    return (false);
}
