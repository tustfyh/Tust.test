#include <stdio.h>
#include <SDL2/SDL.h>
#undef main
#define WIDTH 800
#define HEIGHT 600
#define FPS 60
int x=0;
void creatcube(SDL_Window * win,SDL_Surface *screen)//将屏幕变为白色，并且为中心绘制一个小方块
{
    x++;
    SDL_Rect minwin={0,0,WIDTH,HEIGHT};//在原始窗口上加一个图层
    SDL_FillRect(screen,&minwin,0xffffffff);
    //通过对x的坐标加，实现简单的动画
    SDL_Rect minwin01={0.5*(WIDTH-WIDTH*0.25)+x,0.5*(HEIGHT-HEIGHT*0.25),WIDTH*0.25,HEIGHT*0.25};
    SDL_FillRect(screen,&minwin01,0xffff0000);
    SDL_UpdateWindowSurface(win);
    //for(j=0;j<100;j++)
    //{
    // ((int*)(screen->pixels))[WIDTH*50+50]=0xffff0000;//直接修改像素
    //}
    SDL_UpdateWindowSurface(win);
}
void creatething(SDL_Window * win,SDL_Surface *screen)//创建一个事件循环
{
    //创建一个死循环，若type值等于SDL_QUIT，则跳出循环
    while(1)
    {
        //控制fps原理：在程序开始和结束插入SDL_GetTicks获取运行时间插b，然后计算出60针所需时间a，然后用a-b得到休眠所需时间
        int begin=SDL_GetTicks();//该函数是记录程序运行时间
        creatcube(win,screen);
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT) //
            {
                return;
            }
        }
        int end=SDL_GetTicks();
        int sleep=(1000/FPS)-(begin-end);
        if(sleep>0)
        {
            SDL_Delay(sleep);
        }
    }
}
int main()
{
    if(SDL_Init(SDL_INIT_VIDEO))//初始化屏幕，发生错误返回一个非零数，正常返回一个0
    {
        printf("%s",SDL_GetError());//获取错误值，打印出错误原因
        return 1;
    }
    SDL_Window * win=SDL_CreateWindow(
            "hello world",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,
            SDL_WINDOW_SHOWN);//创建一个窗口,若失败，win会返回一个空指针
    if (win==NULL)
    {
        printf("%s", SDL_GetError());
        return 2;
    }
    SDL_Surface *screen=SDL_GetWindowSurface(win);//将窗口抽象出来并且交给一个SDL_Surface指针
    creatething(win,screen);//事件函数
    SDL_DestroyWindow(win); //销毁窗口
    return 0;
}
