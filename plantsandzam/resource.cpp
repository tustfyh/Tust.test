#include"resource.h"
#include"allvariable.h"
void gameinit()
{
	memset(zhiwu_map, -1, sizeof(zhiwu_map));
	memset(img_zhiwu, 0, sizeof(img_zhiwu));//将这块内存初始化为0
	memset(sun, 0, sizeof(sun));
	memset(ZM, 0, sizeof(ZM));
	memset(shoot_bullets, 0, sizeof(shoot_bullets));
	//加载窗口
	initgraph(WIN_W, WIN_H);
	math_sun = 25;
	//加载游戏背景
	loadimage(&img_bg, "res/bg.jpg");
	loadimage(&img_bar, "res/bar5.png");
	//已循环的方式加载植物卡片
	char name[64];
	for (int i = 0; i < zhiwukapai; i++)
	{
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(&img_Cards[i], name);
		for (int j = 0; j < 20; j++)
		{
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", i, j + 1);
			FILE* fp = fopen(name, "r");
			if (fp != NULL)
			{
				img_zhiwu[i][j] = new IMAGE;
				loadimage(img_zhiwu[i][j], name);
				fclose(fp);
			}
		}
	}
	//循环的方式加载阳光
	for (int i = 0; i < 29; i++)
	{
		sprintf_s(name, sizeof(name), "res/sunshine/%d.png", i + 1);
		loadimage(&img_sun[i], name);
	}
	//加载文字
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = 60;
	strcpy(f.lfFaceName, "Segoe UI BLACK");
	f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿效果
	setcolor(BLACK);
	setbkmode(TRANSPARENT);//设置透明度
	settextstyle(&f);
	//初始化音乐播放器
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("Failed to initialize SDL_mixer!\n");
		return;
	}
	//加载僵尸
	for (int i = 0; i < 22; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm/%d.png", i + 1);
		loadimage(&img_js[i], name);
	}
	//加载子弹的两种状态
	loadimage(&img_bullet_nol, "res/bullets/bullet_normal.png");
	//加载爆炸动画
	loadimage(&img_bullet_fps[3], "res/bullets/bullet_blast.png");
	for (int i = 0; i < 3; i++)
	{
		float k = 0.2 * (i + 1);
		loadimage(&img_bullet_fps[i], "res/bullets/bullet_blast.png",
			img_bullet_fps[i].getwidth() * k, 
			img_bullet_fps[i].getheight() * k, true);

	}
	//加载僵尸的死亡
	for (int i = 0; i < 20; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm_dead/%d.png", i + 1);
		loadimage(&img_zm_dead[i], name);
	}
	//加载僵尸吃植物的图片
	for (int i = 0; i < 21; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm_eat/%d.png", i + 1);
		loadimage(&img_zm_eat[i], name);
	}
}
void updategame()
{
	BeginBatchDraw();//开始缓冲，防止闪烁
	putimage(0, 0, &img_bg);//背景渲染
	putimagePNG(250, 0, &img_bar);//工具栏渲染
	//循环打印，拖动渲染
	for (int i = 0; i < zhiwukapai; i++)
	{
		int x = 338 + 64 * i;
		int y = 6;
		putimage(x, y, &img_Cards[i]);
	}
	if (index > -1)
	{
		IMAGE* img = img_zhiwu[index][0];
		putimagePNG(curX - img->getwidth() / 2, curY - img->getheight() / 2, img);
	}
	//种植渲染
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (zhiwu_map[i][j].type>-1)
			{
				int x = 256 + j * 81;
				int y = 179 + i * 102;
				int zhiwuid = zhiwu_map[i][j].type;
				int png = zhiwu_map[i][j].curfps;//刚刚开始为0
				putimagePNG(x, y, img_zhiwu[zhiwuid][png]);
			}
		}
	}
	//渲染阳光
	for (int i = 0; i < 10; i++)
	{
		if (sun[i].used || sun[i].xoff)
		{
			putimagePNG(sun[i].x,sun[i].y,&img_sun[sun[i].curfps]);
		}
	}
	//渲染文字
	char scorce_sun[8];
	sprintf_s(scorce_sun, sizeof(scorce_sun), "%d", math_sun);
	outtextxy(281, 68, scorce_sun);
	//渲染僵尸
	for (int i = 0; i < 10; i++)
	{
		if (ZM[i].used)
		{
			if (ZM[i].status==0)
			{
				putimagePNG(ZM[i].x,
					ZM[i].y - (&img_js[ZM[i].curfps])->getheight(),
					&img_js[ZM[i].curfps]);
			}
			else if (ZM[i].status)
			{
				putimagePNG(ZM[i].x,
					ZM[i].y - (&img_js[ZM[i].curfps])->getheight(),
					&img_zm_dead[ZM[i].curfps_dead]);
			}
			
		}
	}

	//渲染子弹
	for (int i = 0; i <30; i++)
	{
		if (shoot_bullets[i].used)
		{
			if (shoot_bullets[i].status)
			{
				putimagePNG(shoot_bullets[i].x, shoot_bullets[i].y, &img_bullet_fps[shoot_bullets[i].blats_curfps]);
			}
			else
			{
				putimagePNG(shoot_bullets[i].x, shoot_bullets[i].y, &img_bullet_nol);
			}
		}
	}
	//渲染僵尸吃植物
	for (int i = 0; i < 10; i++)
	{
		if (ZM[i].zm_eating&&ZM[i].used)
		{
			putimagePNG(ZM[i].x,
			ZM[i].y - (&img_zm_eat[ZM[i].zm_eat_curfps])->getheight(),
			&img_zm_eat[ZM[i].zm_eat_curfps]);
		}
	}
	EndBatchDraw();//结束缓冲
}
void mouse_click()
{
	ExMessage mes;
	static int count = 0;
	if (peekmessage(&mes))
	{
		if (mes.message == WM_LBUTTONDOWN)
		{
			//鼠标左键按下
			if (mes.x > 338 && mes.x < 338 + 64 * zhiwukapai && mes.y < 96)
			{
				index = (mes.x - 338) / 65;
				count = 1;

			}
			else {//判断是否点击阳光,并且收集
				collect_sun(&mes);
			}

		}
		else if (mes.message == WM_MOUSEMOVE)
		{
			//鼠标移动
			if (count)
			{
				curX = mes.x;
				curY = mes.y;
			}
		}
		else if(mes.message == WM_LBUTTONUP)
		{
			if (mes.x > 256 && mes.y > 179 && mes.y < 489)
			{

				int row = (mes.y - 179) / 102;//行数 0~2;
				int col = (mes.x - 256) / 81;//列数
				if (zhiwu_map[row][col].type == -1)//如果等于-1，说明没有植物
				{
					zhiwu_map[row][col].type = index;//记录下点击时的植物类型
					zhiwu_map[row][col].curfps = 0;//记录下要渲染的图片
				}
			}
			index = -1;
			count = 0;
		}
	}
}
void update_date()
{

	update_zhiwu();//植物数据的更新

	create_sun();//创建随机阳光
	load_sun();//生产随机阳光

	create_zm();//创建僵尸
	update_zm();//更新僵尸数据


	shoot_bullet();//发射子弹
	shoot_bullet_update();//更新子弹位置
	create_bullet_blats();//实现子弹的爆炸
	check_zm_zhiwu();//实现僵尸吃植物
}
void menuUI()
{
	IMAGE img_menu, img_menu1, img_menu2;
	loadimage(&img_menu, "res/menu.png");
	loadimage(&img_menu1, "res/menu1.png");
	loadimage(&img_menu2, "res/menu2.png");
	int flag = 0;
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &img_menu);
		putimagePNG(474, 75, flag ? &img_menu1 : &img_menu2);
		//三位运算符 flag为真， &img_menu1 ，为假，&img_menu2
		ExMessage meg;
		if (peekmessage(&meg))//判断有没有鼠标消息
		{
			if (meg.message == WM_LBUTTONDOWN)
			{
				if (meg.x > 475 && meg.x < 475 + (&img_menu1)->getwidth() &&
					meg.y>75 && meg.y < 75 + (&img_menu1)->getheight())
				{
					flag = 1;
				}
			}
			else if (flag && meg.message == WM_LBUTTONUP)
			{
					return;
			}
		}
		EndBatchDraw();
	}
	
}
void create_sun()
{	
	static int count = 0;
	static int limit = 10;
	count++;
	if (count>=limit)
	{
		limit = 100 + rand() % ( 250- 100);
		count = 0;
		int i;
		int sz_sun = sizeof(sun) / sizeof(sun[0]);
		for (i = 0; i < sz_sun && sun[i].used; i++)
		if (i >= sz_sun)
		{
			return;
		}
		sun[i].used = true;
		sun[i].curfps = 1;
		sun[i].x = 260 + rand() % (700 - 260);
		sun[i].y = 60;
		sun[i].desY = 200 + rand() % (470 - 200);
	}
}
void load_sun()
{
	int sz_sun = sizeof(sun) / sizeof(sun[0]);
	for (int i = 0; i < sz_sun; i++)
	{     
		if (sun[i].used)
		{
			sun[i].curfps = (sun[i].curfps + 1) % 29; 
			 
			if (sun[i].time_count==0)//计时器的重要性
			{
				sun[i].y += 3;
			}
			if (sun[i].y>=sun[i].desY)
			{
				sun[i].time_count++;
				if (sun[i].time_count >100)
				{
					sun[i].time_count = 0;
					sun[i].used = 0;
				}
			}
		}
		else if (sun[i].xoff)
		{
			sun[i].x -= sun[i].xoff;
			sun[i].y -= sun[i].yoff;
			if (sun[i].x < 262 || sun[i].y<0)
			{
				sun[i].xoff = 0;
				sun[i].yoff = 0;
				math_sun += 25;
			}
		}
	}
}
void collect_sun(ExMessage* mes)
{
	for (int i = 0; i < 10; i++)
	{
		if (sun[i].used)
		{
			int x = sun[i].x;
			int y = sun[i].y;
			int w = img_sun[0].getheight();
			int h = img_sun[0].getwidth();
			if (mes->x > x && mes->x<x + w && mes->y>y && mes->y < y + h)//点击到阳光
			{
				//音乐
				Mix_Music* bk_music = NULL;
				BGM("res/sunshine.mp3",bk_music);
				sun[i].used = 0;
				Mix_FreeMusic(bk_music);
				//设置偏移量
				float destx = 262;
				float desty = 0;
				float angle = atan((y - desty) / (x - destx));//计算角度
				sun[i].xoff = 16 * cos(angle);
				sun[i].yoff = 16 * sin(angle);
			}
		}
	}
}
void BGM(const char* name, Mix_Music* bk_music)
{
	bk_music = Mix_LoadMUS(name);
	Mix_PlayMusic(bk_music,0);
}
void create_zm()
{
	static int count=0;//计数器
	static int limit = 100;
	count++;
	if (count > limit)
	{
		count = 0;
		limit = 100 + rand() % (250 - 100);
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			if (ZM[i].used == 0)
			{
				break;
			}
		}
		if (i < 10)
		{
			memset(&ZM[i], 0, sizeof(ZM[i]));
			ZM[i].used = 1;
			ZM[i].x = WIN_W;
			ZM[i].row = rand() % 3;//0~~~2 整数
			ZM[i].y = 172 + (1 + ZM[i].row) * 100;
			ZM[i].speed = 1;
			ZM[i].blood_zm = 100;//僵尸血量为一百
			ZM[i].zm_eating = 0;//刚开始没有吃植物
		}
	}
}
void update_zm()
{
	for (int  i = 0; i < 10; i++)
	{
		//更新僵尸位置
		if (ZM[i].used)
		{
			ZM[i].x -= ZM[i].speed;
			if (ZM[i].x < 170)
			{
				//结束游戏---待优化
				MessageBox(NULL, "over", "over", 0);
				exit(0);
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (ZM[i].used)
		{
			ZM[i].curfps = (ZM[i].curfps+1) % 22;
			if (ZM[i].curfps == 22)
			{
				ZM[i].curfps = 0;
			}
			if (ZM[i].blood_zm<=0)
			{
				ZM[i].curfps_dead++;
				ZM[i].speed = 0;
				ZM[i].status = 1;
				if (ZM[i].curfps_dead>=20)
				{
					ZM[i].used=0;
					ZM[i].curfps_dead = 0;
					ZM[i].status = 0;
				}
			}
			if (ZM[i].zm_eating)
			{
				ZM[i].zm_eat_curfps = (ZM[i].zm_eat_curfps + 1) % 21;
			}
		}
	}
}
void shoot_bullet()
{
	int bullets_sz = sizeof(shoot_bullets) / sizeof(shoot_bullets[0]);
	for (int k = 0; k< 10; k++)
	{
		if (ZM[k].used && ZM[k].x<WIN_W)
		{
			for (int i = 0;i< 3; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (zhiwu_map[i][j].type == wandou && i==ZM[k].row)
					{
						static int count = 0;
						count++;
						if (count>25)
						{
							int n;
							count = 0;
							for ( n = 0; n < bullets_sz; n++)
							{
								if (shoot_bullets[n].used==0)
								{
									break;
								}
							}
							if (n< bullets_sz)
							{
								int zwx = 256 + j* 81;
								int zwy = 179 + i* 102;
								shoot_bullets[n].used = 1;
								shoot_bullets[n].row = ZM[k].row;
								shoot_bullets[n].speed = 6;
								shoot_bullets[n].x = zwx + img_zhiwu[zhiwu_map[i][j].type][0]->getheight() - 10;
								shoot_bullets[n].y = zwy + 5;
							}
						}
					}
				}
			}
		}
	}
}
void shoot_bullet_update()
{
	int bullets_sz = sizeof(shoot_bullets) / sizeof(shoot_bullets[0]);
	for (int i = 0; i < bullets_sz; i++)
	{
		if (shoot_bullets[i].used)
		{
			shoot_bullets[i].x += shoot_bullets[i].speed;
			if (shoot_bullets[i].x > WIN_W)
			{
				shoot_bullets[i].used = 0;
				shoot_bullets[i].x = 0;
			}
			if (shoot_bullets[i].status==1)
			{
				shoot_bullets[i].blats_curfps++;
				if (shoot_bullets[i].blats_curfps>=4)
				{
					shoot_bullets[i].used = 0;
					shoot_bullets[i].blats_curfps = 0;
					shoot_bullets[i].status = 0;
				}
			}
		}
	}
}
void create_bullet_blats()
{
	int bullets_sz = sizeof(shoot_bullets) / sizeof(shoot_bullets[0]);
	for (int i = 0; i < bullets_sz; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (shoot_bullets[i].status == 0 && shoot_bullets[i].used && ZM[j].used)
			{
				int x1 = ZM[j].x + 75;
				int x2 = ZM[j].x + 110;
				int x = shoot_bullets[i].x;
				if (x>x1 && x<x2 && shoot_bullets[i].row==ZM[j].row)
				{
					ZM[j].blood_zm -= 10;
					shoot_bullets[i].speed = 0;
					shoot_bullets[i].status = 1;
				}
			}
		}
	}
}

void update_zhiwu()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (zhiwu_map[i][j].type > -1)
			{
				zhiwu_map[i][j].curfps++;
				zhiwu_map[i][j].zhiwuX = 256 + j * 81;
				int type = zhiwu_map[i][j].type;
				int id = zhiwu_map[i][j].curfps;
				if (img_zhiwu[type][id] == 0)
				{
					zhiwu_map[i][j].curfps = 0;
				}
			}
		}
	}
}

void check_zm_zhiwu()
{
	int zmcount = sizeof(ZM) / sizeof(ZM[0]);
	for (int i = 0; i < zmcount; i++)
	{
		int row = ZM[i].row;
		for (int  k = 0; k < 9; k++)
		{
			int x1 = zhiwu_map[row][k].zhiwuX + 10;
			int x2 = zhiwu_map[row][k].zhiwuX + 60;
			int x3 = ZM[i].x + 80; 
			if (x3 > x1 && x3 < x2)
			{	
				if (zhiwu_map[row][k].status_eat)
				{
					ZM[i].zm_eat_curfps++;
					if (ZM[i].zm_eat_curfps>100)
					{
						ZM[i].speed = 1;
						zhiwu_map[row][k].dead_time = 0;
						zhiwu_map[row][k].type = -1;
						ZM[i].zm_eating = 0;
						ZM[i].zm_eat_curfps = 0;
					}
				}
				else
				{
					zhiwu_map[row][k].status_eat = 1;
					ZM[i].speed = 0;
					ZM[i].zm_eating = 1;
					ZM[i].zm_eat_curfps = 0;
					zhiwu_map[row][k].dead_time = 0;
				}
			}
		}
	}
}
	
	

