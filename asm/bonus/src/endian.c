/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#include "asm.h"

u_int32_t change_endian_32(u_int32_t endian)
{
    endian = (((endian >> 24) & 0x000000ff) |
    ((endian << 8) & 0x00ff0000) |
    ((endian >> 8) & 0x0000ff00) |
    ((endian << 24) & 0xff000000));
    return (endian);
}

u_int16_t change_endian_16(u_int16_t endian)
{
    endian = ((endian >> 8) | (endian << 8));
    return (endian);
}
