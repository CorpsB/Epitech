/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** story_tell
*/

#include "../../../../include/csfml.h"

static void tell_phrase(gui_t *gui, char *text, event_entity_t *event)
{
    set_dialog_text(gui->player.dialog, text);
    ++event->state;
}

static void npc_2(gui_t *gui, event_entity_t *event)
{
    if (event->state == 46)
        return tell_phrase(gui, "Hey ! I heard this is a teleportation "
        "portal.", event);
    if (event->state == 47)
        return tell_phrase(gui, "Incredible, right ?", event);
    event->state = 0;
    gui->player.dialog->is_hide = sfTrue;
}

static void npc_1(gui_t *gui, event_entity_t *event)
{
    if (event->state == 34)
        return tell_phrase(gui, "Wow ! The show at the TV is incredible !",
        event);
    if (event->state == 36)
        return tell_phrase(gui, "Don't touch me please !", event);
    if (event->state == 37)
        return tell_phrase(gui, "I still hurt from the blows you gave me "
        "yesterday.", event);
    if (event->state == 39)
        return tell_phrase(gui, "Hello !", event);
    if (event->state == 40)
        return tell_phrase(gui, "Are you sick ?", event);
    if (event->state == 41)
        return tell_phrase(gui, "I'm a doctor, I can treat you", event);
    if (event->state == 43)
        return tell_phrase(gui, "Leave me alone please.", event);
    if (event->state == 44)
        return tell_phrase(gui, "I workout, I need to be alone.", event);
    npc_2(gui, event);
}

static void after_fight(gui_t *gui, event_entity_t *event)
{
    if (event->state == 30)
        return tell_phrase(gui, "All right, good habits die hard ...",
        event);
    if (event->state == 31)
        return tell_phrase(gui, "I believe I can officially declare you ...",
        event);
    if (event->state == 32)
        return tell_phrase(gui, "fit for duty, good luck supervisor.",
        event);
    npc_1(gui, event);
}

static void after_teleport(gui_t *gui, event_entity_t *event)
{
    if (event->state == 21)
        return tell_phrase(gui, "All right, you see the person in front of "
            "you ? ...", event);
    if (event->state == 22)
        return tell_phrase(gui, "Steal it! What's the matter ? Don't you want "
        "to ? ...", event);
    if (event->state == 23)
        return tell_phrase(gui, "But you and all your residents will die, "
        "you know ? ...", event);
    if (event->state == 24)
        return tell_phrase(gui, "Tell yourself that they're monsters if that "
        "helps ...", event);
    if (event->state == 25)
        return tell_phrase(gui, "And after all, if you don't steal them now, "
        "they will later ... ", event);
    after_fight(gui, event);
}

static void intro_teleport_next(gui_t *gui, event_entity_t *event)
{
    if (event->state == 17)
        return tell_phrase(gui, "so you can find resources there ...", event);
    if (event->state == 18)
        return tell_phrase(gui, "You can now interact with the teleporter ...",
            event);
    if (event->state == 19)
        return tell_phrase(gui, "Good luck, Supervisor.", event);
    after_teleport(gui, event);
}

void intro_teleport(gui_t *gui, event_entity_t *event)
{
    if (event->state == 12)
        return tell_phrase(gui, "Well, here you are in your office ...",
            event);
    if (event->state == 13)
        return tell_phrase(gui, "In front of you is me, the computer room ...",
            event);
    if (event->state == 14)
        return tell_phrase(gui, "You don't have access to it, as I'm "
            "completely autonomous ...", event);
    if (event->state == 15)
        return tell_phrase(gui, "On your left, the little white cables are"
            " our teleporter ...", event);
    if (event->state == 16)
        return tell_phrase(gui, "They will take you to other shelters "
            "/ dimensions ...", event);
    intro_teleport_next(gui, event);
}

static void story_tell2(gui_t *gui, event_entity_t *event)
{
    if (event->state == 6)
        return tell_phrase(gui, "So let's start with a "
            "simulation so you can understand ...", event);
    if (event->state == 7)
        return tell_phrase(gui, "your role and your duty as a "
            "supervisor ...", event);
    if (event->state == 8)
        return tell_phrase(gui, "Everything you can see or "
            "hearing will not be real ...", event);
    if (event->state == 9)
        return tell_phrase(gui, "Good. Start by going to the "
            "teleporter room. It should be located in the north-west "
            "of the shelter ...", event);
    if (event->state == 10)
        return tell_phrase(gui, "Use the arrows to navigate.",
            event);
    intro_teleport(gui, event);
}

void story_tell(gui_t *gui, event_entity_t *event)
{
    gui->player.dialog->is_hide = sfFalse;
    if (event->state == 1)
        return tell_phrase(gui, "Hello, in case you don't "
            "remember, your name is Julius Nolan and you're "
            "the supervisor of this shelter ...", event);
    if (event->state == 2)
        return tell_phrase(gui, "I'm the main computer in charge of "
            "helping you with your administrative tasks ...", event);
    if (event->state == 3)
        return tell_phrase(gui, "We are now going to start "
            "your rehabilitation ...", event);
    if (event->state == 4)
        return tell_phrase(gui, "You should know that our shelter lacks "
            "a desperate need for resources ...", event);
    if (event->state == 5)
        return tell_phrase(gui, "and we'll soon be doomed "
            "if you do nothing ...", event);
    story_tell2(gui, event);
}
