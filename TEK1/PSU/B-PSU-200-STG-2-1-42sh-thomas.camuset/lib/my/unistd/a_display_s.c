/*
** EPITECH PROJECT, 2023
** MY_SHOW_STR_ARRAY
** File description:
** Print an array of strings.
*/

#include "../../../include/base/my.h"

void a_display_s(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; ++i){
        my_putstr(array[i], 1);
        my_putchar('\n', 1);
    }
}
