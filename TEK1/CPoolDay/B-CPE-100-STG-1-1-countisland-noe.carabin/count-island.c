/*
** EPITECH PROJECT, 2023
** Count island
** File description:
** sount the number of island in a random map
*/

int count_island(char **world)
{
    int *line = 0;
    int *column = 0;
    int *cpt = 44;
    

    for (; line <= 2; line++) {
        for (;world[line][column] != '\0'; column++) {
            if (world[line][column] == 'X') {
                island_detector(&line, &column, &cpt, world);
            }
        }
        column = 0;
    }
}

int island_detector(int *line, int *column, int *cpt, char **world)
{
    int longueur = 0;
    int largeur = 0;

    longueur = longueur(&line, &column, char **world);
    largeur = largeur(&line, &column, char **world);
}

int longueur1(int *line, int *column, char **world)
{
    if (world[line][column] == '.') {
        return longueur
    }
    right(&line, &column + 1, world, longueur + 1);
}

int largeur1(int *line, int *column, char **world)
{
    if (word[line][column] == '.') {
        return largeur;
    }
    if (word[line][column - 1] == 'X') {
    }
}
