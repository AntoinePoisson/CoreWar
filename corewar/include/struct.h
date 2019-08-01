/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** struct
*/

#ifndef COREWAR_STRUCT
#define COREWAR_STRUCT

#include "op.h"

enum pos_or_neg_e {P = 1, N = -1};

typedef struct instruct_s
{
    int old_pc;
    int new_pc;
    char **cmd;
} instruct_t;

typedef struct player_s
{
    int live;
    int cycle;
    int a;
    int n;
    char *name;
    long size;
    int carry;
    char *buffer;
    char *instruc;
    bool fork;
    unsigned int r[REG_NUMBER];
    struct instruct_s *instruct;
} player_t;

typedef struct corewar_s
{
    int last;
    int size_header;
    int nb_core;
    int dump;
    int nb_life;
    int *id;
    int *cycle_die;
    char **name_id;
    char *arena;
    player_t **champ;
    struct pointer_store_s *pointer_store;
} corewar_t;

#endif
