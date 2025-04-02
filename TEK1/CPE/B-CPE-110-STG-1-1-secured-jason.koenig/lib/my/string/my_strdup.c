/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** Create a place into the memory for the given string.
*/

#include "../../../include/my.h"
char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (src_len + 1));
    if (str == NULL)
        return (NULL);
    for (; i < src_len; ++i)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
