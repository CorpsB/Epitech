/*
** EPITECH PROJECT, 2023
** MY_SUBSTR
** File description:
** Copy a given amout of characters of a string
** into an other one using a start and end position.
*/

#include "../../../include/my.h"
char *my_substr(char const *str, int j, int k)
{
    char *result = malloc((sizeof(char) * (k - j)) + 1);
    int i = 0;

    for (; j < k && str[j] != '\0'; ++i) {
        result[i] = str[j];
        ++j;
    }
    result[i] = '\0';
    return result;
}
