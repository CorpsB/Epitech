/*
** EPITECH PROJECT, 2023
** KJ_LIST_SORT
** File description:
** Sort linked lists using merge sort.
*/

#include "../../../include/shell.h"

static var_list_t *get_middle(var_list_t *tmp)
{
    var_list_t *slow = tmp;
    var_list_t *fast = tmp;

    if (tmp == NULL)
        return tmp;
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static var_list_t *merge_node(var_list_t *before, var_list_t *after)
{
    var_list_t *result;

    if (before == NULL)
        return after;
    if (after == NULL)
        return before;
    if (my_stracmp(before->name, after->name) < 0){
        result = before;
        result->next = merge_node(before->next, after);
    } else {
        result = after;
        result->next = merge_node(before, after->next);
    }
    return result;
}

var_list_t *l_sort(var_list_t *list)
{
    var_list_t *middle;
    var_list_t *middle_next;
    var_list_t *before;
    var_list_t *after;
    var_list_t *result;

    if (list == NULL || list->next == NULL)
        return list;
    middle = get_middle(list);
    middle_next = middle->next;
    middle->next = NULL;
    before = l_sort(list);
    after = l_sort(middle_next);
    result = merge_node(before, after);
    return (result);
}
