/*
** EPITECH PROJECT, 2023
** MY_STR_ISPRINTABLE
** File description:
** Check if there is only printable characters in a string.
*/

#include "../../../include/my.h"
int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] <= 31 || str[i] == 127)
            return (0);
    return (1);
}
