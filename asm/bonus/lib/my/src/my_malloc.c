/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** my_malloc
*/

#include "asm.h"
#include "my.h"

char *my_memset(char *pointer, char c, int size)
{
    for (int i = 0; i < size; pointer[i] = c, i++);
    return (pointer);
}

char **my_memset_table(char **pointer, int size)
{
    for (int i = 0; i < size; pointer[i] = NULL, i++);
    return (pointer);
}

void *get_allocation(size_t size, int fill)
{
    char *pointer_one = NULL;
    char **pointer_two = NULL;
    void *pointer_regular = NULL;

    if (fill == 1) {
        if ((pointer_one = malloc(size)) == NULL)
            my_exit(84);
        return (my_memset((char *)pointer_one, '\0',
        (size / sizeof(char))));
    } else if (fill == 2) {
        if ((pointer_two = malloc(size)) == NULL)
            my_exit(84);
        return (my_memset_table((char **)pointer_two,
        (size / sizeof(char *))));
    } else {
        if ((pointer_regular = malloc(size)) == NULL)
            my_exit(84);
        return (pointer_regular);
    }
}

asm_t *init_garbage_collector(asm_t *assembly_pointer)
{
    static asm_t *assembly = NULL;

    if (assembly_pointer != NULL) {
        assembly = assembly_pointer;
        return (NULL);
    }
    return (assembly);
}

void *my_malloc(size_t size, int fill)
{
    asm_t *core = init_garbage_collector(NULL);
    void *pointer = get_allocation(size, fill);
    pointer_store_t *garbage_collector = NULL;
    pointer_store_t *tmp = core->pointer_store;

    if (pointer == NULL)
        my_exit(84);
    if ((garbage_collector = malloc(sizeof(pointer_store_t))) == NULL)
        my_exit(84);
    garbage_collector->pointer = pointer;
    garbage_collector->next = NULL;
    if (core->pointer_store == NULL)
        core->pointer_store = garbage_collector;
    else {
        for (; tmp->next;
        tmp = tmp->next);
        tmp->next = garbage_collector;
    }
    return (pointer);
}
