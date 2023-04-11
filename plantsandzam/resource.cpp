#include"resource.h"
#include"allvariable.h"
void gameinit()
{
	memset(zhiwu_map, -1, sizeof(zhiwu_map));
	memset(img_zhiwu, 0, sizeof(img_zhiwu));//������ڴ��ʼ��Ϊ0
	memset(sun, 0, sizeof(sun));
	memset(ZM, 0, sizeof(ZM));
	memset(shoot_bullets, 0, sizeof(shoot_bullets));
	//���ش���
	initgraph(WIN_W, WIN_H);
	math_sun = 25;
	//������Ϸ����
	loadimage(&img_bg, "res/bg.jpg");
	loadimage(&img_bar, "res/bar5.png");
	//��ѭ���ķ�ʽ����ֲ�￨Ƭ
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
	//ѭ���ķ�ʽ��������
	for (int i = 0; i < 29; i++)
	{
		sprintf_s(name, sizeof(name), "res/sunshine/%d.png", i + 1);
		loadimage(&img_sun[i], name);
	}
	//��������
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = 60;
	strcpy(f.lfFaceName, "Segoe UI BLACK");
	f.lfQuality = ANTIALIASED_QUALITY;//�����Ч��
	setcolor(BLACK);
	setbkmode(TRANSPARENT);//����͸����
	settextstyle(&f);
	//��ʼ�����ֲ�����
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("Failed to initialize SDL_mixer!\n");
		return;
	}
	//���ؽ�ʬ
	for (int i = 0; i < 22; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm/%d.png", i + 1);
		loadimage(&img_js[i], name);
	}
	//�����ӵ�������״̬
	loadimage(&img_bullet_nol, "res/bullets/bullet_normal.png");
	//���ر�ը����
	loadimage(&img_bullet_fps[3], "res/bullets/bullet_blast.png");
	for (int i = 0; i < 3; i++)
	{
		float k = 0.2 * (i + 1);
		loadimage(&img_bullet_fps[i], "res/bullets/bullet_blast.png",
			img_bullet_fps[i].getwidth() * k, 
			img_bullet_fps[i].getheight() * k, true);

	}
	//���ؽ�ʬ������
	for (int i = 0; i < 20; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm_dead/%d.png", i + 1);
		loadimage(&img_zm_dead[i], name);
	}
	//���ؽ�ʬ��ֲ���ͼƬ
	for (int i = 0; i < 21; i++)
	{
		sprintf_s(name, sizeof(name), "res/zm_eat/%d.png", i + 1);
		loadimage(&img_zm_eat[i], name);
	}
}
void updategame()
{
	BeginBatchDraw();//��ʼ���壬��ֹ��˸
	putimage(0, 0, &img_bg);//������Ⱦ
	putimagePNG(250, 0, &img_bar);//��������Ⱦ
	//ѭ����ӡ���϶���Ⱦ
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
	//��ֲ��Ⱦ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (zhiwu_map[i][j].type>-1)
			{
				int x = 256 + j * 81;
				int y = 179 + i * 102;
				int zhiwuid = zhiwu_map[i][j].type;
				int png = zhiwu_map[i][j].curfps;//�ոտ�ʼΪ0
				putimagePNG(x, y, img_zhiwu[zhiwuid][png]);
			}
		}
	}
	//��Ⱦ����
	for (int i = 0; i < 10; i++)
	{
		if (sun[i].used || sun[i].xoff)
		{
			putimagePNG(sun[i].x,sun[i].y,&img_sun[sun[i].curfps]);
		}
	}
	//��Ⱦ����
	char scorce_sun[8];
	sprintf_s(scorce_sun, sizeof(scorce_sun), "%d", math_sun);
	outtextxy(281, 68, scorce_sun);
	//��Ⱦ��ʬ
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

	//��Ⱦ�ӵ�
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
	//��Ⱦ��ʬ��ֲ��
	for (int i = 0; i < 10; i++)
	{
		if (ZM[i].zm_eating&&ZM[i].used)
		{
			putimagePNG(ZM[i].x,
			ZM[i].y - (&img_zm_eat[ZM[i].zm_eat_curfps])->getheight(),
			&img_zm_eat[ZM[i].zm_eat_curfps]);
		}
	}
	EndBatchDraw();//��������
}
void mouse_click()
{
	ExMessage mes;
	static int count = 0;
	if (peekmessage(&mes))
	{
		if (mes.message == WM_LBUTTONDOWN)
		{
			//����������
			if (mes.x > 338 && mes.x < 338 + 64 * zhiwukapai && mes.y < 96)
			{
				index = (mes.x - 338) / 65;
				count = 1;

			}
			else {//�ж��Ƿ�������,�����ռ�
				collect_sun(&mes);
			}

		}
		else if (mes.message == WM_MOUSEMOVE)
		{
			//����ƶ�
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

				int row = (mes.y - 179) / 102;//���� 0~2;
				int col = (mes.x - 256) / 81;//����
				if (zhiwu_map[row][col].type == -1)//�������-1��˵��û��ֲ��
				{
					zhiwu_map[row][col].type = index;//��¼�µ��ʱ��ֲ������
					zhiwu_map[row][col].curfps = 0;//��¼��Ҫ��Ⱦ��ͼƬ
				}
			}
			index = -1;
			count = 0;
		}
	}
}
void update_date()
{

	update_zhiwu();//ֲ�����ݵĸ���

	create_sun();//�����������
	load_sun();//�����������

	create_zm();//������ʬ
	update_zm();//���½�ʬ����


	shoot_bullet();//�����ӵ�
	shoot_bullet_update();//�����ӵ�λ��
	create_bullet_blats();//ʵ���ӵ��ı�ը
	check_zm_zhiwu();//ʵ�ֽ�ʬ��ֲ��
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
		//��λ����� flagΪ�棬 &img_menu1 ��Ϊ�٣�&img_menu2
		ExMessage meg;
		if (peekmessage(&meg))//�ж���û�������Ϣ
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
			 
			if (sun[i].time_count==0)//��ʱ������Ҫ��
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
			if (mes->x > x && mes->x<x + w && mes->y>y && mes->y < y + h)//���������
			{
				//����
				Mix_Music* bk_music = NULL;
				BGM("res/sunshine.mp3",bk_music);
				sun[i].used = 0;
				Mix_FreeMusic(bk_music);
				//����ƫ����
				float destx = 262;
				float desty = 0;
				float angle = atan((y - desty) / (x - destx));//����Ƕ�
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
	static int count=0;//������
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
			ZM[i].row = rand() % 3;//0~~~2 ����
			ZM[i].y = 172 + (1 + ZM[i].row) * 100;
			ZM[i].speed = 1;
			ZM[i].blood_zm = 100;//��ʬѪ��Ϊһ��
			ZM[i].zm_eating = 0;//�տ�ʼû�г�ֲ��
		}
	}
}
void update_zm()
{
	for (int  i = 0; i < 10; i++)
	{
		//���½�ʬλ��
		if (ZM[i].used)
		{
			ZM[i].x -= ZM[i].speed;
			if (ZM[i].x < 170)
			{
				//������Ϸ---���Ż�
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
	
	

