//ֲ���ս��ʬ��ʵ��
#include"resource.h"
#define WIN_W 900
#define WIN_H 600
#undef main//ʹ��sdl���ʱ��Ҫ����
//����ȫ�ֱ���
IMAGE img_bg;//����
IMAGE img_bar;//������
IMAGE img_Cards[zhiwukapai];//ֲ�￨��
IMAGE* img_zhiwu[zhiwukapai][20];//ֲ�����°ڶ�
IMAGE img_sun[29];//����
IMAGE img_js[22];//��ʬ
IMAGE img_bullet_nol;//�����ӵ�
IMAGE img_bullet_fps[4];//�������ӵ���״̬
IMAGE img_zm_dead[20];//��ʬ������ͼƬ
IMAGE img_zm_eat[21];
int curX, curY;//��¼�϶���ֲ�������
int index=-1;//ѡ�еĵ�ǰֲ����Ϊ-1����û�У�Ϊ0�ǵ�һ��ֲ��
zhiwu zhiwu_map[3][9];//��ƺ��ͼ
sunshine sun[10];//һ���Դ���ʮ������
int math_sun;
zm_js ZM[10];
bullets shoot_bullets[100];//�ӵ���


//������
int main()
{
	srand(time(NULL));
	gameinit();//��ʼ����Ϸ�����Լ�����һЩͼƬ
	menuUI();//������Ϸ�˵�
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
			update_date();//����ҡ���ٶ�
		}
	}
	system("pause");
	return 0;
}

