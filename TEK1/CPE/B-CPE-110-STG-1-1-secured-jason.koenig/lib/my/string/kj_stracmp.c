/*
** EPITECH PROJECT, 2023
** MY_STRCMP
** File description:
** Compare a string with an other one using ASCII.
*/

#include "../../../include/my.h"
static char verif_char(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    else
        return (c);
}

int kj_stracmp(char const *s1, char const *s2)
{
    int t1 = 0;
    int t2 = 0;

    if (s1[0] == '\0' && s2[0] == '\0')
        return (0);
    for (int i = 0; t1 == t2; ++i){
        t1 += verif_char(s1[i]);
        t2 += verif_char(s2[i]);
        if (s1[i] == '\0' && s2[i] == '\0')
            break;
    }
    return (t1 - t2);
}
