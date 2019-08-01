/*
** EPITECH PROJECT, 2019
** add.c
** File description:
** add
*/

#include "op.h"
#include "asm.h"

int write_add(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 3);
    write_parameter(var, instruct.args[0], 1);
    write_parameter(var, instruct.args[1], 1);
    write_parameter(var, instruct.args[2], 1);
    return (0);
}
