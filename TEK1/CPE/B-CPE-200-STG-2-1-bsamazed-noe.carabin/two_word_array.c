/*
** EPITECH PROJECT, 2023
** New-project
** File description:
** two_word_array.c
*/

static char **str_to_array(char *map, char sep)
{
    char **result = malloc(sizeof(char) * my_strlen(map));
    int column = 0;
    int li = 0;
    int index = 0;

    for (; map[index] != '\0'; li++) {
        result[li] = malloc(sizeof(char) * (str_len_to(map, index, sep) + 1));
        for (; map[index] != sep && map[index] != '\0'; index++) {
            result[li][column] = map[index];
            column++;
        }
        result[li][column] = '\0';
        index++;
        column = 0;
    }
    return result;
}
