/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** task06 my_strcmp.c
*/

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
