/*
** EPITECH PROJECT, 2023
** PSU2
** File description:
** segmentation.c
*/

#include "my.h"

static void print_arg(char *str)
{
    int i = 0;

    for (; str[i] != ' ' && str[i] != '\0'; i++)
        printf("%c", str[i]);
    printf("\n");
    if (str[i] != '\0')
        i++;
    for (; str[i] != '\0'; i++)
        printf("%c", str[i]);
    printf("\n");
}

int main(int ac, char **av, char **env)
{
    print_arg(av[1]);
    return 0;
}