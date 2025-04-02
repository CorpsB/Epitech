/*
** EPITECH PROJECT, 2024
** STRING PARSER
** File description:
** Parse strings using tokens.
*/

#include "../../include/shell.h"

static int skip_comment(char *line, int j)
{
    char c;

    if (line[j] == '"')
        c = '"';
    else if (line[j] == '\'')
        c = '\'';
    else
        c = '`';
    for (++j; line[j] != c && line[j] != '\0'; ++j);
    return j + 1;
}

static void error_case(cmd_data_t **data, char *line, int i, int c)
{
    if (i == 0 || *data == NULL)
        return;
    if (s_litsearch(SKIP_CHARS, line[i - 1]) != -1 && (*data)->TOKEN == c)
        l_cmd_add(data, NULL, ERROR_TOKEN);
}

void store_token(cmd_data_t **data, char *line, int i)
{
    switch (line[i]){
        case ';':
            return l_cmd_add(data, NULL, SEMICOLON_TOKEN);
        case '<':
            error_case(data, line, i, CHEVRON_LEFT_TOKEN);
            return l_cmd_add(data, NULL, CHEVRON_LEFT_TOKEN);
        case '>':
            error_case(data, line, i, CHEVRON_RIGHT_TOKEN);
            return l_cmd_add(data, NULL, CHEVRON_RIGHT_TOKEN);
        case '|':
            error_case(data, line, i, PIPE_TOKEN);
            return l_cmd_add(data, NULL, PIPE_TOKEN);
        case '&':
            error_case(data, line, i, AMPERSAND_TOKEN);
            return l_cmd_add(data, NULL, AMPERSAND_TOKEN);
        case '(':
            return l_cmd_add(data, NULL, PARENTHESE_START_TOKEN);
        case ')':
            return l_cmd_add(data, NULL, PARENTHESE_END_TOKEN);
    }
}

void store_value(cmd_data_t **data, char *line, int *i)
{
    int j = *i;
    char *arg;

    if (line[j] == '"' || line[j] == '\'' || line[j] == '`')
        j = skip_comment(line, j);
    else
        for (; s_litsearch(ALLOWED_TOKENS, line[j]) == -1 && line[j] != ';' &&
        s_litsearch(SKIP_CHARS, line[j]) == -1 && line[j] != '\0'; ++j);
    arg = my_substr(line, *i, j);
    if (*data != NULL && ((*data)->TOKEN == COMMAND_TOKEN ||
    (*data)->TOKEN == COMMAND_ARG_TOKEN) &&
    (*data)->TOKEN != SEMICOLON_TOKEN && (*data)->TOKEN != PIPE_TOKEN)
        l_cmd_add(data, arg, COMMAND_ARG_TOKEN);
    else
        l_cmd_add(data, arg, COMMAND_TOKEN);
    *i = j - 1;
}

void remove_inhibitors(cmd_data_t *data)
{
    char first_char;
    size_t len;

    for (cmd_data_t *tmp = data; tmp != NULL; tmp = tmp->next) {
        if (tmp->TOKEN != COMMAND_TOKEN && tmp->TOKEN != COMMAND_ARG_TOKEN)
            continue;
        first_char = tmp->value[0];
        len = my_strlen(tmp->value);
        if ((first_char == '\'' || first_char == '\"') &&
            len >= 2 && first_char == tmp->value[len - 1]) {
            memmove(tmp->value, tmp->value + 1, len - 2);
            tmp->value[len - 2] = '\0';
        }
    }
}

static int parse_data_next(cmd_data_t **data, char *line,
    storage_bag_t *storage)
{
    if (reveal_variables(storage, *data) == ERR)
        return ERR;
    redirect_aliases(storage, data);
    if (count_paranthesis(line) == ERR)
        return ERR;
    if (check_parenthese(storage, data, line) == ERR)
        return ERR;
    replace_backticks(storage, data);
    while (extract_parentheses(data, storage));
    return 0;
}

int parse_data(cmd_data_t **data, char *line, storage_bag_t *storage)
{
    for (int i = 0; line[i] != '\0'; ++i){
        if (s_litsearch(ALLOWED_TOKENS, line[i]) != -1 || line[i] == ';'){
            store_token(data, line, i);
            continue;
        }
        if (s_litsearch(SKIP_CHARS, line[i]) == -1)
            store_value(data, line, &i);
    }
    l_cmd_reverse(data);
    if (redirect_history(storage, *data))
        return ERR;
    if (storage->allow_history == true)
        history(storage, *data);
    remove_inhibitors(*data);
    if (parse_data_next(data, line, storage) == ERR)
        return ERR;
    return 0;
}
