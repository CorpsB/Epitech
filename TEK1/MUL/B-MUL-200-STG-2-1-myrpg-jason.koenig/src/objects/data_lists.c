/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** create_scene
*/

#include "../../include/csfml.h"

void create_data(element_t **list, void *element)
{
    element_t *s_list = malloc(sizeof(struct element_s));

    s_list->element = element;
    s_list->next = *list;
    *list = s_list;
}

void destroy_data_list(element_t **list)
{
    element_t *target;
    element_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->element);
        tmp = tmp->next;
        free(target);
    }
}
