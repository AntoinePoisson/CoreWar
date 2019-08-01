/*
** EPITECH PROJECT, 2019
** lld.c
** File description:
** lld
*/

#include "op.h"
#include "asm.h"

int write_lld(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 12);
    write_parameter(var, instruct.args[0],
        check_parameter_type_(instruct.args[0]));
    write_parameter(var, instruct.args[1], 1);
    return (0);
}
