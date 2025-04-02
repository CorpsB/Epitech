/*
** EPITECH PROJECT, 2023
** MY_SHOW_INT_ARRAY
** File description:
** Print an array of integers.
*/

#include "../../../include/my.h"
int my_show_int_array(int *tab)
{
    for (int i = 0; tab[i] != 0; ++i){
        my_putnbr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
