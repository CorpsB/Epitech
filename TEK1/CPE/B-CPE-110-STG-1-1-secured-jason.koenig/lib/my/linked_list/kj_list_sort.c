/*
** EPITECH PROJECT, 2023
** KJ_LIST_SORT
** File description:
** Sort linked lists using merge sort.
*/

#include "../../../include/my.h"
static linked_list_t *get_middle(linked_list_t *tmp)
{
    linked_list_t *slow = tmp;
    linked_list_t *fast = tmp;

    if (tmp == NULL)
        return (tmp);
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return (slow);
}

static linked_list_t *merge_node(linked_list_t *before, linked_list_t *after)
{
    linked_list_t *result;

    if (before == NULL)
        return (after);
    if (after == NULL)
        return (before);
    if (kj_stracmp(before->data, after->data) < 0){
        result = before;
        result->next = merge_node(before->next, after);
    } else {
        result = after;
        result->next = merge_node(before, after->next);
    }
    return (result);
}

linked_list_t *kj_list_sort(linked_list_t *list)
{
    linked_list_t *middle;
    linked_list_t *middle_next;
    linked_list_t *before;
    linked_list_t *after;
    linked_list_t *result;

    if (list == NULL || list->next == NULL)
        return (list);
    middle = get_middle(list);
    middle_next = middle->next;
    middle->next = NULL;
    before = kj_list_sort(list);
    after = kj_list_sort(middle_next);
    result = merge_node(before, after);
    return (result);
}
