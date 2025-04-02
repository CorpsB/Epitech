/*
** EPITECH PROJECT, 2023
** MY_PRINT_PARAMS
** File description:
** Return the main params.
*/

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i = i + 1) {
            my_putchar(str[i]);
                }
}

int main(int argc, char **argv)
{
    int compteur = 0;

    for (;compteur < argc; compteur++) {
        my_putstr(argv[compteur]);
        my_putchar('\n');
    }
    return (0);
}
