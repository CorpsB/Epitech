/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** text
*/

#include "../../../include/csfml.h"

dialog_box_t *create_csfml_text(sfVector2f *pos, gui_t *gui,
    unsigned int char_size)
{
    dialog_box_t *dialog = malloc(sizeof(dialog_box_t));

    dialog->box = NULL;
    dialog->text = sfText_create();
    sfText_setFont(dialog->text, gui->graphics.font);
    sfText_setColor(dialog->text, sfWhite);
    sfText_setOrigin(dialog->text,
        (sfVector2f){sfText_getLocalBounds(dialog->text).width / 2,
        sfText_getLocalBounds(dialog->text).height / 2});
    sfText_setPosition(dialog->text, *pos);
    sfText_setCharacterSize(dialog->text, char_size);
    dialog->is_hide = sfTrue;
}

dialog_box_t *create_dialog_box(gui_t *gui)
{
    sfVector2f size = {gui->graphics.win_size.x, 75};
    sfVector2f pos = {0,
        gui->graphics.win_size.y - size.y};
    dialog_box_t *dialog = create_csfml_text(&pos, gui, 25);

    sfText_setPosition(dialog->text, (sfVector2f){pos.x + 30, pos.y + 20});
    sfText_setColor(dialog->text, sfBlack);
    dialog->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(dialog->box, sfColor_fromRGB(250, 250, 250));
    sfRectangleShape_setOutlineColor(dialog->box, sfBlack);
    sfRectangleShape_setOutlineThickness(dialog->box, 2.0f);
    sfRectangleShape_setOrigin(dialog->box,
        (sfVector2f){sfRectangleShape_getLocalBounds(dialog->box).width / 2,
        sfRectangleShape_getLocalBounds(dialog->box).height / 2});
    sfRectangleShape_setPosition(dialog->box, pos);
    sfRectangleShape_setSize(dialog->box, size);
    return dialog;
}

void set_dialog_text(dialog_box_t *dialog, char *text)
{
    sfText_setString(dialog->text, text);
}

void draw_dialog(dialog_box_t *box, sfRenderWindow *win)
{
    if (box->is_hide == sfTrue)
        return;
    if (box->box != NULL)
        sfRenderWindow_drawRectangleShape(win, box->box, NULL);
    sfRenderWindow_drawText(win, box->text, NULL);
}

void destroy_dialog(dialog_box_t *box)
{
    sfText_destroy(box->text);
    if (box->box != NULL)
        sfRectangleShape_destroy(box->box);
    free(box);
}
