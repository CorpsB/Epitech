/*
** EPITECH PROJECT, 2023
** MY_SHOW_WORD_ARRAY
** File description:
** MY_SHOW_WORD_ARRAY
*/

int size_tt(char *str)
{
    int taille = 0;

    for (; str[taille] != '\0'; taille++) {
    }
    return (taille);
}

int size(char *str, int str_lettres)
{
    for (;alphanum(str, str_lettres) == 1; str_lettres++) {
    }
    for (;alphanum(str, str_lettres) == 1; str_lettres++) {
    }
    return (str_lettres);
}

int alphanum(char *str, int str_lettres)
{
    if ((str[str_lettres] >= 'A' && str[str_lettres] <= 'Z') ||
        (str[str_lettres] >= 'a' && str[str_lettres] <= 'z') ||
        (str[str_lettres] >= '1' && str[str_lettres] <= '9')) {
            return 1;
        } else {
            return 0;
        }
}

int error(char *str, int str_lettres)
{
    for (; alphanum(str, str_lettres) == 0 && str[str_lettres + 1] !=
        '\0'; str_lettres++) {
        }
    return (str_lettres);
}

char **my_str_to_word_array(char const *str)
{
    int mots = 0;
    int lettres = 0;
    char **final;
    int str_lettres = 0;

    final = malloc((sizeof(*final) * (size_tt(str) + 1)));
    for (; alphanum(str, str_lettres) == 0 && str[str_lettres + 1]
    != '\0';str_lettres++) {
    }
    for (; str[str_lettres] != '\0';) {
        final[mots] = malloc(sizeof(char) * size(str, str_lettres));
        for (; alphanum(str, str_lettres) == 1; str_lettres++) {
            final[mots][lettres] = str[str_lettres];
            lettres++;
        }
        str_lettres = error(str, str_lettres);
        lettres = 0;
        mots++;
    }
    return final;
}
