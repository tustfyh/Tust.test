#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include"tools.h"
#include<time.h>
#include<SDL.h>
#include<SDL_mixer.h>
#include<math.h>
#define WIN_W 900
#define WIN_H 600
void gameinit(); 
void updategame();
void mouse_click();
void update_date();
void  menuUI();
void create_sun();
void load_sun();
void collect_sun(ExMessage* mes);
void BGM(const char *name, Mix_Music* bk_music);
void create_zm();
void update_zm();
void shoot_bullet();
void shoot_bullet_update();
void create_bullet_blats();
void check_zm_zhiwu();
void update_zhiwu();
enum
{
	wandou,//0
	xiangrikui,//1
	zhiwukapai//2，实现植物卡牌种类
};
//植物结构体
typedef struct {
	int type;//植物类型
	int curfps;//当前植物摆动的图片帧
	int dead_time;//死亡倒计时
	int status_eat;//判断植物是否被吃 0为没有，1为被吃
	int zhiwuX;
}zhiwu;
//阳光结构体
typedef struct {
	int x;
	int y;
	int curfps;
	int desY;//降落到草坪的目标位置
	float xoff;//x的偏移量
	float yoff;//y的偏移量
	int used; //判断每个阳光池是否在使用
	int time_count;//计时器
}sunshine;
//僵尸结构体
typedef struct{
	int x;
	int y;
	int curfps;
	int row;
	int used; //判断每个僵尸是否在使用
	int speed;//僵尸的移动速度
	int blood_zm;//僵尸的血量
	int status; //判断僵尸状态，0为正常，1为死亡
	int curfps_dead;//死亡的帧数号
	int zm_eating;//判断僵尸是否为持植物的状态; 0为没有吃，1为吃植物
	int zm_eat_curfps;//僵尸吃植物的帧序号
}zm_js;
//子弹结构体
typedef struct {
	int x,y;
	int row;
	int used;
	int speed;
	int status;//判断子弹状态, 0为正常，1为爆炸
	int blats_curfps;//体现爆炸子弹的当前帧序号,初始为0;
}bullets;



