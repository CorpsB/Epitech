/*
** EPITECH PROJECT, 2023
** MY_SWAP
** File description:
** Chang two different var
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
