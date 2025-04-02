/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** create_scene
*/

#include "../../include/csfml.h"

void create_pannel(pannel_t **list, int id,
    void (*draw_func)(element_t *elt, gui_t *gui),
    void (*destroy_func)(element_t *elt))
{
    pannel_t *s_list = malloc(sizeof(struct pannel_s));

    s_list->element = NULL;
    s_list->draw_func = draw_func;
    s_list->destroy_func = destroy_func;
    s_list->id = id;
    s_list->next = *list;
    *list = s_list;
}

void draw_pannels(pannel_t *list, gui_t *gui)
{
    for (pannel_t *tmp = list; tmp != NULL; tmp = tmp->next)
        tmp->draw_func(tmp->element, gui);
}

void destroy_pannels(pannel_t **list)
{
    pannel_t *target;
    pannel_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp->destroy_func(tmp->element);
        destroy_data_list(&tmp->element);
        tmp = tmp->next;
        free(target);
    }
}
