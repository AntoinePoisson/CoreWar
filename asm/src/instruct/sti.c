/*
** EPITECH PROJECT, 2019
** sti.c
** File description:
** sti
*/

#include "op.h"
#include "asm.h"

int write_sti(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 10);
    write_parameter(var, instruct.args[0], 1);
    if (check_parameter_type_(instruct.args[1]) == 2 ||
        check_parameter_type_(instruct.args[1]) == 3)
        write_parameter(var, instruct.args[1], 2);
    else
        write_parameter(var, instruct.args[1], 1);
    if (check_parameter_type_(instruct.args[2]) == 3 ||
        check_parameter_type_(instruct.args[2]) == 2)
        write_parameter(var, instruct.args[2], 2);
    else
        write_parameter(var, instruct.args[2], 1);
    return (0);
}
