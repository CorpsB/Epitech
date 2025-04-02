/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-noe.carabin
** File description:
** get_array.c
*/

#include "my.h"

static file_content *get_file_content(char *filepath)
{
    int open_value;
    struct stat file_info;
    file_content *file = malloc(sizeof(file_content));

    open_value = open(filepath, O_RDONLY);
    if (open_value == (-1))
        printf("OPEN ERROR");
    if (stat(filepath, &file_info) == (-1))
        printf("STAT ERROR");
    file->size = file_info.st_size;
    file->content = malloc(sizeof(char) * (file->size + 1));
    read(open_value, file->content, file->size);
    file->content[file->size] = '\0';
    //printf("%s", file->content);
    return (file);
}

static int get_line_len(char *str, int i, char divisor)
{
    int a = i;

    for (; str[a] != divisor || str[a] != '\0'; a++);
    a = a - i;
    return (a);
}

static char **my_str_two_word_array(char *str, char divisor)
{
    char **table = malloc(sizeof(char*) * (my_strlen(str)));
    int i = 0;
    int a = 0;
    int b = 0;

    for (; str[i] != '\0'; a++) {
        for (; str[i] != divisor || str[i] != '\0'; i++) {
            table[a] = malloc(sizeof(char) * get_line_len(str, i, divisor));
            table[a][b] = str[i];
            b++;
        }
        b = 0;
        a++;
    }
    b++;
    printf("\t char :%c", table[0][1]);
    table[a][b] = '\0';
    return table;
}

char **get_array(char *str)
{
    file_content *map = get_file_content(str);
    char **array_map = my_str_two_word_array(map->content, '\n');
    
    return (array_map);
}