/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-noe.carabin
** File description:
** my.h
*/

#ifndef LIST_H_
    #define LIST_H_

//Include :
//Lib pour open
    #include <fcntl.h>
//Lib pour stat
    #include <sys/stat.h>
// Lib de Printf
    #include <stdio.h>
//Lib de malloc
    #include <stdlib.h>
//Lib de close et read
    #include <unistd.h>
//Poiteur NULL
    #include <stddef.h>
//Toutes les lib de la CSFML
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
//Lib math (sqrt)
    #include <math.h>
    #include <stdbool.h>

//Structures :

typedef struct plane {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int speed;
    int delay;
    int id;
    bool isalive;
    sfSprite* plane;
    sfRectangleShape* hit_box;
    sfVector2f norm;
    struct plane *next;
} plane_t;

typedef struct tower {
    int co_x;
    int co_y;
    int radius;
    struct tower *next;
} tower_t;

typedef struct game {
    sfRenderWindow *win;
    sfVideoMode vm;
    sfClock *clock;
    sfEvent event;
} game_t;


//Déclaration des fonctions
int file_extractor(char *filepath, plane_t **plane, tower_t **tower);
void core(game_t *game, plane_t *plane, tower_t *tower);
static sfSprite *create_plane_sprite(int i);
void check_colision(plane_t *plane, game_t *game);
void free_planes(plane_t **list);
void free_towers(tower_t **list);
#endif /*LIST_H_*/
