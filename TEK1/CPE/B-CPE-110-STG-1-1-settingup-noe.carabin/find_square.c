/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-noe.carabin
** File description:
** find_square.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "my.h"

static int replace(struct moving_string *str)
{
    switch (str->string[str->cpt]) {
    case '.':
        return (1);
    case 'o':
        return (0);
    case '\n':
    case '\0':
        return (-1);
    default:
    my_putstr("INVALID MAP : Map must only content '.' or 'o'");
    str->error = (84);
    }
}

static int my_strlen(struct moving_string *str)
{
    int i = 0;
    int char_number = 0;

    for (; str->string[i] != '\0'; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

static void if_point(struct define_min *s_min, struct Best *Best_square,
    struct int_table_information *newstr, struct moving_string *str)
{
    s_min->a = newstr->ta[newstr->loc - newstr->first_len];
    s_min->b = newstr->ta[newstr->loc - newstr->first_len - 1];
    s_min->c = newstr->ta[newstr->loc - 1];
    s_min->minimal = s_min->a;
    if (s_min->b < s_min->minimal) {
        s_min->minimal = s_min->b;
    }
    if (s_min->c < s_min->minimal) {
        s_min->minimal = s_min->c;
    }
    newstr->ta[newstr->loc] = s_min->minimal + 1;
    if (s_min->minimal + 1 > Best_square->b_larg) {
        Best_square->b_larg = s_min->minimal + 1;
        Best_square->b_co = str->cpt;
    }
}

static void place_the_best_square(struct Best *Best_square,
    struct int_table_information *newstr, struct moving_string *str)
{
    for (int line = 0; line < Best_square->b_larg; line++) {
        for (int compt = 0; compt != (Best_square->b_larg * (-1)); compt--) {
            str->string[(Best_square->b_co + compt) -
            (newstr->first_len * line)] = 'x';
        }
    }
}

static void finish(struct int_table_information *newstr,
    struct moving_string *str)
{
    str->final_size = newstr->size - (newstr->count + 1);
}

static int func(struct moving_string *str,
    struct int_table_information *newstr)
{
    if (str->string[str->cpt] == '\n') {
        newstr->ta[newstr->loc] = (-1);
        newstr->loc++;
        str->cpt++;
        if (str->string[str->cpt] == '\0') {
            return (4);
        }
        newstr->ta[newstr->loc] = replace(str);
        newstr->loc++;
        return (3);
    }
    return (0);
}

static void setting_second(struct moving_string *str,
    struct int_table_information *newstr,
    struct Best *Best_square, struct define_min *s_min)
{
    int ret = 0;

    for (; str->string[str->cpt] != '\0'; str->cpt++) {
        ret = func(str, newstr);
        if (ret == 3)
            continue;
        if (ret == 4)
            break;
        if (str->string[str->cpt] == 'o')
            newstr->ta[newstr->loc] = 0;
        if (str->string[str->cpt] == '.')
            if_point(s_min, Best_square, newstr, str);
        newstr->loc++;
    }
    place_the_best_square(Best_square, newstr, str);
    finish(newstr, str);
}

int setting_first(struct Best *Best_square, struct define_min *s_min,
    struct int_table_information *newstr, struct moving_string *str)
{
    for (; str->string[str->cpt] != '\n'; str->cpt++) {
        newstr->ta[newstr->loc] = replace(str);
        newstr->loc++;
    }
    newstr->first_len = newstr->loc + 1;
    setting_second(str, newstr, Best_square, s_min);
}

int init_struct(struct moving_string *str, struct stat *buf, int count)
{
    struct Best Best_square;
    struct define_min s_min;
    struct int_table_information newstr;

    newstr.size = buf->st_size;
    newstr.count = count;
    newstr.ta = malloc(sizeof(int) * (my_strlen(str)));
    newstr.first_len = 0;
    newstr.loc = 0;
    s_min.a = 0;
    s_min.b = 0;
    s_min.c = 0;
    s_min.minimal = 0;
    Best_square.b_larg = 0;
    Best_square.b_co = 0;
    setting_first(&Best_square, &s_min, &newstr, str);
    free(newstr.ta);
}
