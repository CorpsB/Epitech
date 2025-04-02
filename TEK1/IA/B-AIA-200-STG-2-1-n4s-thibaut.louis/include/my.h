/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** List of functions avaliable in lib/my/
*/

#ifndef MY
    #define MY
    #define BASE_36 "0123456789abcdefghijklmnopqrstuvwxyz"

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <fcntl.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

// others
void a_sort_int(int *array, int size);
int n_size(unsigned long long n);
char *s_upper(char *str);
char *s_lower(char *str);
char *my_strstr(char *str, char const *pattern);
char *s_copy(char *dest, char const *src);
char *s_ncopy(char *dest, char const *src, int max);
int my_strcmp(char const *s1, char const *s2);
int my_stracmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int size);
int my_strscmp(char const *s1, char const *s2, int i, int n);
int my_strlen(char const *str);
char *s_reverse(char *str);
int s_search(char const *str, char min, char max);
int n_convert_s(char const *str);
unsigned long long n_power(int nb, int power);
int n_prime(int nb);
int n_isprime(int nb);
long long n_revbase(char *nb, int base);
int s_count(char *str, char c);
int a_size(char **array);

// stdlib.h
void l_free(linked_list_t **list);
linked_list_t *l_sort(linked_list_t *list, int (*cmp_func)());
void l_add(linked_list_t **list, void *arg);
void l_merge(linked_list_t **list_1, linked_list_t **list_2);
void l_remove(linked_list_t **list, void const *ref, int (*cmp_func)());
void l_reverse(linked_list_t **list);
linked_list_t *l_convert_a(int ac, char **av);
void l_display(linked_list_t *list);
int l_size(linked_list_t **list);
char *my_substr(char const *str, int min, int max);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strcat_sep(char *dest, char const *src, char sep);
char *s_convert_n(long long nb);
char *s_remove(char *str, char c);
char *n_base(unsigned long long nb, int base);
char *s_convert_f(double nb, int virg);
void a_free(char **array);
char **a_convert_s(char *str, char sep);
char **a_dup(char **array);
char *my_getline(char *str, int *i, char sep);

// unistd.h
void a_display_n(int *array);
void a_display_s(char **array);
void my_putstr(char const *str, int port);
void my_putchar(char c, int port);
void my_putnbr(long long nb, int port);
char *my_strtok(char *str, char *clean_list);

// stdarg.h
void my_printf(int port, const char *str, ...);

// fcntl.h
char *my_readfile(char *pathname);

#endif
