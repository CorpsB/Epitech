/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** List of functions avaliable in lib/my/
*/

#ifndef MY
    #define MY

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "hashtable.h"

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

void my_putchar(char);
void my_putnbr(long long);
void my_putstr(char const *);
int my_strlen(char const *);
char *my_substr(char const *, int, int);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_square_root(int);
int my_is_prime(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int n);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcat(char *, char const *);
int my_show_str_array(char **);
int my_show_int_array(int *);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
void my_concat_list(linked_list_t **, linked_list_t **);
linked_list_t *my_params_to_list(int, char **);
void my_rev_list(linked_list_t **);
int get_color(unsigned char, unsigned char, unsigned char);
int kj_count_number(unsigned long long int);
char *kj_convert_base(unsigned long long, int);
void kj_put_in_chain(linked_list_t **, void *);
long long kj_reverse_base(char *, int);
void kj_free_list(linked_list_t **);
char *kj_getfloat(double, int);
int kj_find_in_str(char const *, char, char);
char *kj_int_to_str(long long);
unsigned long long int kj_xposant(int, int);
char *kj_atomize_char(char *, char, int, int);
int my_list_size(linked_list_t **);
int kj_stracmp(char const *, char const *);
void my_printf(const char *, ...);
void my_display_list(linked_list_t *, void (*)());
void my_delete_in_list(linked_list_t **, void const *, int (*)());
linked_list_t *kj_list_sort(linked_list_t *);
void kj_free_dlist(dlist **);
#endif
