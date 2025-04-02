/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** disp_history.c
*/

#include "../../../include/shell.h"

static int verif_line_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]))
            return 1;
    }
    return 0;
}

static int feed_id(int tmp_int, char *cmd, int i)
{
    if (cmd[i] >= '0' && cmd[i] <= '9')
        tmp_int = tmp_int * 10 + (cmd[i] - '0');
    return tmp_int;
}

static char *exec_id(storage_bag_t *storage, int tmp_int)
{
    for (history_t *tmp = storage->history; tmp != NULL; tmp = tmp->next)
        if (tmp->id == tmp_int)
            return tmp->cmd_line;
    return NULL;
}

static char *exec_str(storage_bag_t *storage, char *cmd)
{
    for (history_t *tmp = storage->history; tmp != NULL; tmp = tmp->next)
        if (my_strncmp(cmd, tmp->cmd_line, my_strlen(cmd)) == 0)
            return tmp->cmd_line;
    return NULL;
}

char *find_hist(storage_bag_t *storage, char *cmd)
{
    int tmp_int = 0;

    if (verif_line_int(cmd) == 0)
        return exec_str(storage, &cmd[1]);
    for (int i = 0; cmd[i] != '\0'; i++)
        tmp_int = feed_id(tmp_int, cmd, i);
    return exec_id(storage, tmp_int);
}

static bool event_cmd(history_t *hist, char *cmd)
{
    for (history_t *tmp = hist; tmp != NULL; tmp = tmp->next)
        if (my_strncmp(cmd, tmp->cmd_line, my_strlen(cmd)) == 0)
            return true;
    return false;
}

static bool event_int(history_t *hist, char *copy)
{
    history_t *tmp = hist;
    int i = 0;
    int int_cmd = atoi(copy);

    if (int_cmd == 0)
        return false;
    for (; tmp != NULL; tmp = tmp->next) {
        i++;
    }
    if (int_cmd > i)
        return false;
    return true;
}

int excl_history(storage_bag_t *storage, char **cmd, bool is_print)
{
    if (cmd[0][1] == '\0')
        return (is_print) ? msg(ERR, 2, 1, "!: Command not found.\n") : ERR;
    if (!event_int(storage->history, &cmd[0][1]) &&
    !event_cmd(storage->history, &cmd[0][1]))
        return (is_print) ? msg(ERR, 2, 2,
        &cmd[0][1], ": Event not found.\n") : ERR;
    return 0;
}
