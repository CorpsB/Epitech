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
//Include de wait
#include <sys/wait.h>

#ifndef LIST_H_
    #define LIST_H_


typedef struct linked_info {
    char *name;
    char *rules;
    int link;
    char *author;
    char *author_group;
    int size;
    char *date;
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

int each_filepath(each_info_t *filepath);
char *file_type(struct stat *buff);
void display(each_info_t *entiere_list, flag_t *command_info);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_strdup(char *src);
int my_put_nbr(int a);

#endif /*LIST_H_*/
