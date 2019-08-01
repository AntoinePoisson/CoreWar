/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

static int parameters_nb(instruct_t *instruct, int a)
{
    if (op_tab[instruct[a].name - 1].nbr_args > MAX_ARGS_NUMBER ||
        op_tab[instruct[a].name - 1].nbr_args != instruct[a].len) {
        if (op_tab[instruct[a].name - 1].nbr_args > instruct[a].len)
            my_puterror("The argument given to the instruction is invalid.\n");
        else
            my_puterror("Too many arguments given to the instruction.\n");
        return (84);
    }
    return (0);
}

static int parameters_type(instruct_t *inst, int a, label_t *stack)
{
    args_type_t check = 0;

    for (int b = 0; inst[a].args[b] != NULL; b++) {
        check = check_parameter_type(inst[a].args[b], stack);
        if (check == 84)
            return (84);
        if ((check & op_tab[inst[a].name - 1].type[b]) == 0) {
            my_puterror("The argument given to the instruction is invalid.\n");
            return (84);
        }
    }
    return (0);
}

int is_wrong_parameters(label_t *labels)
{
    label_t *tmp = labels;

    while (tmp != NULL) {
        for (int a = 0; tmp->instruct[a].end != 1; a++) {
            if (tmp->instruct[a].name == -1)
                return (my_puterror("Invalid instruction.\n"));
            if (parameters_nb(tmp->instruct, a) != 0)
                return (84);
            if (parameters_type(tmp->instruct, a, labels) != 0)
                return (84);
        }
        tmp = tmp->next;
    }
    return (0);
}
