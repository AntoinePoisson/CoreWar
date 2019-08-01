/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (my_puterror("Usage: ./asm file_name[.s] ....\n"));
    if (help_flag(av[0], av[1]) == 0)
        return (0);
    for (unsigned int i = 1; av[i]; i++)
        if (assembly(av[i]) == 84)
            return (84);
    return (0);
}
