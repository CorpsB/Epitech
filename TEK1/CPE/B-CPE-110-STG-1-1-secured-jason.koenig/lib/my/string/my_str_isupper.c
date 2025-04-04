/*
** EPITECH PROJECT, 2023
** MY_STR_ISUPPER
** File description:
** Check if there is only uppercase characters in a string.
*/

#include "../../../include/my.h"
int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
    return (1);
}
