/*
** EPITECH PROJECT, 2023
** MY_STRSTR
** File description:
** Search a pattern into a text and return the next occurence.
*/

#include "../../../include/my.h"
char *my_strstr(char *str, char const *pattern)
{
    int str_a_len = my_strlen(str);
    int find_len = my_strlen(pattern);

    if (find_len == 0 || str_a_len == 0)
        return (NULL);
    for (int i = 0; str[i] != '\0'; ++i)
        if (my_strncmp(&str[i], pattern, find_len) == 0)
            return (&str[i]);
    return (NULL);
}
