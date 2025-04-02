/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** my_str_cat.c
*/

#include <stdio.h>
#include "../../my.h"

char *my_str_cat(char *str1, char *str2, char sep)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));

    for (int i = 0; str1[i] != '\0'; i++) {
        tmp[j] = str1[i];
        j++;
    }
    tmp[j] = sep;
    j++;
    for (int i = 0; str2[i] != '\0'; i++) {
        tmp[j] = str2[i];
        j++;
    }
    tmp[j] = '\0';
    free(str1);
    return tmp;
}

char *my_str_cat2(char *str1, char *str2)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));

    for (int i = 0; str1[i] != '\0'; i++) {
        tmp[j] = str1[i];
        j++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        tmp[j] = str2[i];
        j++;
    }
    tmp[j] = '\0';
    free(str1);
    return tmp;
}

// int main(void)
// {
//     char *s1 = my_strdup("épi");
//     char *s2 = my_strdup("tech");
//     char *s4 = my_strdup("ls");
//     char s3 = '/';

//     s1 = my_str_cat(s1, s2, s3);
//     s1 = my_str_cat(s1, s4, s3);
//     printf("%s\n", s1);
//     free(s1);
//     free(s2);
//     free(s4);
//     return 0;
// }
