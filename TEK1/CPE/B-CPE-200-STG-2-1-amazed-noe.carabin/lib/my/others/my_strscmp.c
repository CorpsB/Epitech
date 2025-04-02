/*
** EPITECH PROJECT, 2023
** MY_STRNCMP
** File description:
** Compare two strings using ASCII next to the given number.
*/

#include "../../../include/my.h"
int my_strscmp(char const *s1, char const *s2, int i, int n)
{
    int t1 = 0;
    int t2 = 0;

    if (s1[0] == '\0' && s2[0] == '\0')
        return (0);
    for (int j = 0; j < n; ++j){
        t1 += s1[i + j];
        t2 += s2[j];
        if (s1[i + j] == '\0' || s2[j] == '\0')
            break;
    }
    return (t1 - t2);
}
