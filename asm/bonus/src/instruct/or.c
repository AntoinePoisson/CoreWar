/*
** EPITECH PROJECT, 2019
** or.c
** File description:
** or
*/

#include "op.h"
#include "asm.h"

int write_or(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 6);
    write_parameter(var, instruct.args[0],
        check_parameter_type_(instruct.args[0]));
    write_parameter(var, instruct.args[1],
        check_parameter_type_(instruct.args[1]));
    write_parameter(var, instruct.args[2], 1);
    return (0);
}
