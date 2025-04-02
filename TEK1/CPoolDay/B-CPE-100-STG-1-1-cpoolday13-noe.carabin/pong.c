#include <SFML/Graphics.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 60
#define BALL_SIZE 10
#define PADDLE_SPEED 20
#define BALL_SPEED_X 3
#define BALL_SPEED_Y 3

int main() {
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Pong", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfRectangleShape* paddle1 = sfRectangleShape_create();
    sfRectangleShape_setSize(paddle1, (sfVector2f){PADDLE_WIDTH, PADDLE_HEIGHT});
    sfRectangleShape_setPosition(paddle1, (sfVector2f){20, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2});
    sfRectangleShape_setFillColor(paddle1, sfWhite);

    sfRectangleShape* paddle2 = sfRectangleShape_create();
    sfRectangleShape_setSize(paddle2, (sfVector2f){PADDLE_WIDTH, PADDLE_HEIGHT});
    sfRectangleShape_setPosition(paddle2, (sfVector2f){SCREEN_WIDTH - PADDLE_WIDTH - 20, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2});
    sfRectangleShape_setFillColor(paddle2, sfWhite);

    sfRectangleShape* ball = sfRectangleShape_create();
    sfRectangleShape_setSize(ball, (sfVector2f){BALL_SIZE, BALL_SIZE});
    sfRectangleShape_setPosition(ball, (sfVector2f){SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2});
    sfRectangleShape_setFillColor(ball, sfWhite);

    int ballVelocityX = BALL_SPEED_X;
    int ballVelocityY = BALL_SPEED_Y;

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        

            if (sfKeyboard_isKeyPressed(sfKeyZ) && sfRectangleShape_getPosition(paddle1).y > 0)
            sfRectangleShape_move(paddle1, (sfVector2f){0, -PADDLE_SPEED});
        if (sfKeyboard_isKeyPressed(sfKeyS) && sfRectangleShape_getPosition(paddle1).y < SCREEN_HEIGHT - PADDLE_HEIGHT)
            sfRectangleShape_move(paddle1, (sfVector2f){0, PADDLE_SPEED});
            if (sfKeyboard_isKeyPressed(sfKeyUp) && sfRectangleShape_getPosition(paddle2)\
.y > 0)
            sfRectangleShape_move(paddle2, (sfVector2f){0, -PADDLE_SPEED});
        if (sfKeyboard_isKeyPressed(sfKeyDown) && sfRectangleShape_getPosition(paddle2).y\
 < SCREEN_HEIGHT - PADDLE_HEIGHT)
            sfRectangleShape_move(paddle2, (sfVector2f){0, PADDLE_SPEED});
        }
        // Add AI or control for the second paddle here

        sfVector2f ballPosition = sfRectangleShape_getPosition(ball);
        sfRectangleShape_move(ball, (sfVector2f){ballVelocityX, ballVelocityY});
 
        if ((ballPosition.y <= 0  && ballVelocityY < 0) ||( ballPosition.y >= SCREEN_HEIGHT - BALL_SIZE && ballVelocityY > 0))
            ballVelocityY = -ballVelocityY;

        if (ballPosition.x <= 0 || ballPosition.x >= SCREEN_WIDTH - BALL_SIZE) {
            // Ball out of bounds, reset position
            sfRectangleShape_setPosition(ball, (sfVector2f){SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2});
            ballVelocityX = BALL_SPEED_X; // Reset ball speed
        }

        // Check collision with paddles
        sfFloatRect paddle1Bounds = sfRectangleShape_getGlobalBounds(paddle1);
        sfFloatRect paddle2Bounds = sfRectangleShape_getGlobalBounds(paddle2);
        sfFloatRect ballBounds = sfRectangleShape_getGlobalBounds(ball);

        if (sfFloatRect_intersects(&paddle1Bounds, &ballBounds, NULL) || 
            sfFloatRect_intersects(&paddle2Bounds, &ballBounds, NULL)) {
            ballVelocityX = -ballVelocityX + 1;
        }
        

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, paddle1, NULL);
        sfRenderWindow_drawRectangleShape(window, paddle2, NULL);
        sfRenderWindow_drawRectangleShape(window, ball, NULL);
        sfRenderWindow_display(window);
    }

    sfRectangleShape_destroy(paddle1);
    sfRectangleShape_destroy(paddle2);
    sfRectangleShape_destroy(ball);
    sfRenderWindow_destroy(window);

    return 0;
}
