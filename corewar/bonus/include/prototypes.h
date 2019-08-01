/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

/* lib */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <curses.h>

#include "struct.h"

/* Read Instruction */
short char_to_short(char one, char two);
int char_to_int(char one, char two, char three, char four);
int read_coding_byte(char *map, int *pc);
int check_instruct_always_true(corewar_t *core, int i);
char **read_lfork(char *map, int *new_posi, int instruct);
char **read_lldi(char *map, int *new_posi, int instruct);
char **read_fork(char *map, int *new_posi, int instruct);
char **read_sti(char *map, int *new_posi, int instruct);
char **read_ldi(char *map, int *new_posi, int instruct);
char **read_zjmp(char *map, int *new_posi, int instruct);
char **read_live(char *map, int *new_posi, int instruct);
char **interpret_coding_byte(char *map, int *new_posi, int instruct);
char *read_char(char *map, int *pc, int cas);
char *reword_neg_read_short(char *result);
char *read_short(char *map, int *pc);
char *reword_neg_read_int(char *result);
char *read_int(char *map, int *pc);
char **create_tab_two(int nbr_parametre);
char **special_case(char *map, int *new_posi, int instruct);
int find_posi_new_pc_instruction(char *map, int pc, int *new_posi);
char **find_data(char *map, int *pc, int *new_posi);
instruct_t *find_instruction(corewar_t *core, int pc,
    instruct_t *instruct, int i);

/* VM */
char *char_to_binary_str(unsigned char c);
char *get_file(char const *name, long *size, char **c_name);
int corewar(int ac, char **av);
int count_cor(char **av);
int check_cor(char *av);
bool parsing_error(int ac, char **av);
void display_curses(corewar_t *core);
void parser(int ac, char **av, corewar_t *corewar);
void print_map(char const *str);
void init_arena(corewar_t *core);
void game_loop(corewar_t *core);
void free_array(char **tab);
void apply_instruct(corewar_t *core);

/* Instructions */
bool check_only_number(char *str);
bool check_number_or_register(char *str);
bool check_only_register(char *str);
void live(corewar_t *core, char **tab, int i);
void ld(corewar_t *core, char **tab, int i);
void st(corewar_t *core, char **tab, int i);
void add(corewar_t *core, char **tab, int i);
void sub(corewar_t *core, char **tab, int i);
void and(corewar_t *core, char **tab, int i);
void or(corewar_t *core, char **tab, int i);
void xor(corewar_t *core, char **tab, int i);
void zjmp(corewar_t *core, char **tab, int i);
void ldi(corewar_t *core, char **tab, int i);
void sti(corewar_t *core, char **tab, int i);
void my_fork(corewar_t *core, char **tab, int i);
void lld(corewar_t *core, char **tab, int i);
void lldi(corewar_t *core, char **tab, int i);
void lfork(corewar_t *core, char **tab, int i);
void aff(corewar_t *core, char **tab, int i);
int register_or_not(char *str);
int write_value(int value, char *mem, unsigned int index);

int display_help(char *av);

#endif
