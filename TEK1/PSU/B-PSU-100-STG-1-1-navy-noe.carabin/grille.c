/*
** EPITECH PROJECT, 2023
** Create a table
** File description:
** grille.c
*/

#include <stdlib.h>

static int my_strlen(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return (count);
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **crate_table(void)
{
    char init_line[9] = "........\0";
    char **table = malloc(sizeof(char *) * 63);

    for (int i = 0; i <= 7; i++) {
        table[i] = malloc(sizeof(char) * 9);
        my_strcpy(table[i], init_line);
    }
    return table;
}
