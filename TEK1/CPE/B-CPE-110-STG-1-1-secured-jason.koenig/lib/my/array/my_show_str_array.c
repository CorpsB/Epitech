/*
** EPITECH PROJECT, 2023
** MY_SHOW_STR_ARRAY
** File description:
** Print an array of strings.
*/

#include "../../../include/my.h"
int my_show_str_array(char **tab)
{
    for (int i = 0; tab[i] != 0; ++i){
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
