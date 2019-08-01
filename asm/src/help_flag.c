/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** help_flag.c
*/

#include <stdio.h>
#include <unistd.h>
#include "asm.h"

int help_flag(char const *av0, char const *av1)
{
    if (my_strcmp(av1, "-h"))
        return (84);
    write(1, "USAGE\n\t", 7);
    write(1, av0, my_strlen(av0));
    write(1, " file_name[.s]\n\nDESCRIPTION\n\tfile_name\t", 39);
    write(1, "file in assembly language to be converted into ", 47);
    write(1, "file_name.cor, an executable in the Virtual Machine.\n", 53);
    return (0);
}
