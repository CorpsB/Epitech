/*
** EPITECH PROJECT, 2023
** DISPLAY_LIST
** File description:
** Print the content of a linked list.
*/

#include "../../../include/my.h"
void my_display_list(linked_list_t *begin, void (*disp_fct)())
{
    linked_list_t *tmp = begin;

    for (; tmp != NULL; tmp = tmp->next)
        disp_fct(tmp->data);
}
