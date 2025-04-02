/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** file_extractor.c
*/

#include "include/my.h"

static void set_data(int pos[5], char *line, int *coords, int *count)
{
    pos[0] = line[2] - 'A';
    pos[1] = line[3] - '1';
    pos[2] = line[5] - 'A';
    pos[3] = line[6] - '1';
    pos[4] = pos[1] * 8 + pos[0] + 1;
    pos[5] = pos[3] * 8 + pos[2] + 1;
    coords[*count] = pos[4];
    (*count)++;
    if (pos[5] - pos[4] < 8) {
        for (++pos[4]; pos[4] < pos[5]; ++pos[4]){
            coords[*count] = pos[4];
            (*count)++;
        }
    } else
        for (pos[4] += 8; pos[4] < pos[5]; pos[4] += 8){
            coords[*count] = pos[4];
            (*count)++;
        }
    coords[*count] = pos[5];
    (*count)++;
}

void placenbr(int *coords, char **tabl)
{
    int i = '2';

    for (int j = 0; coords[j] != -1; j++) {
        if (j == 2 || j == 5 || j == 9)
            i++;
        if (coords[j] % 8 == 0) {
            tabl[coords[j] / 8 - 1][7] = i;
        } else {
            tabl[coords[j] / 8][coords[j] % 8 - 1] = i;
        }
    }
}

int get_info(char *filepath, int size, table_t *table)
{
    FILE *file;
    int *coords;
    int count = 0;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    int pos[] = {0, 0, 0, 0, 0, 0};

    file = fopen(filepath, "r");
    coords = malloc(sizeof(int) * 15);
    coords[14] = -1;
    read = getline(&line, &len, file);
    while (read != -1) {
        set_data(pos, line, coords, &count);
        read = getline(&line, &len, file);
    }
    free(line);
    size = count;
    fclose(file);
    placenbr(coords, table->player_position);
}

static int validate_line(const char *line)
{
    int length = my_strlen(line);

    if (length != 7)
        return 0;
    if (line[0] < '2' || line[0] > '5')
        return 0;
    if (line[1] != ':' || line[4] != ':')
        return 0;
    if (line[2] < 'A' || line[2] > 'H')
        return 0;
    if (line[3] < '1' || line[3] > '8')
        return 0;
    return 1;
}

static int process_lines(FILE *fd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int success = 0;

    while (1) {
        read = getline(&line, &len, fd);
        if (read == -1)
            break;
        if (read > 0 && line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        if (!validate_line(line) || read == -1) {
            success = 0;
            break;
        }
        success = 1;
    }
    free(line);
    return success;
}

int file_content_checker(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    int result = process_lines(fd);

    if (fd == NULL) {
        my_printf("Échec de l'ouverture du fichier\n");
        return 84;
    }
    fclose(fd);
    if (result) {
        return 0;
    } else {
        my_printf("Le fichier ne contient pas le contenu ");
        my_printf("attendu ou est vide\n");
        return 84;
    }
}
