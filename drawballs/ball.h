//
// Created by fyh on 2023/3/18.
//

#ifndef DRAWBALLS_BALL_H
#define DRAWBALLS_BALL_H
#define FILE_NAME "ball.png"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#undef main
#define WIDTH 800
#define HEIGHT 600
#define FPS 60
typedef struct
{
    SDL_Rect dest;
    double speed;
    double angle;
}ball;
ball* ballcreate(int x,int y,double ballspeed);
void ball_draw(SDL_Renderer*renderer,ball*self);
void ballfree(ball* b);
#endif //DRAWBALLS_BALL_H
