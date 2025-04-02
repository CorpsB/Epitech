/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** disp_history.c
*/

#include "../../../include/shell.h"

static int isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i])) {
            return 1;
        }
        return 0;
}

int check_error_cmd(char **cmd)
{
    if (isnum(cmd[1]) == 1) {
        my_putstr("history: Badly formed number.\n", 2);
        return 1;
    }
    return 0;
}

void print_with_space(storage_bag_t *storage, history_t *current)
{
    if (current->id < 10) {
        my_printf("     %i ", current->id);
        my_printf(" %s ", current->temps);
        my_printf(" %s\n", current->cmd_line);
    }
    if (current->id >= 10 && current->id < 100) {
        my_printf("    %i ", current->id);
        my_printf(" %s ", current->temps);
        my_printf(" %s\n", current->cmd_line);
    }
    if (current->id >= 100) {
        my_printf("   %i ", current->id);
        my_printf(" %s ", current->temps);
        my_printf(" %s\n", current->cmd_line);
    }
}

int display_history_without_arg(storage_bag_t *storage)
{
    history_t *current;

    l_reverse_history(&storage->history);
    current = storage->history;
    while (current != NULL) {
        if (current->id != 0) {
            print_with_space(storage, current);
        }
        current = current->next;
    }
    l_reverse_history(&storage->history);
    return 0;
}

void print_with_space_arg(storage_bag_t *storage, history_t *start)
{
    if (start->id < 10) {
        my_printf("     %i ", start->id);
        my_printf(" %s ", start->temps);
        my_printf(" %s\n", start->cmd_line);
    }
    if (start->id >= 10 && start->id < 100) {
        my_printf("    %i ", start->id);
        my_printf(" %s ", start->temps);
        my_printf(" %s\n", start->cmd_line);
    }
    if (start->id >= 100) {
        my_printf("   %i ", start->id);
        my_printf(" %s ", start->temps);
        my_printf(" %s\n", start->cmd_line);
    }
}

int disp_history(storage_bag_t *storage, char **cmd)
{
    int j = 0;
    history_t *start = storage->history;

    if (cmd[1] == NULL)
        return display_history_without_arg(storage);
    if (check_error_cmd(cmd) == 1)
        return 1;
    if (isnum(cmd[1]) == 0) {
        for (int i = atoi(cmd[1]); i > 1; i--)
            start = start->next;
        l_reverse_history(&storage->history);
        for (; start != NULL; start = start->next) {
            print_with_space_arg(storage, start);
        }
    }
    l_reverse_history(&storage->history);
    return 0;
}
