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

static linked_list_t *merge_node(linked_list_t *before, linked_list_t *after,
    int (*cmp_data)())
{
    linked_list_t *result;

    if (before == NULL)
        return (after);
    if (after == NULL)
        return (before);
    if (cmp_data(before->data, after->data) < 0){
        result = before;
        result->next = merge_node(before->next, after, cmp_data);
    } else {
        result = after;
        result->next = merge_node(before, after->next, cmp_data);
    }
    return (result);
}

linked_list_t *l_sort(linked_list_t *list, int (*cmp_data)())
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
    before = l_sort(list, cmp_data);
    after = l_sort(middle_next, cmp_data);
    result = merge_node(before, after, cmp_data);
    return (result);
}
