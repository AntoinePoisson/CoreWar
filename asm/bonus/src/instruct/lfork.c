/*
** EPITECH PROJECT, 2019
** lfork.c
** File description:
** lfork
*/

#include "op.h"
#include "asm.h"

int write_lfork(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 14);
    write_parameter(var, instruct.args[0], 2);
    return (0);
}
