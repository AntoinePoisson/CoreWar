/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

static int add_label(label_t **labels, char *name, int lines, instruct_t *inst)
{
    label_t *element = my_malloc(sizeof(*element), 0);

    if (!element) {
        write(2, "\033[1masm, Error malloc.\n\033[0m", 26);
        return (84);
    }
    element->name = name;
    element->lines = lines;
    element->instruct = inst;
    element->next = *labels;
    *labels = element;
    return (0);
}

int init_labels(instruct_t **instruct, char **file, var_t *i, label_t **labels)
{
    if (i->b && i->b[0][my_strlen(i->b[0]) - 1] != LABEL_CHAR) {
        *instruct = stack_instruct(i->b, file, i->a);
        for (i->ln = 0; (i->b = my_str_to_selec_array(file[++i->a], ' ')) &&
            i->b[0][my_strlen(i->b[0]) - 1] != LABEL_CHAR; i->ln++);
        if (add_label(labels, NULL, ++i->ln, *instruct))
            return (84);
    }
    return (0);
}

void fct_for_norm(char **name, instruct_t **instruct, var_t *i, char **file)
{
    *name = i->b[0];
    (*name)[my_strlen(*name) - 1] = '\0';
    *instruct = stack_instruct(i->b, file, i->a);
    for (i->ln = 0; (i->b = my_str_to_selec_array(file[++i->a], ' ')) &&
        i->b[0][my_strlen(i->b[0]) - 1] != LABEL_CHAR; i->ln++);
}

int stack_labels(char **file, label_t **labels, int index)
{
    instruct_t *instruct = NULL;
    char *name = NULL;
    var_t i = {0, index, my_str_to_selec_array(file[index], '\t')};

    if (init_labels(&instruct, file, &i, labels) == 84)
        return (84);
    while (file[i.a] != NULL) {
        i.b = my_str_to_selec_array(file[i.a], '\t');
        if (i.b && i.b[0][my_strlen(i.b[0]) - 1] == LABEL_CHAR) {
            fct_for_norm(&name, &instruct, &i, file);
            if (add_label(labels, name, ++i.ln, instruct))
                return (84);
            for (int a = 0; (*labels)->instruct[a].end != 1; a++)
                (*labels)->instruct[a].args[(*labels)->instruct[a].len] = NULL;
        } else
            i.a++;
    }
    return (0);
}
