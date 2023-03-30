//
// Created by fyh on 2023/3/27.
//

#ifndef PROJECT1_RESOURCE_H
#define PROJECT1_RESOURCE_H
#include <stdio.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
typedef struct {
    SDL_Rect src;
}get_follow;
typedef struct {
    SDL_Rect  date;
}get_ball_date;
SDL_Texture * get_img_tex(SDL_Renderer * renderer);
get_follow * get_location(int x,int y,int w,int h);
void BGM(Mix_Music *backgrountbgm);
void drawcube(SDL_Renderer * renderer,int x,int y,int w,int h);
void follow_mouse(get_follow * self,SDL_Event *event);
void click_mouse(SDL_Event *event,get_ball_date * self_ball,Mix_Music * backgrountbgm);
get_ball_date* getballdate(int x,int y,int w,int h);
Mix_Music * get_music();
#endif //PROJECT1_RESOURCE_H
