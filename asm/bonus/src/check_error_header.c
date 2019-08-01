/*
** EPITECH PROJECT, 2019
** check_error_header.c
** File description:
** check_error_header
*/

#include "op.h"
#include "asm.h"

static int check_after_flag(char const *str, int *count, int cas)
{
    int count_cote = 0;
    int size = 0;
    int i = 0;

    while (str[i] && str[i] != '"')
        i += 1;
    for (; str[i]; i++, size += 1) {
        if (count_cote == 2 && str[i] != ' ' && str[i] != '\t')
            return (my_puterror("Syntax error.\n"));
        if (str[i] == '"')
            count_cote += 1;
    }
    if (cas == 1 && (size - 2) > PROG_NAME_LENGTH)
        return (my_puterror("The program name is too long.\n"));
    if (count_cote != 2)
        return (my_puterror("Syntax error.\n"));
    if (cas == 2 && (size - 2) > COMMENT_LENGTH)
        return (my_puterror("The comment is too long.\n"));
    *count += 1;
    return (0);
}

static int is_extension_check_error_header(asm_t *var, int *cas_one,
    int *cas_two, int i)
{
    char **line = my_str_to_selec_array(var->file[i], ' ');
    char *err_mess = "The name of your program must be the first line.\n";

    if (line && my_strcmp(line[0], NAME_CMD_STRING) == 0) {
        if (check_after_flag(var->file[i], cas_one, 1) == 84)
            return (84);
    } else if (line && my_strcmp(line[0], COMMENT_CMD_STRING) == 0) {
        if (*cas_one == 0)
            return (my_puterror("The comment must be just after the name.\n"));
        if (check_after_flag(var->file[i], cas_two, 2) == 84)
            return (84);
    } else if (line != NULL && *cas_two != 1 && *cas_one != 1)
        return (my_puterror(err_mess));
    line = free_tab_two(line);
    return (0);
}

static int is_extension_check_error_header_two(asm_t *var)
{
    int cas_one = 0;
    int cas_two = 0;
    char **line = NULL;
    int i = 0;

    for (i = 0, cas_one = 0, cas_two = 0; var->file[i]; i++) {
        if (cas_one == 1 && cas_two == 1)
            break;
        line = my_str_to_selec_array(var->file[i], ' ');
        if (line && my_strcmp(line[0], NAME_CMD_STRING) == 0)
            cas_one += 1;
        if (line && my_strcmp(line[0], COMMENT_CMD_STRING) == 0)
            cas_two += 1;
        line = free_tab_two(line);
    }
    return (i);
}

int check_error_header(asm_t *var, int *i)
{
    int cas_one = 0;
    int cas_two = 0;

    for (; var->file[*i]; *i += 1) {
        if (is_extension_check_error_header(var, &cas_one, &cas_two, *i) == 84)
            return (84);
    }
    if (cas_one != 1 || cas_two != 1)
        return (my_puterror("Error with the .name .commit\n"));
    *i = is_extension_check_error_header_two(var);
    return (0);
}
