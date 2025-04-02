/*
** EPITECH PROJECT, 2023
** concat params
** File description:
** take different params and put them inside a string.
*/
int taille_count(char *src)
{
    int taille = 0;

    for (;src[taille] != '\0'; taille++) {
    }
    return (taille);
}

int tt_long(int ac, char **av)
{
    int ac_compteur = 0;
    int taille = 0;

    for (; ac_compteur < ac; ac_compteur++) {
        taille = taille + taille_count(av[ac_compteur]);
    }
    return (taille);
}

char *concat_params(int ac, char **av)
{
    int taille = 0;
    int compteur = 0;
    int letter_counter = 0;
    int char_compteur = 0;
    int taillett = tt_long(ac, av);
    char *final_string = malloc(sizeof(char) * (taillett + ac + 1));

    for (;compteur < ac; compteur++) {
        taille = taille_count(av[compteur]) +1;
        for (; av[compteur][letter_counter] != '\0'; letter_counter++) {
            final_string[char_compteur] = av[compteur][letter_counter];
            char_compteur++;
        }
        letter_counter = 0;
        final_string[char_compteur] = '\n';
        char_compteur++;
    }
    return (final_string);
}
