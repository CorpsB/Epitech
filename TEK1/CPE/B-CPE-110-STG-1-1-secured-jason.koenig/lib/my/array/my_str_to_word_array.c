/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** Tranform a string into an array of words.
*/

#include "../../../include/my.h"
static int non_alphanumeric_test(char const *str)
{
    int count = 0;

    for (int i = 1; str[i] != '\0'; ++i)
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= '0' && str[i] <= '9')) &&
        ((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
        (str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
        (str[i - 1] >= '0' && str[i - 1] <= '9')))
            ++count;
    return (count);
}

static int str_to_word_array_sub(char const *str, int *i)
{
    for (; (str[*i] >= 'a' && str[*i] <= 'z') ||
    (str[*i] >= 'A' && str[*i] <= 'Z') ||
    (str[*i] >= '0' && str[*i] <= '9'); ++(*i));
    if ((str[*i - 1] >= 'a' && str[*i - 1] <= 'z') ||
    (str[*i - 1] >= 'A' && str[*i - 1] <= 'Z') ||
    (str[*i - 1] >= '0' && str[*i - 1] <= '9'))
        return (1);
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int t_max = non_alphanumeric_test(str);
    int str_a_len = my_strlen(str);
    int j;
    int k = 0;

    tab = malloc(sizeof(char *) * (t_max + 2));
    if (tab == NULL)
        return (NULL);
    for (int i = 0; i < str_a_len; ++i){
        j = i;
        if (str_to_word_array_sub(str, &i)){
            tab[k] = malloc(sizeof(char) * (i - j + 1));
            my_strncpy(tab[k], &str[j], i - j);
            ++k;
        }
    }
    tab[t_max + 1] = 0;
    return (tab);
}
