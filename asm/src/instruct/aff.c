/*
** EPITECH PROJECT, 2019
** aff.c
** File description:
** aff
*/

#include "op.h"
#include "asm.h"

int write_aff(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 15);
    write_parameter(var, instruct.args[0], 1);
    return (0);
}