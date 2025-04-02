/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** main.c
*/

#include "my.h"

static void init_struct(flag_t *command_info)
{
    command_info->flag_a = false;
    command_info->flag_l = false;
    command_info->flag_R = false;
    command_info->flag_d = false;
    command_info->flag_r = false;
    command_info->flag_t = false;
}

static int which_flag(char *str, flag_t *flag)
{
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == 'a')
            flag->flag_a = true;
        if (str[i] == 'l')
            flag->flag_l = true;
        if (str[i] == 'R')
            flag->flag_R = true;
        if (str[i] == 'd')
            flag->flag_d = true;
        if (str[i] == 'r')
            flag->flag_r = true;
        if (str[i] == 't')
            flag->flag_t = true;
        if (str[i] == 'a' || str[i] == 'l' || str[i] == 'R' || str[i] == 'd' ||
        str[i] == 'r' || str[i] == 't')
            continue;
        return 84;
    }
    return 0;
}

static int flag_detector(int table_size, char **args, flag_t *command_info)
{
    int error = 0;

    for (int i = 1; i < table_size; i++) {
        if (args[i][0] == '-') {
            error = which_flag(args[i], command_info);
        }
    }
    return error;
}

void my_put_in_list(each_info_t **list, char *av)
{
    each_info_t *element;

    element = malloc(sizeof(*element));
    element->filepath = av;
    element->next = *list;
    *list = element;
    return;
}

static int filepath_detector(int ac, char **args, each_info_t **filepath)
{
    for (int i = 1; args[i] != NULL; i++) {
        if (args[i][0] == '-') {
            continue;
        } else {
            my_put_in_list(filepath, args[i]);
        }
    }
}

int main(int ac, char **av)
{
    flag_t *command_info = malloc(sizeof(flag_t));
    each_info_t *filepath = NULL;
    int error_detector = 0;

    init_struct(command_info);
    if (ac != 1) {
        error_detector = flag_detector(ac, av, command_info);
        error_detector += filepath_detector(ac, av, &filepath);
    }
    if (ac == 1 || filepath == NULL)
        my_put_in_list(&filepath, ".");
    if (error_detector > 0)
        return 84;
    if (command_info->flag_R)
        recursive_flag(&filepath, command_info);
    each_filepath(filepath);
    display(filepath, command_info);
    return 0;
}
