/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** tools2.c
*/

#include "my.h"

int my_strcmp(char *name1, char *name2)
{
    int i = 0;

    for (; name1[i] != '\0' && name2[i] != '\0'; i++) {
        if (name1[i] == name2[i]) {
            continue;
        }
        return (name1[i] - name2[i]);
    }
    if (name1[i] != '\0' || name2[i] != '\0') {
        return (name1[i] - name2[i]);
    }
    return (0);
}

int get_table_size(char **table)
{
    int i = 0;

    for (; table[i] != NULL; i++);
    return i;
}
