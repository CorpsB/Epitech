/*
** EPITECH PROJECT, 2023
** PSU2
** File description:
** env.c
*/

#include <stddef.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
    for(int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }
}