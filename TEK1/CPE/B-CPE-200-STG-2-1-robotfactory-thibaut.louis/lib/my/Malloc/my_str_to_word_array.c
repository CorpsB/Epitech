/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** my_str_to_word_array.c
*/

#include "../../my.h"

static int is_alpha(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') || c == '/' || c == '.' || c == '-' || c == '_'
    || c == ')' || c == '(' || c == '|')
        return (0);
    return (1);
}

static char **my_word_to_array(char **argv, char const *str)
{
    int j = 0;
    int c = 0;

    for (int i = 0; str[i]; i++) {
        if (is_alpha(str[i]) == 0) {
            argv[j][c] = str[i];
            c++;
        }
        if (c != 0 && (is_alpha(str[i]) == 1 &&
            is_alpha(str[i + 1] == 0))) {
            argv[j][c] = '\0';
            j++;
            c = 0;
        }
    }
    argv[j + 1] = NULL;
    return (argv);
}

char **my_str_to_word_array(char const *str)
{
    char **argv = NULL;
    int j = 0;

    if (str[0] == 0)
        return (NULL);
    for (int i = 0; str && str[i]; i++)
        if (is_alpha(str[i]) == 1 && is_alpha(str[i + 1]) == 0)
            j++;
    argv = malloc(sizeof(char *) * (j + 3));
    if (argv == NULL)
        return (NULL);
    for (int i = 0; i <= j; i++) {
        argv[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (argv[i] == NULL)
            return (NULL);
        for (int c = 0; c <= my_strlen(str); c++)
            argv[i][c] = '\0';
    }
    return (my_word_to_array(argv, str));
}

// int main()
// {
//     char const *str = "\t   Hello-World\t\t\t  This|is   \ta   test.\t ";
//     char **result = my_str_to_word_array(str);
//     if (result == NULL) {
//         printf("Erreur lors de l'allocation mémoire.\n");
//         return 1;
//     }
//     printf("Mots extraits de la chaîne :\n");
//     for (int i = 0; result[i] != NULL; i++) {
//         printf("Mot %d: |%s|\n", i, result[i]);
//     }
//     for (int i = 0; result[i] != NULL; i++) {
//         free(result[i]);
//     }
//     free(result);
//     return 0;
// }
