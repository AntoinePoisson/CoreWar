/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr.c
*/

#include "my.h"

static int nbrimpair(char const *chaine)
{
    int i = 0;
    int nbrimpair = 0;

    for (i = 0; chaine[i] != '\0'; i = i + 1) {
        if (chaine[i] == '-')
            nbrimpair = nbrimpair + 1;
    }
    if (nbrimpair % 2 == 0)
        return (1);
    else
        return (0);
}

static int place_recovery_two(int nbr_chiffre, char stokage[], int int_return)
{
    int p = 0;
    int b = 0;

    while (b < nbr_chiffre) {
        int_return += (stokage[b] - 48) * my_compute_power_rec(10, p);
        p++;
        b++;
    }
    return (int_return);
}

static int place_recovery_one(char const *str, int i, int int_return)
{
    int a = 0;
    int nbr_chiffre = 0;
    char stokage[my_strlen(str)];

    while (str[i] >= '0' && str[i] <= '9') {
        stokage[a] = str[i];
        nbr_chiffre++;
        a++;
        i++;
    }
    stokage[a] = '\0';
    my_revstr(stokage);
    return (place_recovery_two(nbr_chiffre, stokage, int_return));
}

int my_getnbr(char const *str)
{
    int int_return = 0;
    int first_chiffre = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= '0' && str[i] <= '9' && first_chiffre == 0) {
            int_return = place_recovery_one(str, i, int_return);
            first_chiffre++;
        }
    }
    if (first_chiffre == 0)
        return (0);
    if (nbrimpair(str) == 0)
        int_return = int_return * -1;
    return (int_return);
}
