/*
** EPITECH PROJECT, 2023
** new_folder
** File description:
** my.h
*/

#ifndef MY
    #define MY

    //INCLUDE:

    //Librarie booléen
    #include <stdbool.h>
    //Lib printf
    #include <stdio.h>
    //Lib de valeur NULL
    #include <stddef.h>
    //Malloc, free, exit, rand
    #include <stdlib.h>
    //Librarie stat
    #include <sys/stat.h>
    //Lib open close
    #include <fcntl.h>
    //Opendir, close, readir
    #include <dirent.h>
    //Macro permission
    #include <sys/stat.h>
    //Librarie WRITE (putchar et put_str)
    #include <unistd.h>
    //Transformer ID auteur en str
    #include <pwd.h>
    //Transformer ID groupe en str
    #include <grp.h>
    //Formatage du temps avec ctime
    #include <time.h>

//Structures listes chainés :
typedef struct linked_list {
    int data;
    struct linked_list *other_list;
    struct linked_list *next;
} linked_t;

//Focntion du sokoban :
char *file_checker(char *filepath);
char **get_informtion_array(char *pre_map, linked_t **infos_position);
int core(char **map, linked_t *infos);

//Focntions des listes chainés :
int del_in_list(linked_t **list, int id);
int my_put_in_list(linked_t **list, int data);
int my_list_size(linked_t *begin);
void my_show_list(linked_t *list);
void my_show_revlist(linked_t *tmp);
int sort_name(linked_t **something);

//Fonctions de la lib
int my_is_prime_test(int nb);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
void my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

#endif /*MY*/
