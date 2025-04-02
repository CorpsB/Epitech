/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** Print a string.
*/

#include "../../../include/base/my.h"
void my_putstr(char const *str, int port)
{
    write(port, str, my_strlen(str));
}

void my_lim_putstr(char const *str, int i)
{
    for (; str[i] != '\0'; ++i)
        write(1, &str[i], 1);
}
