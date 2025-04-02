/*
** EPITECH PROJECT, 2023
** MY_SUBSTR
** File description:
** Copy a given amout of characters of a string
** into an other one using a start and end position.
*/

#include "../../../include/my.h"
char *my_substr(char const *str, int y, int x)
{
    char *result = malloc((sizeof(char) * (x - y)) + 1);
    int i = 0;

    if (result == NULL)
        return NULL;
    for (; y < x && str[y] != '\0'; ++i) {
        result[i] = str[y];
        ++y;
    }
    result[i] = '\0';
    return result;
}
