/*
** EPITECH PROJECT, 2023
** MY_STRNCMP
** File description:
** Compare two strings using ASCII next to the given number.
*/

#include "../../../include/my.h"
int my_strncmp(char const *s1, char const *s2, int n)
{
    int t1 = 0;
    int t2 = 0;

    if (s1[0] == '\0' && s2[0] == '\0')
        return (0);
    for (int i = 0; t1 == t2 && i < n; ++i){
        t1 += s1[i];
        t2 += s2[i];
        if (s1[i] == '\0' && s2[i] == '\0')
            break;
    }
    return (t1 - t2);
}
