/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define NONE 0
    #define HOVER 1
    #define SELECTED 2
    #define OPEN 4

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <string.h>
    #include <fcntl.h>
    #include "csfml.h"
    //include stat (->help_function)
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
int my_putnbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
void my_rev_list(linked_list_t **);
char *my_strdup(char const *);
int my_list_size(linked_list_t const *);
void my_put_in_chain(linked_list_t **, char *);
char *tc_get_scientif(double, int);
char *tc_my_int_to_str(long long int);
void tc_put_scientif(double, int);
char *tc_rev_bin(char *);
char *tc_two_complement(char *);
int kj_put_in_chain(linked_list_t **, char *);
char *kj_getfloat(double, int);
char *kj_chain_to_str(linked_list_t *);
void kj_free_list(linked_list_t *);
int kj_putfloat(double, int);
unsigned long long int kj_xposant(int, int);
int kj_count_number(unsigned long long int);
char *kj_charcut_str(char const *, int, int, int);
char **my_str_to_word_array(char *str, char delim);
int count_words(char *str);
int my_printf(char const *format, ...);
int print_exit(int exit, int exit_code, int nb, ...);

#endif
