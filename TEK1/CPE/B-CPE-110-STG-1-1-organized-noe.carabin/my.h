/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** my.h
*/

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H_
    #define LIST_H_

int my_strcompare(char *first, char *second);

typedef struct linked_list {
    char *name;
    char *type;
    int nbr;
    struct linked_list *next;
} linked_list_t;

typedef struct list_and_nbr_t {
    int nbr;
    linked_list_t *list;
} list_and_nbr;

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_putchar(char c);
char *my_strdup(char const *src);
int my_putnbr(int a);
int my_strcmp(char *name1, char *name2);
int get_table_size(char **table);
int switch_revsort(void *data, char **args);

#endif /*LIST_H*/
