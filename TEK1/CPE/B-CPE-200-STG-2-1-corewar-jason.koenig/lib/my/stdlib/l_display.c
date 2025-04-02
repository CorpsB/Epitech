/*
** EPITECH PROJECT, 2023
** DISPLAY_LIST
** File description:
** Print the content of a linked list.
*/

#include "../../../include/my.h"
void l_display(linked_list_t *list)
{
    linked_list_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next){
        my_putstr(tmp->data, 1);
        my_putchar('\n', 1);
    }
}
