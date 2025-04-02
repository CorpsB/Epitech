/*
** EPITECH PROJECT, 2023
** KJ_PUT_IN_CHAIN
** File description:
** Put a string into a linked list.
*/

#include "../../../include/project.h"
void l_add(linked_list_t **list, void *arg)
{
    linked_list_t *s_list = malloc(sizeof(struct linked_list));

    s_list->data = arg;
    s_list->next = *list;
    *list = s_list;
}

void l_add_shema(champion_shema_t **list, int arg_a, int arg_n, char *path)
{
    champion_shema_t *s_list = malloc(sizeof(struct champion_shema));

    s_list->path = path;
    s_list->arg_a = arg_a;
    s_list->arg_n = arg_n;
    s_list->next = *list;
    *list = s_list;
}

void l_add_champion(champions_t **list)
{
    champions_t *s_list = malloc(sizeof(struct champions));

    s_list->next = *list;
    *list = s_list;
}
