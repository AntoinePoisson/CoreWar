/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

int find_type_of_arg(char const *arg, int instruct);
int check_parameter_type_(char const *arg);
int help_flag(char const *av0, char const *av1);
void write_parameter(asm_t *var, char const *parameter, int cas);
int check_register_(char const *regist);
int check_direct_(char const *direct);
int write_instruction_and_coding_byte(asm_t *var, char **arg, int cas);
int write_add(asm_t *var, instruct_t instruct);
int write_aff(asm_t *var, instruct_t instruct);
int write_and(asm_t *var, instruct_t instruct);
int write_fork(asm_t *var, instruct_t instruct);
int write_ld(asm_t *var, instruct_t instruct);
int write_ldi(asm_t *var, instruct_t instruct);
int write_lfork(asm_t *var, instruct_t instruct);
int write_live(asm_t *var, instruct_t instruct);
int write_lld(asm_t *var, instruct_t instruct);
int write_lldi(asm_t *var, instruct_t instruct);
int write_or(asm_t *var, instruct_t instruct);
int write_st(asm_t *var, instruct_t instruct);
int write_sti(asm_t *var, instruct_t instruct);
int write_sub(asm_t *var, instruct_t instruct);
int write_xor(asm_t *var, instruct_t instruct);
int write_zjmp(asm_t *var, instruct_t instruct);
int write_data(asm_t *var, label_t *label);
char calcul_coding_byte(char **arg);
label_t *rev_list(label_t **label);
int check_error_in_file(asm_t *var);
char **management_tab(char **tab);
int assembly(char const *av);
char **free_tab_two(char **str);
int write_prog_size(asm_t *var);
char **tab_realloc(char **tab);
int management_header(asm_t *var, int *i);
char **fill_tab(char const *av);
int create_file(char const *file);
u_int32_t change_endian_32(u_int32_t endian);
u_int16_t change_endian_16(u_int16_t endian);
int check_error_header(asm_t *var, int *i);
char **strtoarr(char const *, char);
char *mstrchr(char *s, int c);
int prog_size(asm_t *var);
int is_wrong_label(label_t *labels);
instruct_t *stack_instruct(char **buf, char **file, int a);
int stack_labels(char **file, label_t **labels, int index);
int is_wrong_champ(asm_t *var, label_t **labels);
int is_wrong_parameters(label_t *labels);
args_type_t check_parameter_type(char const *arg, label_t *stack);

#endif
