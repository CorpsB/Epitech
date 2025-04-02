/*
** EPITECH PROJECT, 2024
** INHIBITORS
** File description:
** Things that ignore parsing.
*/

#include "../../../include/shell.h"

void parenthese_builder(pipe_data_t *data, cmd_data_t *line)
{
    char *left_cmd = NULL;
    char *right_cmd = NULL;
    int mode = 0;

    for (cmd_data_t *tmp = line; tmp != NULL;){
        if (tmp->TOKEN == CHEVRON_LEFT_TOKEN)
            mode += get_chevron_data(&tmp, &left_cmd, CHEVRON_LEFT_TOKEN);
        if (tmp != NULL && tmp->TOKEN == CHEVRON_RIGHT_TOKEN)
            mode += get_chevron_data(&tmp, &right_cmd, CHEVRON_RIGHT_TOKEN);
        if (tmp != NULL)
            tmp = tmp->next;
    }
    data->chev_left = left_cmd;
    data->chev_right = right_cmd;
    data->mode = mode;
    data->instance = true;
}

static void exec_p_in_pipe(cmd_data_t *tmp, cmd_data_t *start,
    storage_bag_t *storage)
{
    cmd_data_t *last_end = NULL;
    int i_max;

    for (cmd_data_t *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->next)
        if (tmp2->TOKEN == PARENTHESE_END_TOKEN)
            last_end = tmp2;
    l_remove_cmd(&tmp, last_end);
    start->TOKEN = EXTERNAL_PARENTHESE_TOKEN;
    start->value = get_raw_cmd_from_build(&i_max, tmp);
    l_cmd_free(&tmp);
}

static void redirect_link(cmd_data_t **lock, cmd_data_t **data,
    cmd_data_t *start, cmd_data_t *tmp)
{
    *lock = start->next;
    start->next = tmp->next;
    tmp->next = NULL;
}

int extract_parentheses(cmd_data_t **data, storage_bag_t *storage)
{
    cmd_data_t *start = NULL;
    cmd_data_t *end = NULL;
    cmd_data_t *prev = NULL;
    cmd_data_t *lock;
    bool found_start = false;

    for (cmd_data_t *tmp = *data; tmp != NULL; tmp = tmp->next){
        if (tmp->TOKEN == PARENTHESE_START_TOKEN && !found_start){
            start = tmp;
            found_start = true;
        }
        if (tmp->TOKEN == PARENTHESE_END_TOKEN)
            end = tmp;
        prev = tmp;
    }
    if (end != NULL){
        redirect_link(&lock, data, start, end);
        exec_p_in_pipe(lock, start, storage);
    }
    return (end == NULL) ? 0 : 1;
}

static char *without_space(char *str)
{
    int size = 0;
    char *result;
    int w = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t')
            continue;
        size++;
    }
    result = malloc(sizeof(char) * (size + 1));
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == ' ' || str[j] == '\t')
            continue;
        result[w] = str[j];
        w++;
    }
    free(str);
    result[w] = '\0';
    return result;
}

int searching_char(char *str, char search)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == search)
            nbr++;
    return nbr;
}

static int free_arch_return(char **tab, char *copy, int val)
{
    free(copy);
    a_free(tab);
    return val;
}

int check_parenthese(storage_bag_t *storage, cmd_data_t **data, char *line)
{
    char *copy = without_space(my_strdup(line));
    char **parsing_sep = a_convert_s(copy, ';', '|');

    if (searching_char(line, '(') == 0 && searching_char(line, ')') == 0)
        return free_arch_return(parsing_sep, copy, 0);
    for (int i = 0; parsing_sep[i] != NULL; i++)
        if (parsing_sep[i][0] != '(' &&
        searching_char(parsing_sep[i], '(') != 0) {
            my_putstr("Badly placed ()'s.\n", 2);
            return free_arch_return(parsing_sep, copy, 1);
        }
    for (int i = 0; copy[i] != '\0'; i++) {
        if (copy[i] == ')' && copy[i + 1] && (copy[i + 1] != ';' &&
        copy[i + 1] != '|' && copy[i + 1] != '<' && copy[i + 1] != '>')) {
            my_putstr("Badly placed ()'s.\n", 2);
            return free_arch_return(parsing_sep, copy, 1);
        }
    }
    return free_arch_return(parsing_sep, copy, 0);
}
