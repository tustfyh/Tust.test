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
	zhiwukapai//2��ʵ��ֲ�￨������
};
//ֲ��ṹ��
typedef struct {
	int type;//ֲ������
	int curfps;//��ǰֲ��ڶ���ͼƬ֡
	int dead_time;//��������ʱ
	int status_eat;//�ж�ֲ���Ƿ񱻳� 0Ϊû�У�1Ϊ����
	int zhiwuX;
}zhiwu;
//����ṹ��
typedef struct {
	int x;
	int y;
	int curfps;
	int desY;//���䵽��ƺ��Ŀ��λ��
	float xoff;//x��ƫ����
	float yoff;//y��ƫ����
	int used; //�ж�ÿ��������Ƿ���ʹ��
	int time_count;//��ʱ��
}sunshine;
//��ʬ�ṹ��
typedef struct{
	int x;
	int y;
	int curfps;
	int row;
	int used; //�ж�ÿ����ʬ�Ƿ���ʹ��
	int speed;//��ʬ���ƶ��ٶ�
	int blood_zm;//��ʬ��Ѫ��
	int status; //�жϽ�ʬ״̬��0Ϊ������1Ϊ����
	int curfps_dead;//������֡����
	int zm_eating;//�жϽ�ʬ�Ƿ�Ϊ��ֲ���״̬; 0Ϊû�гԣ�1Ϊ��ֲ��
	int zm_eat_curfps;//��ʬ��ֲ���֡���
}zm_js;
//�ӵ��ṹ��
typedef struct {
	int x,y;
	int row;
	int used;
	int speed;
	int status;//�ж��ӵ�״̬, 0Ϊ������1Ϊ��ը
	int blats_curfps;//���ֱ�ը�ӵ��ĵ�ǰ֡���,��ʼΪ0;
}bullets;



