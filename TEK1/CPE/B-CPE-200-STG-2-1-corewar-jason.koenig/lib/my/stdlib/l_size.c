/*
** EPITECH PROJECT, 2023
** MY_LIST_SIZE
** File description:
** A function that returns the number
** of elements on the list.
*/

#include "../../../include/project.h"
int l_size(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}

int l_size_shema(champion_shema_t **list)
{
    champion_shema_t *tmp = *list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}

int l_size_champion(champions_t **list)
{
    champions_t *tmp = *list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}
