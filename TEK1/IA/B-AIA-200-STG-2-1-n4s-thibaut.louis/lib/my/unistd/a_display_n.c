/*
** EPITECH PROJECT, 2023
** MY_SHOW_INT_ARRAY
** File description:
** Print an array of integers.
*/

#include "../../../include/my.h"

void a_display_n(int *array)
{
    for (int i = 0; array[i] != 0; ++i){
        my_putnbr(array[i], 1);
        my_putchar('\n', 1);
    }
}
