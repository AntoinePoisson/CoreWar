/*
** EPITECH PROJECT, 2019
** ldi.c
** File description:
** ldi
*/

#include "op.h"
#include "asm.h"

int write_ldi(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 9);
    if (check_parameter_type_(instruct.args[0]) == 1)
        write_parameter(var, instruct.args[0], 1);
    else
        write_parameter(var, instruct.args[0], 2);
    if (check_parameter_type_(instruct.args[1]) == 1)
        write_parameter(var, instruct.args[1], 1);
    else
        write_parameter(var, instruct.args[1], 2);
    write_parameter(var, instruct.args[2], 1);
    return (0);
}
