/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct var_s {
    int ln;
    int a;
    char **b;
} var_t;

typedef struct instruct_s {
    char end;
    char name;
    char **args;
    int len;
} instruct_t;

typedef struct index_s {
    int b;
    int d;
    int c;
} index_t;

typedef struct label_s {
    char *name;
    int lines;
    instruct_t *instruct;
    struct label_s *next;
} label_t;

typedef struct asm_s {
    char **file;
    int fd;
    int posi;
    int label;
    int reg;
    int dir;
    int ind;
    label_t *label_list;
    struct pointer_store_s *pointer_store;
} asm_t;

#endif
