/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

static int is_wrong_charac(char *name)
{
    int b = 0;

    if (name[0] == '\0' || (name[0] >= '0' && name[0] <= '9'))
        return (84);
    for (int a = 0; name[a] != '\0'; a++) {
        for (b = 0; LABEL_CHARS[b] != '\0'; b++)
            if (name[a] == LABEL_CHARS[b])
                break;
        if (LABEL_CHARS[b] == '\0')
            return (84);
    }
    return (0);
}

int is_wrong_label(label_t *labels)
{
    label_t *copy = labels;

    for (label_t *tmp = labels; tmp != NULL; tmp = tmp->next)
        if (tmp->name && is_wrong_charac(tmp->name) != 0)
            return (my_puterror("Invalid label name.\n"));
    for (; copy != NULL; copy = copy->next) {
        for (label_t *tmp = copy->next; tmp != NULL; tmp = tmp->next)
            if (tmp->name && my_strcmp(tmp->name, copy->name) == 0) {
                write(2, "Multiple definition of the same label.\n", 39);
                return (84);
            }
    }
    return (0);
}
