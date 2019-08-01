/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

static int check_register(char const *regist)
{
    if (regist[1] == '\0')
        return (my_puterror("Invalid register number.\n"));
    if (my_getnbr(&regist[1]) >= 0 && my_getnbr(&regist[1]) <= REG_NUMBER)
        return (0);
    return (my_puterror("Invalid register number.\n"));
}

static int check_direct(char const *direct, label_t *stack)
{
    if (direct[1] == '\0' ||
        (direct[1] != LABEL_CHAR && my_isnum(&direct[1]))) {
        my_puterror("The argument given to the instruction is invalid.\n");
        return (84);
    }
    if (!my_isnum(&direct[1]))
        return (0);
    if (direct[1] == LABEL_CHAR)
        for (label_t *tmp = stack; tmp != NULL; tmp = tmp->next) {
            if (my_strcmp(&direct[2], tmp->name) == 0)
                return (0);
        }
    my_puterror("Undefined label.\n");
    return (84);
}

static int check_indirect(char const *direct, label_t *stack)
{
    if (!my_isnum(direct)) {
        return (T_IND);
    }
    if (direct[0] == LABEL_CHAR)
        for (label_t *tmp = stack; tmp != NULL; tmp = tmp->next)
            if (my_strcmp(direct + 1, tmp->name) == 0)
                return (T_IND);
    for (label_t *tmp = stack; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(direct, tmp->name) == 0)
            return (T_IND);
    my_puterror("The argument given to the instruction is invalid.\n");
    return (84);
}

args_type_t check_parameter_type(char const *arg, label_t *stack)
{
    if (arg[0] == 'r')
        return (check_register(arg) != 84) ? (T_REG) : (84);
    else if (arg[0] == DIRECT_CHAR)
        return (check_direct(arg, stack) != 84) ? (T_DIR) : (84);
    else
        return (check_indirect(arg, stack));
    return ('\0');
}

int check_parameter_type_(char const *arg)
{
    if (arg[0] == 'r')
        return (1);
    else if (arg[0] == DIRECT_CHAR)
        return (3);
    else
        return (2);
}
