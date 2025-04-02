/*
** EPITECH PROJECT, 2023
** DISPLAY_LIST
** File description:
** Print the content of a linked list.
*/

#include "../../../include/shell.h"
void l_display(linked_list_t *list)
{
    linked_list_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next){
        my_putchar('{', 1);
        my_putstr(tmp->data, 1);
        my_putchar('}', 1);
        my_putchar('\n', 1);
    }
}

void l_display_history(history_t *list)
{
    history_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next){
        my_putchar('{', 1);
        my_putstr(tmp->cmd_line, 1);
        my_putchar('}', 1);
        my_putchar('\n', 1);
    }
}

void l_display_var(var_list_t *list)
{
    list = l_sort(list);
    for (var_list_t *tmp = list; tmp != NULL; tmp = tmp->next){
        my_printf("%s\t", tmp->name);
        if (tmp->value != NULL)
            my_printf("%s", tmp->value);
        my_putchar('\n', 1);
    }
}
