//
// Created by fyh on 2023/3/27.
#include "resource.h"
void BGM(Mix_Music * backgrountbgm)//击杀音效
{
    backgrountbgm= Mix_LoadMUS("csgo.wav");//加载音乐
    Mix_PlayMusic(backgrountbgm,0);
    //Mix_FreeMusic(backgrountbgm);//销毁
}
void drawcube(SDL_Renderer * renderer,int x,int y,int w,int h)//绘制随机小球
{
    SDL_Texture * texture= IMG_LoadTexture(renderer,"ball.png");
    get_ball_date * ballDate= malloc(sizeof (get_ball_date));
    ballDate->date.w=w;
    ballDate->date.h=h;
    ballDate->date.x=x;
    ballDate->date.y=y;
    SDL_Rect des={ballDate->date.x,ballDate->date.y,ballDate->date.w,ballDate->date.h};
    SDL_RenderCopy(renderer,texture,NULL,&des);
    //SDL_RenderPresent(renderer);
    free(ballDate);
    SDL_DestroyTexture(texture);
}
void follow_mouse(get_follow * self_mouse,SDL_Event *event)//鼠标跟随
{
    self_mouse->src.x=event->motion.x-(self_mouse->src.w/2);
    self_mouse->src.y=event->motion.y-(self_mouse->src.h/2);
}
get_follow * get_location(int x,int y,int w,int h)
{
    get_follow * self_mouse= malloc(sizeof (get_follow));
    self_mouse->src.h=h;
    self_mouse->src.w=w;
    self_mouse->src.x=x;
    self_mouse->src.y=y;
    return self_mouse;
}
SDL_Texture * get_img_tex(SDL_Renderer * renderer)
{
    SDL_Texture *texture=IMG_LoadTexture(renderer,"zhunxing.jpg");
    return texture;
}
get_ball_date* getballdate(int x,int y,int w,int h)
{
    get_ball_date * self_ball= malloc(sizeof (get_ball_date));
    self_ball->date.h=h;
    self_ball->date.w=w;
    self_ball->date.x=x;
    self_ball->date.y=y;
    return self_ball;
}
void click_mouse(SDL_Event *event,get_ball_date * self_ball,Mix_Music * backgrountbgm)
{
    if ((event->button.x>self_ball->date.x)
    &&(event->button.x<=self_ball->date.x+self_ball->date.w)
    &&(event->button.y>self_ball->date.y)
    &&(event->button.y<=self_ball->date.y+self_ball->date.h))
    {
        if (self_ball->date.x<800&&self_ball->date.y<600)
        {

            self_ball->date.x=rand()%700;
            self_ball->date.y=rand()%500;
            BGM(backgrountbgm);
        }

    }
}
Mix_Music * get_music()
{
    Mix_Music * music=NULL;
    return music;
}