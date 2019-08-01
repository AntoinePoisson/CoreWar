/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** libmy
*/

#include "asm.h"
#include "my.h"

void empty_garbage_collector(void)
{
    asm_t *core = init_garbage_collector(NULL);
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
    free(pointer);
    return (0);
}
