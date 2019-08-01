/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include <fcntl.h>
#include "asm.h"

char **fill_tab(char const *av)
{
    int fd = open(av, 0);
    char *line = NULL;
    char **tab = my_malloc(sizeof(char *) * 2, 2);
    int i = 0;

    if (!tab || fd < 0) {
        my_puterror("Error in function open: No such file or directory.\n");
        return (NULL);
    }
    line = get_next_line(fd);
    tab[i] = line;
    while (line) {
        line = get_next_line(fd);
        tab = tab_realloc(tab);
        tab[++i] = line;
    }
    close(fd);
    return (tab);
}

int write_prog_size(asm_t *var)
{
    int prog_size = change_endian_32(var->reg + var->dir + var->ind);

    lseek(var->fd, 136, SEEK_SET);
    write(var->fd, &prog_size, sizeof(prog_size));
    return (0);
}

int assembly(char const *av)
{
    asm_t var = {NULL, -1, 0, 0, 0, 0, 0, NULL, NULL};
    label_t *labels = NULL;

    init_garbage_collector(&var);
    if ((var.file = management_tab(fill_tab(av))) == NULL)
        return (84);
    if (is_wrong_champ(&var, &labels) == 84)
        return (84);
    if ((var.fd = create_file(av)) < 0)
        return (84);
    if (write_data(&var, labels) == 84)
        return (84);
    write_prog_size(&var);
    empty_garbage_collector();
    return (0);
}
