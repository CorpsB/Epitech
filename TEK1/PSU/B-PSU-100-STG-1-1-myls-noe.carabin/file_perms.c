/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** file_perms.c
*/

#include "my.h"

static int file_permissions_oe(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IXOTH) {
        data[*cpt] = 'x';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
}

static int file_permissions_ow(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IWOTH) {
        data[*cpt] = 'w';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_oe(buff, data, cpt);
}

static int file_permissions_or(struct stat *buff, char *data, int *cpt)
{
    data[*cpt] = ' ';
    if (buff->st_mode & S_IROTH) {
        data[*cpt] = 'r';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_ow(buff, data, cpt);
}

static int file_permissions_gx(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IXGRP) {
        data[*cpt] = 'x';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_or(buff, data, cpt);
}

static int file_permissions_gw(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IWGRP) {
        data[*cpt] = 'w';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_gx(buff, data, cpt);
}

static int file_permissions_gr(struct stat *buff, char *data, int *cpt)
{
    data[*cpt] = ' ';
    if (buff->st_mode & S_IRGRP) {
        data[*cpt] = 'r';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_gw(buff, data, cpt);
}

static int file_permissions_ae(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IXUSR) {
        data[*cpt] = 'x';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_gr(buff, data, cpt);
}

static int file_permissions_aw(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IWUSR) {
        data[*cpt] = 'w';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_ae(buff, data, cpt);
}

static void file_permissions_ar(struct stat *buff, char *data, int *cpt)
{
    if (buff->st_mode & S_IRUSR) {
        data[*cpt] = 'r';
    } else {
        data[*cpt] = '-';
    }
    (*cpt)++;
    file_permissions_aw(buff, data, cpt);
}

char *file_type(struct stat *buff)
{
    char *str = malloc(sizeof(char) * 12);
    int cpt = 1;

    str[12] = '\0';
    str[0] = '-';
    if (S_ISDIR(buff->st_mode))
        str[0] = 'd';
    if (S_ISLNK(buff->st_mode))
        str[0] = 'l';
    file_permissions_ar(buff, str, &cpt);
    str[cpt] = '\0';
    return str;
}
