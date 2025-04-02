/*
** EPITECH PROJECT, 2023
** do op
** File description:
** Main fonction
*/
int calcul(int nb, int p)
{
    int result;

    if (p == 0) {
        return (nb);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

int my_compute_power_rec(int nb, int p)
{
    if (nb == 0 || p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    return (calcul(nb, p));
}

int get_nbr(char *str)
{
    int compteur = 0;
    int nbr = 0;
    int i = 0;
    int negative = 0;

    for (; str[compteur] == '-'; compteur ++) {
        negative++;
    }
    for (;str[compteur] < '9' && str[compteur] > '0' ; compteur++) {
        i++;
    }
    compteur = compteur - i;
    for (;str[compteur] < '9' && str[compteur] > '0' ; compteur++) {
        nbr = nbr + (str[compteur] - 48) * my_compute_power_rec(10, i - 1);
        i--;
    }
    if (negative % 2 != 0) {
        nbr = nbr * (-1);
    }
    return nbr;
}
