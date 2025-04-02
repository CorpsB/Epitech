/*
** EPITECH PROJECT, 2023
** new_folder
** File description:
** linked_list.c
*/

#include "my.h"

// void my_show_list(linked_t *list)
// {
//     linked_t *tmp;

//     tmp = list;
//     while (tmp != NULL) {
//         my_putstr(tmp->data);
//         tmp = tmp->next;
//     }
// }

// void my_show_revlist(linked_t *tmp)
// {
//     if (tmp == NULL) {
//         return;
//     }
//     my_show_revlist(tmp->next);
//     my_putstr(tmp->data);
//     my_putchar('\n');
// }

// int my_list_size(linked_t *begin)
// {
//     int cpt = 0;
//     linked_t *tmp = begin;

//     for (; tmp != NULL; cpt++) {
//         tmp = tmp->next;
//     }
//     return (cpt);
// }

int my_put_in_list(linked_t **list, char object, int line, int column)
{
    linked_t *element;

    element = malloc(sizeof(*element));
    element->type = object;
    element->line = line;
    element->column = column;
    element->next = *list;
    *list = element;
    return (0);
}

static void free_list(linked_t *list)
{
    linked_t *tmp = list;

    if (list->next == NULL) {
        free(list);
        return;
    }
    list = list->next;
    for (; list != NULL; list = list->next) {
        free(tmp);
        tmp = list;
    }
    free(list);
    return;
}

void free_everything(linked_t *infos_position, char *pre_map, char **map)
{
    free(pre_map);
    free_list(infos_position);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

// static int del_node(linked_t *prv)
// {
//     free(prv->data);
//     free(prv);
//     return 0;
// }

// static void delete_first(linked_t *tmp, linked_t *prv, linked_t **list)
// {
//     prv = tmp;
//     tmp = tmp->next;
//     del_node(prv);
//     *list = tmp;
// }

// int del_in_list(linked_t **list, int id)
// {
//     linked_t *prv = NULL;
//     linked_t *tmp = *list;

//     if (tmp->id == id) {
//         delete_first(tmp, prv, list);
//         return 0;
//     }
//     while (tmp != NULL) {
//         if (tmp->id != id) {
//             prv = tmp;
//             tmp = tmp->next;
//             continue;
//         }
//         prv->next = tmp->next;
//         return del_node(tmp);
//     }
//     return 84;
//     }
