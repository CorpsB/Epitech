/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-noe.carabin
** File description:
** my.h
*/

#include <SFML/Window.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/ConvexShape.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Transformable.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/VertexBuffer.h>
#include <SFML/Graphics/View.h>
#include <stddef.h>
#include <SFML/System.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferRecorder.h>
#include <SFML/Audio/SoundRecorder.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundStream.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

#ifndef MY_HUNTER
    #define MY_HUNTER

typedef struct sprite_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} sprite_t;

typedef struct window_s {
    sfRenderWindow *win;
    sfVideoMode vm;
    sfEvent event;
    sprite_t **sprite;
    int entities;
    sfClock *clock;
    sfVector2f mouv;
    float speed;
    sfMusic *audio;
} window_t;

#endif
