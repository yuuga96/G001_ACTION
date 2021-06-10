#pragma once
#include"float2.h"
#include"rect_area.h"
struct PLAYER {
	int imgIdx = 0;
	int imgW = 0;
	int imgH = 0;
	struct FLOAT2 p; //px,py��p��
	float vx = 0;
	float vy = 0;
	float initVy = 0;
	float gravity = 0;     //�d��
	int jumpFlag = 0;		//�W�����v���Ă邩
	float limmitPy = 0;		//���n�_��ݒ�
	struct RECT_AREA r;
};
void load(struct PLAYER* p);
void init(struct PLAYER* p);
void move(struct PLAYER* p);
void draw(struct PLAYER* p);

