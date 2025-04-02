/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** task03 my_strlen.c
*/

int my_strlen(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; str++){
        count++;
    }
    return (count);
}
