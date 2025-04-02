/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-noe.carabin
** File description:
** map_fenerator.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0' ; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

int calcul(int nb, int p)
{
    int result;

    if (p == 0) {
        return (nb);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

int my_compute_power_rec(int nb, int p)
{
    if (nb == 0 || p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    return (calcul(nb, p));
}

static void init_newstr(struct int_table_information *newstr, int nbr)
{
    newstr->size = nbr;
    newstr->ta = malloc(sizeof(int) * nbr);
    newstr->count = 0;
    newstr->first_len = 0;
    newstr->loc = 0;
}

static void pre_init_struct(char *map, int nbr, struct moving_string *str)
{
    struct Best Best_square;
    struct define_min s_min;
    struct int_table_information *newstr =
    malloc(sizeof(struct int_table_information));

    str->string = malloc(sizeof(char) * nbr + 1);
    str->string[nbr] = '\0';
    str->string = map;
    init_newstr(newstr, nbr);
    str->cpt = 0;
    s_min.a = 0;
    s_min.b = 0;
    s_min.c = 0;
    s_min.minimal = 0;
    Best_square.b_larg = 0;
    Best_square.b_co = 0;
    setting_first(&Best_square, &s_min, newstr, str);
    free(newstr->ta);
}

char *gen(int a, char *give, struct moving_string *str)
{
    int patter_index = 0;
    int line_counter = 0;
    char *map = malloc(sizeof(char) * (a * a + a + 1));
    int i = 0;

    for (; i < (a * a + a); i++) {
        if (line_counter <= a) {
            map[i] = give[patter_index];
            line_counter++;
            patter_index++;
        }
        if (line_counter > a) {
            line_counter = 0;
            map[i] = '\n';
        }
        if (give[patter_index] == '\0')
            patter_index = 0;
    }
    map[i] = '\0';
    pre_init_struct(map, a * a + a + 1, str);
}

void argument_selector(char *number, char *give, struct moving_string *str)
{
    int nbr = 0;

    if (number[0] <= '-' && number[0] == '0') {
        my_putstr("Can't generate a negative or null map");
        str->error = 84;
        return;
    }
    for (int cpt = 0; number[cpt] != '\0'; cpt++) {
        nbr += (number[my_strlen(number) - cpt - 1] - 48) *
        my_compute_power_rec(10, cpt);
    }
    gen(nbr, give, str);
    return;
}
