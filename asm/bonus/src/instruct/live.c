/*
** EPITECH PROJECT, 2019
** live.c
** File description:
** live
*/

#include "op.h"
#include "asm.h"

int write_live(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 0);
    write_parameter(var, instruct.args[0], 3);
    return (0);
}