/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parsing_error, test_normal_1, .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 4);

    av[0] = strdup("./corewar");
    av[1] = strdup("zork.cor");
    av[2] = strdup("thanos.cor");
    av[3] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(3, av), false);
}

Test(parsing_error, test_normal_2, .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 10);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("42");
    av[3] = strdup("-a");
    av[4] = strdup("21");
    av[5] = strdup("-n");
    av[6] = strdup("12");
    av[7] = strdup("zork.cor");
    av[8] = strdup("thanos.cor");
    av[9] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(9, av), false);
}

Test(parsing_error, test_normal_3, .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 10);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("42");
    av[3] = strdup("zorky.cor");
    av[4] = strdup("zorkos.cor");
    av[5] = strdup("-n");
    av[6] = strdup("12");
    av[7] = strdup("zork.cor");
    av[8] = strdup("thanos.cor");
    av[9] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(9, av), false);
}

Test(parsing_error, test_error_not_enough_champions,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 9);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("42");
    av[3] = strdup("-a");
    av[4] = strdup("21");
    av[5] = strdup("-n");
    av[6] = strdup("12");
    av[7] = strdup("zork.cor");
    av[8] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(8, av), true);
}

Test(parsing_error, test_error_no_parameter_after_parameter1,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 9);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("42");
    av[3] = strdup("zork.cor");
    av[4] = strdup("thanos.cor");
    av[5] = strdup("-a");
    av[6] = strdup("21");
    av[7] = strdup("-n");
    av[8] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(8, av), true);
}

Test(parsing_error, test_error_no_parameter_after_parameter2,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 9);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("42");
    av[3] = strdup("zork.cor");
    av[4] = strdup("-n");
    av[5] = strdup("84");
    av[6] = strdup("thanos.cor");
    av[7] = strdup("-a");
    av[8] = NULL;
    init_garbage_collector(&core);
    parsing_error(8, av);
}

Test(parsing_error, test_error_no_parameter_after_parameter3,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 9);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("zork.cor");
    av[3] = strdup("-n");
    av[4] = strdup("84");
    av[5] = strdup("-a");
    av[6] = strdup("42");
    av[7] = strdup("thanos.cor");
    av[8] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(8, av), true);
}

Test(parsing_error, test_error_no_parameter_after_parameter4,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 9);

    av[0] = strdup("./corewar");
    av[1] = strdup("-n");
    av[2] = strdup("84");
    av[3] = strdup("zork.cor");
    av[4] = strdup("-a");
    av[5] = strdup("42");
    av[6] = strdup("thanos.cor");
    av[7] = strdup("-dump");
    av[8] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(8, av), true);
}

Test(parsing_error, test_error_parameter_isnt_right,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 10);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("84");
    av[3] = strdup("-n");
    av[4] = strdup("84");
    av[5] = strdup("zork.cor");
    av[6] = strdup("-a");
    av[7] = strdup("random_thing");
    av[8] = strdup("thanos.cor");
    av[9] = NULL;
    init_garbage_collector(&core);
    parsing_error(9, av);
}

Test(parsing_error, test_error_parameter_isnt_right2,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 10);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("84");
    av[3] = strdup("-n");
    av[4] = strdup("random_thing");
    av[5] = strdup("zork.cor");
    av[6] = strdup("-a");
    av[7] = strdup("84");
    av[8] = strdup("thanos.cor");
    av[9] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(9, av), true);
}

Test(parsing_error, test_error_parameter_isnt_right3,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 10);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = strdup("random_thing");
    av[3] = strdup("-n");
    av[4] = strdup("84");
    av[5] = strdup("zork.cor");
    av[6] = strdup("-a");
    av[7] = strdup("84");
    av[8] = strdup("thanos.cor");
    av[9] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(9, av), true);
}

Test(parsing_error, test_error_parameter_isnt_right4,
    .init = redirect_all_stdout)
{
    corewar_t core = {0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    char **av = malloc(sizeof(char *) * 3);

    av[0] = strdup("./corewar");
    av[1] = strdup("-dump");
    av[2] = NULL;
    init_garbage_collector(&core);
    cr_assert_eq(parsing_error(2, av), true);
}

Test(corewar, display_help, .init = redirect_all_stdout)
{
    cr_expect_eq(display_help("corewar"), 0);
}

Test(corewar, main_function, .init = redirect_all_stdout)
{
    char *av[2] = {"./corewar", "-h"};
    char *av_bis[4] = {"./corewar", "tests/add.cor", "tests/add.cor", NULL};

    cr_expect_eq(corewar(1, NULL), 84);
    cr_expect_eq(corewar(2, av), 0);
    cr_expect_eq(corewar(3, av_bis), 0);
}

Test(corewar, write_value, .init = redirect_all_stdout)
{
    char mem[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

    cr_expect_eq(write_value(12, mem, 2), 0);
}
