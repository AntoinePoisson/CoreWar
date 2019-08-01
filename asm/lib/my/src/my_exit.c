/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** libmy
*/

#include "my.h"

void my_exit(int number)
{
    empty_garbage_collector();
    exit(number);
}
