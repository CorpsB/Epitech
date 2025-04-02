/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-thibaut.louis
** File description:
** my_str_to_int.c
*/

#include "../../my.h"

int my_str_to_int(char *str)
{
    int result = 0;
    int chiffre;
    int i_max = 0;

    for (; str[i_max] != ' ' && str[i_max] != '\n' &&
    str[i_max] != '\0'; ++i_max);
    --i_max;
    for (int i = i_max; i > -1; --i){
        chiffre = str[i] - 48;
        result += (chiffre * my_compute_power_it(10, (i_max - i)));
    }
    return result;
}
