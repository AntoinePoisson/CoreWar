/*
** EPITECH PROJECT, 2019
** zjmp.c
** File description:
** zjmp
*/

#include "op.h"
#include "asm.h"

int write_zjmp(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 8);
    write_parameter(var, instruct.args[0], 2);
    return (0);
}
