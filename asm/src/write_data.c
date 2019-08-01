/*
** EPITECH PROJECT, 2019
** parser.c
** File description:
** parse.c
*/

#include "op.h"
#include "asm.h"

static char number_of_instruction(int cas)
{
    switch (cas) {
        case 0: return (0x01);
        case 1: return (0x02);
        case 2: return (0x03);
        case 3: return (0x04);
        case 4: return (0x05);
        case 5: return (0x06);
        case 6: return (0x07);
        case 7: return (0x08);
        case 8: return (0x09);
        case 9: return (0x0a);
        case 10: return (0x0b);
        case 11: return (0x0c);
        case 12: return (0x0d);
        case 13: return (0x0e);
        case 14: return (0x0f);
        case 15: return (0x10);
        default: return (84);
    }
    return (84);
}

int write_instruction_and_coding_byte(asm_t *var, char **arg, int cas)
{
    char number = number_of_instruction(cas);
    char element = 0x00;

    if (number == 84)
        return (84);
    write(var->fd, &number, sizeof(number));
    var->posi += 1;
    var->reg += 1;
    if (cas == 0 || cas == 8 || cas == 11 || cas == 14)
        return (0);
    element = calcul_coding_byte(arg);
    var->posi += 1;
    var->reg += 1;
    write(var->fd, &element, sizeof(element));
    return (0);
}

int call_function_two(asm_t *var, instruct_t instruct)
{
    int cas = instruct.name;

    switch (cas) {
        case 14: return (write_lldi(var, instruct));
        case 15: return (write_lfork(var, instruct));
        case 16: return (write_aff(var, instruct));
        default: return (84);
    }
    return (84);
}

int call_function(asm_t *var, instruct_t instruct)
{
    int cas = instruct.name;

    switch (cas) {
        case 1: return (write_live(var, instruct));
        case 2: return (write_ld(var, instruct));
        case 3: return (write_st(var, instruct));
        case 4: return (write_add(var, instruct));
        case 5: return (write_sub(var, instruct));
        case 6: return (write_and(var, instruct));
        case 7: return (write_or(var, instruct));
        case 8: return (write_xor(var, instruct));
        case 9: return (write_zjmp(var, instruct));
        case 10: return (write_ldi(var, instruct));
        case 11: return (write_sti(var, instruct));
        case 12: return (write_fork(var, instruct));
        case 13: return (write_lld(var, instruct));
        default: return (call_function_two(var, instruct));
    }
    return (84);
}

int write_data(asm_t *var, label_t *element)
{
    label_t *label = element;
    int i = 0;
    var->label_list = element;

    if (management_header(var, &i) == 84)
        return (84);
    for (i = 0; label; label = label->next, i = 0) {
        for (; label->instruct[i].end != 1; i++) {
        var->label = var->reg + var->ind + var->dir;
        if (call_function(var, label->instruct[i]) == 84)
            return (84);
        }
    }
    return (0);
}
