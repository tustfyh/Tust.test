//
// Created by fyh on 2023/3/18.
//
#include "resource.h"
ball* ballcreate(int x,int y,double ballspeed)//对球的区域进行初始化
{
    ball* b1= malloc(sizeof (ball));
    b1->dest.x=x;
    b1->dest.y=y;
    b1->dest.w=30;
    b1->dest.h=30;
    b1->angle=0;
    b1->speed=ballspeed;
    return b1;
}
void ball_draw(SDL_Renderer*renderer,ball*self)
{
    self->angle+=self->speed;
    SDL_RenderCopyEx(renderer,get_image_tex(),NULL,&(self->dest),self->angle,NULL,SDL_FLIP_NONE);
}
void ballfree(ball* b)
{
    free(b);
    b=NULL;
}