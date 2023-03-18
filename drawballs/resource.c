//
// Created by fyh on 2023/3/18.
//
#include "ball.h"
#include "resource.h"
SDL_Texture*imageTexture;
void imgload(SDL_Renderer* renderer)
{
    imageTexture= IMG_LoadTexture(renderer,FILE_NAME);
    if(imageTexture==NULL)
    {
        printf("%s", IMG_GetError());
        return;
    }
}

SDL_Texture* get_image_tex()//重点，bug来源
{
    return imageTexture;
}

void imgunload()
{
    SDL_DestroyTexture(imageTexture);
}