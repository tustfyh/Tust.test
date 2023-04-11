#pragma once
#include"resource.h"
extern IMAGE img_bg;
extern IMAGE img_bar;
extern IMAGE img_Cards[zhiwukapai];
extern IMAGE* img_zhiwu[zhiwukapai][20];
extern int curX, curY;//记录拖动的植物的坐标
extern int index;
extern zhiwu zhiwu_map[3][9];
extern IMAGE img_sun[29];//阳光变量
extern sunshine sun[10];//阳光池
extern int math_sun;//阳光数
extern IMAGE img_js[22];//加载僵尸图片
extern zm_js ZM[10];//僵尸数量
extern IMAGE img_bullet_nol;//
extern IMAGE img_bullet;
extern bullets shoot_bullets[100];
extern IMAGE img_bullet_fps[4];
extern IMAGE img_zm_dead[20];
extern IMAGE img_zm_eat[21];