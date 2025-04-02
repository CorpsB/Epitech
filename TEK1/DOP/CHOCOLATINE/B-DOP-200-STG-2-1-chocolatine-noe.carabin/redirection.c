/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** redirection.c
*/

#include "my.h"

static int exit_func(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>' && str[i + 1] == '>')
            return 2;
    }
    return 1;
}

static int enter_func(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<' && str[i + 1] == '<')
            return 2;
    }
    return 1;
}

static int len_without_other_char(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == -126) {
            i++;
            continue;
        }
        i++;
        count++;
    }
    return count;
}

char *destroy(char *str, char searcher)
{
    int start = 0;
    int end = 0;
    char *result;
    int index = 0;

    for (; str[start] != searcher; start++);
    for (end = start; str[end] != '\0'; end++)
        if (str[end] == ' ' && (str[end - 1] != searcher))
            break;
    for (int i = start; i < end; i++)
        str[i] = 130;
    result = malloc(sizeof(char) * (len_without_other_char(str)));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == -126)
            continue;
        result[index] = str[i];
        index++;
    }
    result[index] = '\0';
    return result;
}

char *grab(char *str, char searcher)
{
    int start = 0;
    int end = 0;

    for (; str[start] != searcher; start++);
    if (str[start + 1] && str[start + 1] == searcher)
        start++;
    if (str[start + 1] && str[start + 1] == ' ')
        start++;
    start++;
    end = start;
    for (; str[end] != '\0'; end++) {
        if (str[end] == ' ')
            break;
    }
    return my_substr(str, start, end);
}

static char *grab_and_destroy(char *str, char searcher)
{
    char *result = NULL;

    result = grab(str, searcher);
    str = destroy(str, searcher);
    str = format_str(str, false);
    return result;
}

static void redirection_next(char **table, red_t *red)
{
    int size = table_len(table);

    if (red->exit) {
        red->ex_filepath = grab_and_destroy(table[size - 1], '>');
        red->ex_filepath = format_str(red->ex_filepath, false);
    }
    if (red->enter) {
        red->en_filepath = grab_and_destroy(table[0], '<');
        red->en_filepath = format_str(red->ex_filepath, false);
    }
}

void complete_redirection(pipe_t *pipe, char **table, red_t *red)
{
    int size = table_len(table);

    if (red->enter && enter_func(table[0]) == 2) {
        red->big_enter = true;
        red->little_enter = false;
    } else if (red->enter) {
        red->big_enter = false;
        red->little_enter = true;
    }
    if (red->exit && exit_func(table[size - 1]) == 2) {
        red->big_exit = true;
        red->little_exit = false;
    } else if (red->exit) {
        red->big_exit = false;
        red->little_exit = true;
    }
    redirection_next(table, red);
    pipe->red = red;
}
