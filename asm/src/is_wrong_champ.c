/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_wrong_label.c
*/

#include "asm.h"

static int reverse_list(label_t **list)
{
    label_t *reverse = NULL;
    label_t *head = NULL;

    while (*list != NULL) {
        reverse = my_malloc(sizeof(*reverse), 0);
        if (reverse == NULL)
            return (-1);
        reverse->name = (*list)->name;
        reverse->lines = (*list)->lines;
        reverse->instruct = (*list)->instruct;
        reverse->next = head;
        head = reverse;
        *list = (*list)->next;
    }
    *list = reverse;
    return (0);
}

int is_wrong_champ(asm_t *var, label_t **labels)
{
    int i = 0;

    if (check_error_header(var, &i) == 84)
        return (84);
    if (!var->file)
        return (84);
    if (stack_labels(var->file, labels, i) != 0 || is_wrong_label(*labels) != 0)
        return (84);
    if (is_wrong_parameters(*labels) != 0)
        return (84);
    reverse_list(labels);
    return (0);
}
