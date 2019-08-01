/*
** EPITECH PROJECT, 2019
** management_header.c
** File description:
** management_header
*/

#include "op.h"
#include "asm.h"

int magic_nbr(asm_t *var)
{
    int magic = COREWAR_EXEC_MAGIC;

    magic = change_endian_32(magic);
    write(var->fd, &magic, sizeof(magic));
    return (0);
}

int write_name(asm_t *var, char *prog_name)
{
    int size = PROG_NAME_LENGTH;

    while ((prog_name[0] && prog_name[0] != '"'))
        prog_name = &prog_name[1];
    prog_name = &prog_name[1];
    prog_name[my_strlen(prog_name) - 1] = '\0';
    size -= my_strlen(prog_name);
    write(var->fd, prog_name, my_strlen(prog_name));
    for (; size >= 0 - 3; size--)
        write(var->fd, "\0", 1);
    size = 0x00;
    write(var->fd, &size, sizeof(size));
    return (0);
}

int write_comment(asm_t *var, char *comment)
{
    int size = COMMENT_LENGTH;

    while (comment[0] && comment[0] != '"')
        comment = &comment[1];
    comment = &comment[1];
    comment[my_strlen(comment) - 1] = '\0';
    size -= my_strlen(comment);
    write(var->fd, comment, my_strlen(comment));
    for (; size >= -3; size--)
        write(var->fd, "\0", 1);
    return (0);
}

int management_header(asm_t *var, int *i)
{
    int a = 0;
    char **line = NULL;

    magic_nbr(var);
    for (; var->file[a]; a++) {
        line = my_str_to_selec_array(var->file[a], ' ');
        if (line && my_strcmp(line[0], NAME_CMD_STRING) == 0)
            write_name(var, var->file[a]);
        if (line && my_strcmp(line[0], COMMENT_CMD_STRING) == 0) {
            write_comment(var, var->file[a]);
            *i = a + 1;
            break;
        }
        line = free_tab_two(line);
    }
    return (0);
}
