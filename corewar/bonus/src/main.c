/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    if (env[0] == NULL)
        return (84);
    return (corewar(ac, av));
}
