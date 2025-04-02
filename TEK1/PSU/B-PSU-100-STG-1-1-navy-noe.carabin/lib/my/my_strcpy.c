/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** task01 my_strcpy.c
*/

static int my_strlen(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return (count);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
