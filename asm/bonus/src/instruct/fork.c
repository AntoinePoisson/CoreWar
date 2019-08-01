/*
** EPITECH PROJECT, 2019
** fork.c
** File description:
** fork
*/

#include "op.h"
#include "asm.h"

int write_fork(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 11);
    write_parameter(var, instruct.args[0], 2);
    return (0);
}
