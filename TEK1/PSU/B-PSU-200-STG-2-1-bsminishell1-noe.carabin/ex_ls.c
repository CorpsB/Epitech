/*
** EPITECH PROJECT, 2023
** PSU2
** File description:
** ex_ls.c
*/

#include <unistd.h>

int main(int ac, char **av, char **env)
{
    execve("/bin/ls", NULL, env);
}