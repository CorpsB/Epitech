/*
** EPITECH PROJECT, 2023
** PSU2
** File description:
** exec.c
*/

#include "my.h"
#include <string.h>

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0'; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

static int str_len_to(char *str, int index, char separator)
{
    int a = index;

    for (; str[index] != '\0' && str[index] != separator; index++);
    return (index - a);
}

static char **str_to_array(char *map, char sep)
{
    char **result = malloc(sizeof(char *) * (my_strlen(map) + 1));
    int column = 0;
    int li = 0;

    for (int index = 0; map[index] != '\0'; index++) {
        result[li] = malloc(sizeof(char) * (str_len_to(map, index, sep) + 1));
        for (; map[index] != sep && map[index] != '\0'; index++) {
            result[li][column] = map[index];
            column++;
        }
        result[li][column] = '\0';
        li++;
        column = 0;
        if (map[index] == '\0')
            break;
    }
    printf("Nb args : %i\n", li);
    result[li] = NULL;
    return result;
}

static void print_arg(char *str, char **env, int p_pid)
{
    int i = 0;
    char *filepath;
    char **flag_array;

    for (; str[i] != ' ' && str[i] != '\0'; i++)
    filepath = malloc(sizeof(char) * (i + 2));
    filepath[i] = '\0';
    i = 0;
    for (; str[i] != ' ' && str[i] != '\0'; i++) {
        filepath[i] = str[i];
    }
    printf("Program name : %s\n", filepath);
    printf("PID : %i\n", p_pid);
    printf("Children PID : %i\n", getpid());
    flag_array = malloc(sizeof(char *) * my_strlen(str) + 2);
    flag_array[my_strlen(str)] = NULL;
    flag_array = str_to_array(str, ' ');
    printf("Children PID : %i\n", getpid());
    execve(filepath, flag_array, env);
    printf("Program terminated\n");
}

int main(int ac, char **av, char **env)
{
    pid_t pid;
    int status;
    int parent_pid = getpid();

    pid = fork();
    if (pid == 0) {
        print_arg(av[1], env, parent_pid);
        return 0;
    }
    wait(&status);
    printf("Program terminated\n");
    if (WIFEXITED(status)) {
        printf("Status : OK\n");
    } else {
        printf("Status : SEGMENTATION FAULT\n");
    }
    return 0;
}