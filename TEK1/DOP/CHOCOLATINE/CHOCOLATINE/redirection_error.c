/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** redirection_exit.c
*/

#include "my.h"

static bool little_redirection_next(char **sub_table, int i)
{
    if (sub_table[i][0] == '<' || sub_table[i][0] == '>') {
        if (my_strlen(sub_table[i]) >= 3)
            return true;
        if (my_strlen(sub_table[i]) == 2 && sub_table[i][1] != '<' ||
            sub_table[i][1] != '>')
            return true;
    }
    return false;
}

static bool little_redirection(char **sub_table)
{
    for (int i = 0; sub_table[i] != NULL; i++) {
        if (little_redirection_next(sub_table, i))
            return true;
    }
    return false;
}

static bool is_sequence_followed_by_space_or_word(char *str,
    int start_index, int seq_length)
{
    int nextIndex = start_index + seq_length;

    if (str[nextIndex] == ' ') {
        nextIndex++;
    }
    if ((str[nextIndex] >= 'a' && str[nextIndex] <= 'z') ||
        (str[nextIndex] >= 'A' && str[nextIndex] <= 'Z')) {
        return true;
    }
    return false;
}

static bool check_for_redirection(char *str, const char *redirection,
    int start_index)
{
    int len = my_strlen(redirection);

    for (int k = 0; k < len; ++k) {
        if (str[start_index + k] != redirection[k]) {
            return false;
        }
    }
    if (is_sequence_followed_by_space_or_word(str, start_index, len)) {
        return true;
    }
    return false;
}

bool is_no_name_next(char *str, char **redirection, int numRedirections, int i)
{
    for (int j = 0; j < numRedirections; ++j) {
        if (check_for_redirection(str, redirection[j], i)) {
            return false;
        }
    }
    return true;
}

bool is_no_name(char *str)
{
    char *redirections[] = { "<", "<<", ">", ">>" };
    int numRedirections = sizeof(redirections) / sizeof(redirections[0]);

    if (!char_searcher(str, '>') && !char_searcher(str, '<'))
        return false;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!is_no_name_next(str, redirections, numRedirections, i))
            return false;
    }
    return true;
}

static bool is_error_next(char **table)
{
    char **sub_table;

    for (int i = 0; table[i] != NULL; i++) {
        sub_table = str_to_array(table[i], ' ');
        if (table_len(sub_table) == 1) {
            my_putstr("Missing name for redirect.\n");
            return true;
        }
        if (is_no_name(table[0])) {
            my_putstr("Missing name for redirect.\n");
            return true;
        }
        if (table_len(table) != 1 && is_no_name(table[table_len(table) - 1])) {
            my_putstr("Missing name for redirect.\n");
            return true;
        }
    }
    return false;
}

static bool ambigous_error(char **table, int size)
{
    for (int i = 1; i < size - 1; i++) {
        if (char_searcher(table[i], '>') || char_searcher(table[i], '<')) {
            my_putstr("Ambiguous output redirect.\n");
            return true;
        }
    }
    return false;
}

static bool is_error(int i, int size, char **table)
{
    if (char_searcher(table[0], '>') && table_len(table) != 1) {
        my_putstr("Ambiguous output redirect.\n");
        return true;
    }
    if (char_searcher(table[size - 1], '<') && table_len(table) != 1) {
        my_putstr("Ambiguous output redirect.\n");
        return true;
    }
    if (table[1] != NULL) {
        if (ambigous_error(table, size))
            return true;
    }
    return is_error_next(table);
}

bool redirection(pipe_t *pipe, int i, int size, char **table)
{
    bool is_exit_redirection = search_exit_redirection(table);
    bool is_enter_redirection = search_enter_redirection(table);
    red_t redirection;

    if (!is_exit_redirection && !is_enter_redirection)
        return false;
    if (is_error(i, size, table))
        exit(1);
    redirection.enter = is_enter_redirection;
    redirection.exit = is_exit_redirection;
    complete_redirection(pipe, table, &redirection);
    return true;
}
