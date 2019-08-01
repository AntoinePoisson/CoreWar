/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create element of asm
*/

#include <fcntl.h>
#include "asm.h"

static int check_link(char const *file)
{
    for (int i = 0; file && file[i]; i++)
        if (file[i] == '/' || file[i] == '\\')
            return (1);
    return (0);
}

int create_file(char const *file)
{
    int size = my_strlen(file);
    char *nw_file = my_malloc(sizeof(char) * (size + 3), 0);
    int flag = O_CREAT | O_RDWR | O_TRUNC;
    int fd = -1;

    if (nw_file == NULL)
        return (84);
    my_strncpy(nw_file, file, (size - 1));
    my_strcat(nw_file, "cor");
    while (check_link(nw_file))
        nw_file = &nw_file[1];
    fd = open(nw_file, flag, 0664);
    if (fd == -1)
        return (my_puterror("Can't create or open\n"));
    return (fd);
}
