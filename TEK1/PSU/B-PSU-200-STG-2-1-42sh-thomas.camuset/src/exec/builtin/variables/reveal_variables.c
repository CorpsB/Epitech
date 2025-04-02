/*
** EPITECH PROJECT, 2024
** DIRECTORY HANDLER
** File description:
** Change working directory.
*/

#include "../../../../include/shell.h"

static int is_alpha_letter(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') || c == '_')
        return 1;
    return 0;
}

static int store_new_value(cmd_data_t *tmp, char *new_value, int i, int j)
{
    char *new_name = my_substr(tmp->value, 0, i);
    char *new_name2 = my_substr(tmp->value, j, my_strlen(tmp->value));

    free(tmp->value);
    tmp->value = new_name;
    tmp->value = my_strcat(tmp->value, new_value);
    tmp->value = my_strcat(tmp->value, new_name2);
    free(new_name2);
    free(new_value);
    return 0;
}

static bool is_illegal_var_name(char *str)
{
    int i = 0;

    for (; str[i] != '\0' && is_alpha_letter(str[i]); ++i);
    if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
        return false;
    return msg(true, 2, 1, "Variable name must contain "
    "alphanumeric characters.\n");
}

static int analyse_token_next(cmd_data_t *tmp, int *i)
{
    for (; tmp->value[*i] != '\0' && tmp->value[*i] != '$'; ++(*i));
    if (tmp->value[*i] == '\0')
        return 0;
    if (is_illegal_var_name(&tmp->value[*i + 1]))
        return ERR;
    return -1;
}

int analyse_token(storage_bag_t *storage, cmd_data_t *tmp)
{
    char *new_name;
    char *new_value;
    int i = 0;
    int j = 0;
    int analyse = analyse_token_next(tmp, &i);

    if (analyse == ERR || analyse == 0)
        return (analyse == ERR) ? ERR : 0;
    for (j = i + 1; tmp->value[j] != '\0' &&
    s_search(SKIP_CHARS, tmp->value[j], tmp->value[j]) == -1; ++j);
    new_name = my_substr(tmp->value, i + 1, j);
    new_value = get_sys_variable(storage, new_name);
    if (new_value == NULL){
        msg(ERR, 2, 2, new_name, ": Undefined variable.\n");
        free(new_name);
        return ERR;
    }
    free(new_name);
    return store_new_value(tmp, new_value, i, j);
}

int reveal_variables(storage_bag_t *storage, cmd_data_t *line)
{
    int err_code = 0;

    for (cmd_data_t *tmp = line; tmp != NULL; tmp = tmp->next){
        if ((tmp->TOKEN == COMMAND_TOKEN || tmp->TOKEN == COMMAND_ARG_TOKEN) &&
        s_search(tmp->value, '$', '$') != 1 &&
        tmp->value[s_search(tmp->value, '$', '$') + 1] == '\0' &&
        tmp->next != NULL && (tmp->next->TOKEN == PARENTHESE_START_TOKEN ||
        tmp->next->TOKEN == PARENTHESE_END_TOKEN))
            return msg(ERR, 2, 1, "Illegal variable name.\n");
        if (tmp->TOKEN == COMMAND_TOKEN || tmp->TOKEN == COMMAND_ARG_TOKEN)
            err_code = analyse_token(storage, tmp);
        if (err_code != 0)
            return ERR;
    }
    return 0;
}
