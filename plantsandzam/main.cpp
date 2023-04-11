//植物大战僵尸的实现
#include"resource.h"
#define WIN_W 900
#define WIN_H 600
#undef main//使用sdl库的时候要加上
//加载全局变量
IMAGE img_bg;//背景
IMAGE img_bar;//工具栏
IMAGE img_Cards[zhiwukapai];//植物卡牌
IMAGE* img_zhiwu[zhiwukapai][20];//植物种下摆动
IMAGE img_sun[29];//阳光
IMAGE img_js[22];//僵尸
IMAGE img_bullet_nol;//正常子弹
IMAGE img_bullet_fps[4];//非正常子弹的状态
IMAGE img_zm_dead[20];//僵尸死亡的图片
IMAGE img_zm_eat[21];
int curX, curY;//记录拖动的植物的坐标
int index=-1;//选中的当前植物，如果为-1，则没有，为0是第一种植物
zhiwu zhiwu_map[3][9];//草坪地图
sunshine sun[10];//一次性创建十个阳光
int math_sun;
zm_js ZM[10];
bullets shoot_bullets[100];//子弹池


//主函数
int main()
{
	srand(time(NULL));
	gameinit();//初始化游戏窗口以及加载一些图片
	menuUI();//创建游戏菜单
	int time = 0;
	bool fg = true;
	while (1)
	{
		mouse_click();
		updategame();
		time += getDelay();
		if (time>80)
		{
			fg = true;
			time = 0;
		}
		if (fg)
		{
			fg = false;
			update_date();//控制摇摆速度
		}
	}
	system("pause");
	return 0;
}

