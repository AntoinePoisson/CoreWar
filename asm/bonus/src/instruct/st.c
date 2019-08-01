/*
** EPITECH PROJECT, 2019
** st.c
** File description:
** st
*/

#include "op.h"
#include "asm.h"

int write_st(asm_t *var, instruct_t instruct)
{
    write_instruction_and_coding_byte(var, instruct.args, 2);
    write_parameter(var, instruct.args[0], 1);
    write_parameter(var, instruct.args[1],
        check_parameter_type_(instruct.args[1]));
    return (0);
}
