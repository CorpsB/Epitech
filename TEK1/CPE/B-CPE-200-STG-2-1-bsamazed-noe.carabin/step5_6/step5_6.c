/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-bsamazed-noe.carabin
** File description:
** step5_6.c
*/

#include "../my.h"

int my_put_in_list_list(linked_t **list, int nbr, linked_t *other)
{
    linked_t *element;

    element = malloc(sizeof(*element));
    element->data = nbr;
    element->other_list = other;
    element->next = *list;
    *list = element;
    return (0);
}

void my_show_list_list(linked_t *list)
{
    linked_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        printf("\n\nDATA : %i\n", tmp->data);
        printf("CONNECTION :\n");
        for (linked_t *giga_tmp = tmp->other_list; giga_tmp != NULL; giga_tmp = giga_tmp->next) {
            if (giga_tmp->data == 0) {
                printf("NO_VALUE\n");
                continue;
            }
            my_put_nbr(giga_tmp->data);
            my_putchar('\n');
        }
        tmp = tmp->next;
    }
}

int main(void)
{
    linked_t *list = NULL;
    linked_t *first = NULL;
    linked_t *second = NULL;
    linked_t *third = NULL;
    linked_t *four = NULL;
    linked_t *five = NULL;
    linked_t *six = NULL;
    linked_t *seven = NULL;
    linked_t *eight = NULL;

    my_put_in_list(&first, 60012);
    my_put_in_list(&first, 48);

    my_put_in_list(&second, 30012);

    my_put_in_list(&third, 0);

    my_put_in_list(&four, 50012);

    my_put_in_list(&five, 3);

    my_put_in_list(&six, 98);
    my_put_in_list(&six, 8);

    my_put_in_list(&seven, 0);
    my_put_in_list(&eight, 0);


    my_put_in_list_list(&list, 42, first);
    my_put_in_list_list(&list, 60012, second);
    my_put_in_list_list(&list, 30012, third);
    my_put_in_list_list(&list, 48, four);
    my_put_in_list_list(&list, 50012, five);
    my_put_in_list_list(&list, 3, six);
    my_put_in_list_list(&list, 98, seven);
    my_put_in_list_list(&list, 8, eight);
    my_show_list_list(list);
}
