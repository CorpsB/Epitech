/*
** EPITECH PROJECT, 2023
** MY_SHOW_STR_ARRAY
** File description:
** Print an array of strings.
*/

#include "../../../include/my.h"

void a_display_s(char **array)
{
    for (int i = 0; array[i] != 0; ++i){
        my_putchar('|', 1);
        my_putstr(array[i], 1);
        my_putchar('|', 1);
        my_putchar('\n', 1);
    }
}
