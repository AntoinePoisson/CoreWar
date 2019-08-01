/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#ifndef MY_H
#define MY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "asm.h"

typedef struct pointer_store_s
{
    void *pointer;
    struct pointer_store_s *next;
} pointer_store_t;

asm_t *init_garbage_collector(asm_t *assembly_pointer);
void my_exit(int number);
int my_free(void *pointer);
void empty_garbage_collector(void);
int my_compute_power_rec(int nb, int p);
char *my_revstr(char *str);
int my_isnum(char const *s);
void my_putchar(char const c);
void my_put_nbr(long nb);
int my_printf(char const *format, ...);
int my_atoi(char const *str);
int my_puterror(char const *str);
int my_putstr(char const *str);
int my_strncmp(char const *s1, char const *s2, int const n);
int my_strcmp(char const *s1, char const *s2);
int my_strncpy(char *dest, char const *src, int const nb);
int my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *s);
int my_isnum(char const *s);
void *my_malloc(size_t size, int fill);
char *my_itoa(long nb);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcat(char *dest, char const *src);
char *my_strndup(char const *str, int nb);
char *my_strdup(char const *str);
char *get_next_line(int fd);
char *my_strchr(char *s, int c);
char **my_str_to_selec_array(char const *str, char element);
char **my_str_to_word_array(char const *str, char const *delimiter);

#endif
