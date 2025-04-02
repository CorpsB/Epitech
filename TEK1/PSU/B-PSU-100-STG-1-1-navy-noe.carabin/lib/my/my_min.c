/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-thibaut.louis
** File description:
** my_min.c
*/

#include "../../include/my.h"

int my_min(int a, int b, int c)
{
    int min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}
