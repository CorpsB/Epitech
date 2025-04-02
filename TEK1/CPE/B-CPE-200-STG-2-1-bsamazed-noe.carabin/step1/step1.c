/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-bsamazed-noe.carabin
** File description:
** step1.c
*/

#include "../my.h"

void link_list(linked_t *first, linked_t *second)
{
    first->other_list = second;
}

linked_t *create_list(int nbr)
{
    linked_t *list = NULL;
    my_put_in_list(&list, nbr);
    return list;
}

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    int nbr = my_getnbr(av[1]);
    int nbr2 = my_getnbr(av[2]);
    linked_t *link = create_list(nbr);
    linked_t *second = create_list(nbr2);
    
    link_list(link, second);

    printf("First :\n");
    my_show_list(link);
    printf("Second :\n");
    my_show_list(link->other_list);
    return 0;
}