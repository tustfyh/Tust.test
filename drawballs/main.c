#include "resource.h"
#define BALLS_COUNT 5
ball *ball1[BALLS_COUNT];
void creatballs()
{
    for (int i = 0; i < BALLS_COUNT; ++i)
    {
        ball1[i]=ballcreate(40*i,10,(rand()%10)-5);
    }
}
void draw( SDL_Renderer *renderer)
{
    //背景
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    for (int i = 0; i < BALLS_COUNT; ++i)
    {
        ball_draw(renderer,ball1[i]);
    }

    SDL_RenderPresent(renderer);//将渲染修改发送到屏幕
}
void creatthing(SDL_Renderer *renderer)//创建一个事件
{
    while(1)
    {
        int begin=SDL_GetTicks();
        SDL_Event event;
        draw(renderer);
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }
        }
        int end=SDL_GetTicks();
        int sleep=1000/FPS;
        if ((sleep-(end-begin))>0)
        {
            SDL_Delay(sleep-(end-begin));
        }

    }
}
int main()
{
    SDL_Init(SDL_INIT_VIDEO);//初始化

    SDL_Window *window =SDL_CreateWindow(
            "hello game",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,HEIGHT,
            SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer= SDL_CreateRenderer(window ,-1,SDL_RENDERER_ACCELERATED);//初始化渲染

    imgload(renderer);//使用相对路径
    creatballs();
    creatthing(renderer);//创建一个事件
    for (int i = 0; i < BALLS_COUNT; ++i)
    {
        ballfree(ball1[i]);
    }
    SDL_DestroyRenderer(renderer);
    imgunload(get_image_tex());
    SDL_DestroyWindow(window);
    return 0;
}