/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-noe.carabin
** File description:
** sort.c
*/

#include "my.h"

static linked_info_t *chain_cpy(linked_info_t *prev)
{
    linked_info_t *result = malloc(sizeof(linked_info_t));

    result->author = my_strdup(prev->author);
    result->author_group = my_strdup(prev->author_group);
    result->date = my_strdup(prev->date);
    result->link = prev->link;
    result->name = my_strdup(prev->name);
    result->rules = my_strdup(prev->rules);
    result->size = prev->size;
    result->time = prev->time;
    return result;
}

static void swap(linked_info_t *actual, linked_info_t *prev)
{
    linked_info_t *storage = chain_cpy(prev);

    prev->author = actual->author;
    prev->author_group = actual->author_group;
    prev->date = actual->date;
    prev->link = actual->link;
    prev->name = actual->name;
    prev->rules = actual->rules;
    prev->size = actual->size;
    prev->time = actual->time;
    actual->author = storage->author;
    actual->author_group = storage->author_group;
    actual->date = storage->date;
    actual->link = storage->link;
    actual->name = storage->name;
    actual->rules = storage->rules;
    actual->size = storage->size;
    actual->time = storage->time;
}

void sort_chain(linked_info_t *list)
{
    linked_info_t *tmp = list->next;
    linked_info_t *prev = list;

    if (tmp->next == NULL)
        return;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->time < prev->time) {
            swap(tmp, prev);
            tmp = list->next;
            prev = list;
        }
        prev = tmp;
    }
    return;
}
