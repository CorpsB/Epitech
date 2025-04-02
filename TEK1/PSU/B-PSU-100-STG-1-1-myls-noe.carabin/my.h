/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my.h
*/

//Librarie booléen
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
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

#ifndef LIST_H_
    #define LIST_H_


typedef struct linked_info {
    char *name;
    char *rules;
    int link;
    char *author;
    char *author_group;
    int size;
    int block;
    char *date;
    unsigned long long time;
    struct linked_info *next;
} linked_info_t;

typedef struct each_info {
    char *filepath;
    linked_info_t *info;
    struct each_info *next;
} each_info_t;

typedef struct flags {
    bool flag_a;
    bool flag_l;
    bool flag_R;
    bool flag_d;
    bool flag_r;
    bool flag_t;
} flag_t;

//Focntions internes du projet
int each_filepath(each_info_t *filepath);
char *file_type(struct stat *buff);
void display(each_info_t *entiere_list, flag_t *command_info);
int recursive_flag(each_info_t **filepath, flag_t *flag);
char *my_strstr(char *src, char *se, char separator);

//Structure de la lib
typedef struct linked_list {
    char *word;
    int cpt;
    struct linked_list *next;
} linked_t;

int my_list_size(each_info_t *begin);
void sort_chain(linked_info_t *list);
void my_put_in_list(each_info_t **list, char *av);

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
char *my_strncpy(char *dest, char const *src, int n, int start);
char *my_revstr(char *str);
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
char *my_strdup(char const *src);

#endif /*LIST_H_*/
