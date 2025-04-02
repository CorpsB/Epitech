/*
** EPITECH PROJECT, 2023
** my
** File description:
** all header fonction
*/

#ifndef MY
    #define MY

//Include
    #include <unistd.h>
    #include <stdbool.h>
    #include "../my.h"
    #include <stdlib.h>

//Structures listes chainés :
typedef struct linked_list {
    int instructions;
    int size;
    int id;
    struct linked_list *next;
} linked_t;

//Focntions de la lib my
char *format_str(char *str);
void free_table(char **table);
bool is_alpah_num(char *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_is_prime(int nb);
bool my_isneg(int n);
int my_put_nbr(int a);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
bool my_strcmp(char *first, char *second);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *src);
int my_strlen(char const *str);
void show_table(char **table);
int str_len_to(char *str, int index, char separator);
char *char_sep_char(char *src, char *se, char separator);
char *my_strstr(char *src, char *se);
char **str_to_array(char *map, char sep);
int table_len(char **table);
char *write_withoutlast(char *str);
int my_getnbr(char *str);

//Lib linked_list
void re_build_env(char **env, linked_t **l_env);
int del_in_list(linked_t **list, int nbr);
void change_env(char ***mem_env, linked_t *list, char sep);
int my_list_size(linked_t *begin);
int my_put_in_list(linked_t **list, int instruction, int size);
void my_show_list(linked_t *list);
void my_show_revlist(linked_t *tmp);
int search_from_list(linked_t *list, char *name);

#endif /*MY*/
