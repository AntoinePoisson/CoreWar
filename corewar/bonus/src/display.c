/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

void activate_color_corewar(corewar_t *core, int j, bool check)
{
    if (check == true) {
        if ((unsigned char)core->arena[j] > 0)
            attron(COLOR_PAIR(6));
    } else {
        if ((unsigned char)core->arena[j] > 0)
            attroff(COLOR_PAIR(6));
    }
}

void display_curses(corewar_t *core)
{
    unsigned int j = 0;
    int y = 0;
    int x = 0;
    char *str = "0123456789ABCDEF";

    clear();
    while (j < MEM_SIZE) {
        for (x = 0; x < 32; x++, j++) {
            activate_color_corewar(core, j, true);
            mvprintw(y, x * 3, "%c%c", str[((unsigned char)core->arena[j])
            / 16], str[((unsigned char)core->arena[j]) % 16]);
            activate_color_corewar(core, j, false);
        }
        y += 1;
    }
    mvprintw(2, 102, "Cycle: %d", core->nb_cycle);
    refresh();
    usleep(50000);
}

void print_map(char const *str)
{
    unsigned short i = 0;
    unsigned int j = 0;

    while (j < MEM_SIZE) {
        for (i = 0; i < 32; i++, j++) {
            my_printf((str[j]) ? "\033[1;33m" : "");
            my_printf("%c%x", (i == 0) ? '\0' : ' ', str[j]);
            my_printf("\033[0m");
        }
        my_printf("\n");
    }
    my_printf("\n");
}
