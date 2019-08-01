/*
** EPITECH PROJECT, 2019
** asm
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include "asm.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_asm, fill_tab, .init = redirect_all_stdout)
{
    char const *av = "no file here.";

    cr_assert_eq(fill_tab(av), NULL);
}

Test(test_asm, write_prog_size, .init = redirect_all_stdout)
{
    asm_t var = {NULL, 2, 0, 0, 2, 3, 1, NULL};

    cr_assert_eq(write_prog_size(&var), 0);
}

Test(test_asm, assembly, .init = redirect_all_stdout)
{
    char const *av = "tests/zork.s";

    cr_expect_eq(assembly(av), 0);
}

Test(test_asm, help_flag, .init = redirect_all_stdout)
{
    cr_expect_eq(help_flag("./asm", "-h"), 0);
    cr_expect_eq(help_flag("./asm", "not today."), 84);
}

Test(test_asm, instructs_first_part, .init = redirect_all_stdout)
{
    asm_t var = {NULL, 2, 3, 0, 10, 10, 10, NULL};
    instruct_t instrct = {0, 1, NULL, 1};

    instrct.args = malloc(sizeof(char *) * 4);
    instrct.args[0] = my_strdup("%:live");
    instrct.args[1] = my_strdup("3");
    instrct.args[2] = my_strdup("r5");
    instrct.args[3] = NULL;
    cr_expect_eq(write_add(&var, instrct), 0);
    cr_expect_eq(write_aff(&var, instrct), 0);
    cr_expect_eq(write_and(&var, instrct), 0);
    cr_expect_eq(write_fork(&var, instrct), 0);
    cr_expect_eq(write_ld(&var, instrct), 0);
    cr_expect_eq(write_ldi(&var, instrct), 0);
    cr_expect_eq(write_lfork(&var, instrct), 0);
    cr_expect_eq(write_live(&var, instrct), 0);
    cr_expect_eq(write_lld(&var, instrct), 0);
    for (int a = 0; instrct.args[a]; a++)
        free(instrct.args[a]);
    free(instrct.args);
}

Test(test_asm, instructs_second_part, .init = redirect_all_stdout)
{
    asm_t var = {NULL, 2, 3, 0, 10, 10, 10, NULL};
    instruct_t instrct = {0, 1, NULL, 1};

    instrct.args = malloc(sizeof(char *) * 4);
    instrct.args[0] = my_strdup("%:live");
    instrct.args[1] = my_strdup("3");
    instrct.args[2] = my_strdup("r5");
    instrct.args[3] = NULL;
    cr_expect_eq(write_lldi(&var, instrct), 0);
    cr_expect_eq(write_or(&var, instrct), 0);
    cr_expect_eq(write_st(&var, instrct), 0);
    cr_expect_eq(write_sti(&var, instrct), 0);
    cr_expect_eq(write_sub(&var, instrct), 0);
    cr_expect_eq(write_xor(&var, instrct), 0);
    cr_expect_eq(write_zjmp(&var, instrct), 0);
    for (int a = 0; instrct.args[a]; a++)
        free(instrct.args[a]);
    free(instrct.args);
}

Test(test_asm, check_parameter_type, .init = redirect_all_stdout)
{
    char const *reg = "r2";
    char const *dir = "%2";
    char const *ind = "3";

    cr_expect_eq(check_parameter_type(reg, NULL), T_REG);
    cr_expect_eq(check_parameter_type(dir, NULL), T_DIR);
    cr_expect_eq(check_parameter_type(ind, NULL), T_IND);
}

Test(test_asm, management_tab, .init = redirect_all_stdout)
{
    char **tab = NULL;

    cr_assert_eq(management_tab(tab), NULL);
}
