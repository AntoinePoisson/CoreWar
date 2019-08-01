/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

char *fill_first_instruct(char ***instruct, char *search, index_t *i)
{
    if (i->c != 0) {
        (*instruct)[0] = my_malloc(my_strlen(search) + 1, 1);
        if (!(*instruct)[0])
            return (NULL);
        for (i->d = 0; search[i->d] != '\0'; i->d++)
            (*instruct)[0][i->d] = search[i->d];
        (*instruct)[0][i->d] = '\0';
    }
    return ("ok");
}

char **alloc_instruct(char **f, index_t *i, int a, instruct_t **tmp)
{
    char **buf = NULL;
    char *search = my_strchr(f[a], LABEL_CHAR);
    char **instruct = NULL;

    while (f[a][++i->b] != 9 && f[a][i->b] != 10 &&
            f[a][i->b] != 32 && f[a][i->b]);
    i->b = (f[a][i->b - 1] != LABEL_CHAR || (f[a][i->b] && f[a][i->b + 1]))
    ? 1 : 0;
    for (i->c = i->b; (buf = my_str_to_selec_array(f[++a], ' ')) &&
        (*buf)[my_strlen(*buf) - 1] != LABEL_CHAR; i->b++);
    instruct = my_malloc(sizeof(char *) * (i->b + 1), 2);
    (*tmp) = my_malloc(sizeof(**tmp) * (i->b + 1), 0);
    if (!instruct || !(*tmp) || !fill_first_instruct(&instruct, search, i))
        return (NULL);
    return (instruct);
}

int instruct_to_int(char *instruct)
{
    if (!instruct)
        return (0);
    for (int a = 0; op_tab[a].mnemonique != 0; a++)
        if (my_strcmp(instruct, op_tab[a].mnemonique) == 0)
            return (a + 1);
    return (-1);
}

instruct_t *array_to_instruct(char **first_step, instruct_t *instruct)
{
    int a = 0;
    int count = 0;
    char **arr = NULL;

    for (a = 0; first_step[a] != NULL; a++) {
        arr = my_str_to_selec_array(first_step[a], SEPARATOR_CHAR);
        instruct[a].end = 0;
        instruct[a].name = instruct_to_int(arr[0]);
        instruct[a].args = &arr[1];
        for (count = 0; instruct[a].args[count] != NULL; count++);
        instruct[a].len = count;
    }
    instruct[a].end = 1;
    return (instruct);
}

instruct_t *stack_instruct(char **buf, char **file, int a)
{
    index_t i = {-1, 0, 0};
    instruct_t *instruct = NULL;
    char **first_step = alloc_instruct(file, &i, a, &instruct);

    if (!first_step || !instruct) {
        write(2, "\033[1masm, Error malloc.\n\033[0m", 26);
        return (NULL);
    }
    for (i.b = i.c, i.c = a; (buf = my_str_to_selec_array(file[++i.c], ' ')) &&
        (*buf)[my_strlen(*buf) - 1] != LABEL_CHAR; i.b++) {
        first_step[i.b] =
        my_malloc(sizeof(char) * (my_strlen(file[i.c]) + 1), 0);
        for (i.d = 0; file[i.c][i.d] != '\0'; i.d++)
            first_step[i.b][i.d] = file[i.c][i.d];
        first_step[i.b][i.d] = '\0';
    }
    first_step[i.b] = NULL;
    instruct = array_to_instruct(first_step, instruct);
    return (instruct);
}
