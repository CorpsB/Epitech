/*
** EPITECH PROJECT, 2023
** MY_STR_ISLOWER
** File description:
** Check if the is only lowercase characters in a string.
*/

#include "../../../include/my.h"
int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return (0);
    return (1);
}
