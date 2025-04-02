/*
** EPITECH PROJECT, 2023
** KJ_LIST_SORT
** File description:
** Sort linked lists using merge sort.
*/

#include "../../../include/amazed.h"

static room_link_t *get_middle(room_link_t *tmp)
{
    room_link_t *slow = tmp;
    room_link_t *fast = tmp;

    if (tmp == NULL)
        return (tmp);
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return (slow);
}

static room_link_t *merge_node(room_link_t *before, room_link_t *after)
{
    room_link_t *result;

    if (before == NULL)
        return (after);
    if (after == NULL)
        return (before);
    if (before->room->dist < after->room->dist){
        result = before;
        result->next = merge_node(before->next, after);
    } else {
        result = after;
        result->next = merge_node(before, after->next);
    }
    return (result);
}

room_link_t *sort_room_list(room_link_t *list)
{
    room_link_t *middle;
    room_link_t *middle_next;
    room_link_t *before;
    room_link_t *after;
    room_link_t *result;

    if (list == NULL || list->next == NULL)
        return (list);
    middle = get_middle(list);
    middle_next = middle->next;
    middle->next = NULL;
    before = sort_room_list(list);
    after = sort_room_list(middle_next);
    result = merge_node(before, after);
    return (result);
}
