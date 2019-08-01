/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** libmy
*/

#include "corewar.h"
#include "my.h"

void empty_garbage_collector(void)
{
    corewar_t *core = init_garbage_collector(NULL);
    pointer_store_t *backup = NULL;

    while (core->pointer_store) {
        backup = core->pointer_store->next;
        free(core->pointer_store->pointer);
        free(core->pointer_store);
        core->pointer_store = backup;
    }
}

int my_free(void *pointer)
{
    corewar_t *core = init_garbage_collector(NULL);
    pointer_store_t *pointer_store = core->pointer_store;
    pointer_store_t *tmp = NULL;

    if (core->pointer_store == NULL || pointer == NULL)
        return (0);
    if (core->pointer_store->pointer == pointer) {
        tmp = core->pointer_store;
        core->pointer_store = core->pointer_store->next;
    } else {
        for (; pointer_store->next && pointer_store->next->pointer != pointer;
        pointer_store = pointer_store->next);
        if (pointer_store->next == NULL)
            return (0);
        tmp = pointer_store->next;
        pointer_store->next = pointer_store->next->next;
    }
    free(tmp);
    free(pointer);
    return (0);
}
