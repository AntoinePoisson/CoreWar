/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

u_int32_t change_endian_32(u_int32_t endian)
{
    endian = (((endian >> 24) & 0x000000ff) |
    ((endian << 8) & 0x00ff0000) |
    ((endian >> 8) & 0x0000ff00) |
    ((endian << 24) & 0xff000000));
    return (endian);
}

int handle_errors(char const *file, char **c_name, unsigned int size)
{
    int nb = 0;
    int fd = open(file, O_RDONLY);
    char name[PROG_NAME_LENGTH + 1];

    if (fd == -1 || read(fd, &nb, sizeof(int)) == -1)
        return (84);
    if (nb != (int)change_endian_32(COREWAR_EXEC_MAGIC))
        return (84);
    nb = read(fd, (char *)name, PROG_NAME_LENGTH + 1);
    if (nb < PROG_NAME_LENGTH + 1)
        return (84);
    *c_name = my_malloc(sizeof(char) * (my_strlen(name) + 1), 1);
    for (nb = 0; name[nb] && nb < (PROG_NAME_LENGTH + 1); nb++)
        (*c_name)[nb] = name[nb];
    (*c_name)[nb] = '\0';
    if (lseek(fd, 136, SEEK_SET) == -1 || read(fd, &nb, sizeof(int)) == -1)
        return (84);
    if (change_endian_32(nb) != size || size >= MEM_SIZE)
        return (84);
    return (0);
}

char *get_file(char const *name, long *size, char **c_name)
{
    int fd = open(name, O_RDONLY);
    off_t offset = 0;
    char *str = NULL;
    char c = '\0';

    offset = lseek(fd, offset, SEEK_END);
    *size = -1;
    if (fd == -1 || (str = my_malloc(sizeof(char) * (offset + 1), 1)) == NULL)
        return (NULL);
    for (long i = 0; i < offset; i++) {
        lseek(fd, i, SEEK_SET);
        read(fd, &c, sizeof(char));
        str[i] = c;
    }
    *size = offset;
    if (handle_errors(name, c_name, offset - PROG_NAME_LENGTH - COMMENT_LENGTH
        - sizeof(int) * 2 - 8) == 84)
        return (NULL);
    close(fd);
    return (str);
}
