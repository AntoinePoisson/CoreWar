/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** returns a read line from a file descriptor
*/

#include "my.h"
#include "get_next_line.h"

static char *my_strcat_gnl(char *line)
{
    int i = 0;
    int size = my_strlen(line) + 2;
    char *dest = my_malloc(sizeof(char) * size, 0);

    if (dest == NULL)
        return (NULL);
    for (; line[i] != '\0'; i++)
        dest[i] = line[i];
    dest[i + 1] = '\0';
    my_free(line);
    return (dest);
}

static char load_buffer(int fd)
{
    static char buffer[READ_SIZE];
    static int count = 0;
    static char *rest;
    char c;

    if (count == 0) {
        count = read(fd, buffer, READ_SIZE);
        if (count == 0)
            return ('\0');
        rest = buffer;
    }
    count--;
    c = rest[0];
    rest = &rest[1];
    return (c);
}

char *get_next_line(int fd)
{
    char *line = my_malloc(sizeof(char) * 2, 0);
    char c;
    int i = 0;

    if (line == NULL)
        return (NULL);
    line[1] = '\0';
    c = load_buffer(fd);
    for (i = 0; c != '\n' && c != '\0'; i++) {
        line[i] = c;
        line = my_strcat_gnl(line);
        c = load_buffer(fd);
    }
    line[i] = '\0';
    if (c == '\0')
        if (i < 2) {
            my_free(line);
            return (NULL);
        }
    return (line);
}
