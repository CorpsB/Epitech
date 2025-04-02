/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** paint_drawing
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static void draw_with_size_next(paint_t *paint, int x, int y,
    sfVector2u imageSize)
{
    if (x >= 0 && y >= 0 && x < (int)imageSize.x &&
        y < (int)imageSize.y) {
        sfImage_setPixel(paint->image, x, y, paint->selected_color);
    }
    return;
}

static void draw_with_size(paint_t *paint)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(paint->window);
    unsigned int realX = (unsigned int)((mousePos.x -
    sfSprite_getPosition(paint->image_sprite).x) / paint->scale.x);
    unsigned int realY = (unsigned int)((mousePos.y -
    sfSprite_getPosition(paint->image_sprite).y) / paint->scale.y);
    sfVector2u imageSize = sfImage_getSize(paint->image);
    int x = 0;
    int y = 0;

    for (int dx = -(int)paint->pen_size; dx <= (int)paint->pen_size; dx++) {
        for (int dy = -(int)paint->pen_size;
            dy <= (int)paint->pen_size; dy++) {
            x = realX + dx;
            y = realY + dy;
            draw_with_size_next(paint, x, y, imageSize);
        }
    }
}

void paint_drawing(paint_t *paint)
{
    sfImage *image = paint->image;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2f image_position = sfSprite_getPosition(paint->image_sprite);
    sfVector2u image_size = sfImage_getSize(paint->image);

    image_position.x *= paint->scale.x;
    image_position.y *= paint->scale.y;
    image_size.x *= paint->scale.x;
    image_size.y *= paint->scale.y;
    if ((float)(mousePos.x - image_position.x) >= 0 &&
        (float)mousePos.x <= (float)image_position.x + (float)image_size.x &&
        (float)(mousePos.y - image_position.y) >= 0 &&
        (float)mousePos.y <= (float)image_position.y + (float)image_size.y){
        draw_with_size(paint);
        sfTexture_updateFromImage(paint->image_texture, image, 0, 0);
    }
}
