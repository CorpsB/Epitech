/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** display.c
*/

#include "my.h"

static void other_info(linked_info_t *tmp)
{
    my_putstr(tmp->rules);
    my_putchar(' ');
    my_put_nbr(tmp->link);
    my_putchar(' ');
    my_putstr(tmp->author);
    my_putchar(' ');
    my_putstr(tmp->author_group);
    my_putchar(' ');
    my_put_nbr(tmp->size);
    my_putchar(' ');
    my_putstr(tmp->date);
    my_putchar(' ');
}

static void normal_send(linked_info_t *tmp, flag_t *command_info)
{
    if (tmp == NULL) {
        return;
    }
    normal_send(tmp->next, command_info);
    if (!command_info->flag_a && tmp->name[0] != '.') {
        if (command_info->flag_l)
            other_info(tmp);
        my_putstr(tmp->name);
        my_putchar('\n');
    }
    if (command_info->flag_a) {
        if (command_info->flag_l)
            other_info(tmp);
        my_putstr(tmp->name);
        my_putchar('\n');
    }
}

static void reverse_send(linked_info_t *list, flag_t *command_info)
{
    linked_info_t *tmp = list;

    while (tmp != NULL) {
        if (!command_info->flag_a && tmp->name[0] == '.') {
            tmp = tmp->next;
            continue;
        }
        if (command_info->flag_l)
            other_info(tmp);
        my_putstr(tmp->name);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return;
}

static void folder_checker(each_info_t *entiere_list, flag_t *command_info,
    char *name)
{
    linked_info_t *tmp = entiere_list->info;

    if (command_info->flag_l) {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        other_info(tmp);
    }
    my_putstr(name);
    my_putchar('\n');
}

static void send_d(each_info_t *entiere_list, flag_t *command_info)
{
    linked_info_t *tmp = entiere_list->info;

    for (; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->name, ".") == 1)
            break;
    if (command_info->flag_l)
        other_info(tmp);
    my_putstr(entiere_list->filepath);
    my_putchar('\n');
    return;
}

static void flag_t_func(linked_info_t *list, flag_t *command_info)
{
    sort_chain(list);
    if (!command_info->flag_r) {
        normal_send(list, command_info);
    } else {
        reverse_send(list, command_info);
    }
}

static int get_ttsize(each_info_t *list, flag_t *flags)
{
    linked_info_t *tmp = list->info;
    unsigned long long result = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (!flags->flag_a && tmp->name[0] == '.')
            continue;
        result += tmp->block;
    }
    return (result / 2);
}

static void little_message(char *filepath, flag_t *flags, each_info_t *list,
    bool is_single)
{
    if (!flags->flag_d && !is_single) {
        my_putstr(filepath);
        my_putstr(":\n");
    }
    if (!flags->flag_d && flags->flag_l) {
        my_putstr("total ");
        my_put_nbr(get_ttsize(list, flags));
        my_putchar('\n');
    }
}

void display(each_info_t *entiere_list, flag_t *flag)
{
    bool is_single = true;

    if (entiere_list->next != NULL)
        is_single = false;
    while (entiere_list != NULL) {
        if (!is_single || flag->flag_l)
            little_message(entiere_list->filepath, flag, entiere_list,
            is_single);
        if (flag->flag_r && !flag->flag_d && !flag->flag_t)
            reverse_send(entiere_list->info, flag);
        if (!flag->flag_d && !flag->flag_t && !flag->flag_r)
            normal_send(entiere_list->info, flag);
        if (flag->flag_d)
            send_d(entiere_list, flag);
        if (flag->flag_t)
            flag_t_func(entiere_list->info, flag);
        if (!is_single && entiere_list->next != NULL && !flag->flag_d)
            my_putchar('\n');
        entiere_list = entiere_list->next;
    }
}
