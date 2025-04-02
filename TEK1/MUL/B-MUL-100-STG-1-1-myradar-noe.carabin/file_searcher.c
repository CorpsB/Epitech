/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-noe.carabin
** File description:
** file_searcher.c
*/

#include "my.h"

// static int error_detector(char *str)
// {
//     int a = 0;
//     int j = 0;
//     int space_counter = 0;
//     char type;

//     for (int i = 0; str[i] != '\0'; i++) {
//         for (; str[j] != '\n'; j++) {
//             if (space_counter == 0 && str[j] == 'A' && str[j] == 'T') {
//                 type = str[j];
//                 continue;
//             }
//             if (str[j] == ' ') {
//                 space_counter++;
//                 continue;
//             }
//             if (str[j] < 57 && str[j] > 48) {
//                 continue;
//             }
//             break;
//         }
//         if (type == 'A' && space_counter == 6) {
//             i += j;
//             j = 0;
//             continue;
//         }
//         if (type == 'T' && space_counter == 3) {
//             i += j;
//             j = 0;
//             continue;
//         }
//         break;
//     }
//     printf("Error : %i", a);
//     return a;
// }

static int get_nbr(char *str, int i, int *info, int index)
{
    int result = 0;

    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; (i)++) {
        result = result * 10;
        result += (str[i] - 48);
    }
    info[index] = result;
    return i;
}

static void my_put_in_list_tower(tower_t **tower_list, int *info)
{
    tower_t *element;

    element = malloc(sizeof(*element));
    element->co_x = info[0];
    element->co_y = info[1];
    element->radius = info[2];
    element->next = *tower_list;
    *tower_list = element;
    return;
}

static int insert_b(char *str, int i, int *info, tower_t **tower_list)
{
    info = malloc(sizeof(int) * 3);
    i += 2;
    for (int index = 0; index < 3; index++) {
        i = get_nbr(str, i, info, index) + 1;
    }
    my_put_in_list_tower(tower_list, info);
    free(info);
    return i - 1;
}

static sfVector2f get_norm(plane_t *inf)
{
    sfVector2f norm = {inf->end_x - inf->start_x, inf->end_y - inf->start_y};
    float length;

    length = sqrt(norm.x * norm.x + norm.y * norm.y);
    norm.x = length / (inf->end_x - inf->start_x);
    norm.y = length / (inf->end_y - inf->start_y);
    return norm;
}

static sfRectangleShape* init_hit_box(void)
{
    sfRectangleShape* hit_box = sfRectangleShape_create();
    sfVector2f size = {20.0, 20.0};
    sfVector2f origin = {10.0, 10.0};

    sfRectangleShape_setSize(hit_box, size);
    sfRectangleShape_setFillColor(hit_box, sfTransparent);
    sfRectangleShape_setOutlineColor(hit_box, sfRed);
    sfRectangleShape_setOutlineThickness(hit_box, 2.0);
    sfRectangleShape_setOrigin(hit_box, origin);
    return hit_box;
}

static void my_put_in_list_plane(plane_t **plane_list, int *info)
{
    plane_t *element;

    element = malloc(sizeof(*element));
    element->start_x = info[0];
    element->start_y = info[1];
    element->end_x = info[2];
    element->end_y = info[3];
    element->speed = info[4];
    element->delay = info[5];
    element->id = info[6];
    element->isalive = true;
    element->plane = create_plane_sprite(1);
    element->norm = get_norm(element);
    element->hit_box = init_hit_box();
    element->next = *plane_list;
    *plane_list = element;
    return;
}

static int insert_a(char *str, int i, int *info, plane_t **plane_list)
{
    i += 2;
    for (int index = 0; index < 6; index++) {
        i = get_nbr(str, i, info, index) + 1;
    }
    my_put_in_list_plane(plane_list, info);
    free(info);
    return i;
}

static void stock_info(char *str, plane_t **plane, tower_t **tower)
{
    int *info;
    int error = 0;
    int id = 0;

    for (int i = 0; str[i] != '\0' && error != 84;) {
        if (str[i] == 'A') {
            info = malloc(sizeof(int) * 7);
            info[6] = id;
            i = insert_a(str, i, info, plane) - 1;
            id++;
        }
        if (str[i] == 'T') {
            i = insert_b(str, i, info, tower);
        }
        if (str[i] != '\0') {
            i++;
            continue;
        }
        error = 84;
    }
}

static sfSprite *create_plane_sprite(int i)
{
    sfTexture* texture = sfTexture_createFromFile("sprite/plane.png", NULL);
    sfSprite* sprite = sfSprite_create();
    plane_t *tmp;
    sfVector2f origin = {10.0, 10.0};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setOrigin(sprite, origin);
    return (sprite);
}

int file_extractor(char *filepath, plane_t **plane, tower_t **tower)
{
    struct stat tmp_info;
    int open_error = open(filepath, O_RDONLY);
    char *file_content;

    if (open_error == -1)
        return 84;
    stat(filepath, &tmp_info);
    file_content = malloc(sizeof(char) * (tmp_info.st_size + 1));
    read(open_error, file_content, tmp_info.st_size);
    file_content[tmp_info.st_size] = '\0';
    close(open_error);
    stock_info(file_content, plane, tower);
}

//Gestion d'erreur à ajouter avant : stock_info(file_content, plane, tower);
