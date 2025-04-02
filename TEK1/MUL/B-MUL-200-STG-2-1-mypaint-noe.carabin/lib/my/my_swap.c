/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** my_swap
*/

#include "../../includes/my.h"

void my_swap(int *a, int *b)
{
    int c = *a;
    int d = *b;

    *a = d;
    *b = c;
}
