
#include <stdlib.h>
#include "resource.h"
#undef main
#define HEIGHT 600
#define WIDTH 800
#define FPS 60
get_follow * self_mouse;
get_ball_date * self_ball;
Mix_Music * backgrountbgm;
void draw(SDL_Renderer *renderer)//绘制准星
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_Rect src={self_mouse->src.x,self_mouse->src.y,self_mouse->src.w,self_mouse->src.h};
    SDL_RenderCopy(renderer, get_img_tex(renderer),NULL,&src);
    drawcube(renderer,self_ball->date.x,self_ball->date.y,self_ball->date.w,self_ball->date.h);
    SDL_RenderPresent(renderer);
}
void event_loop(SDL_Renderer *renderer)
{

    while(1)
    {
        int begin01=SDL_GetTicks();
        SDL_Event event;
        draw(renderer);
        while(SDL_PollEvent(&event))
        {
            follow_mouse(self_mouse,&event);
            if (event.type==SDL_QUIT)
            {
                return;
            }
            else if (event.type==SDL_MOUSEMOTION)
            {
                follow_mouse(self_mouse,&event);
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                click_mouse(&event,self_ball,backgrountbgm);
            }
        }
        int end01=SDL_GetTicks();
        SDL_Delay((1000/FPS)-(begin01-end01));

    }
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);//初始化窗口
    //创建窗口
    SDL_Window * win= SDL_CreateWindow(
            "只因你太美",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,
            SDL_WINDOW_SHOWN);
    //初始化音乐播放器
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Failed to initialize SDL_mixer!\n");
        return 1;
    }
    //创建渲染器
    SDL_Renderer *renderer= SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(0);//隐藏鼠标
    //加载变量
    backgrountbgm= get_music();//加载音乐
    self_mouse= get_location(0,0,25,25);//准星的加载
    self_ball= getballdate(0,0,40,40);//小球的加载
    //主事件循环
    event_loop(renderer);
    //销毁垃圾场
    free(self_ball);
    free(self_mouse);
    Mix_FreeMusic(backgrountbgm);
    SDL_DestroyWindow(win);
    return 0;
}
