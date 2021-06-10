#pragma once
#include"obstacle.h"
#include"player.h"
struct GAME {
	int state;
	const int INIT = 0; //�萔
	const int PLAY = 1;
	const int OVER = 2;
	const int CLEAR = 3;
	struct OBSTACLE obstacle;
	struct PLAYER player;
};
void load(struct GAME* g);
void init(struct GAME* g);
void play(struct GAME* g);
void over(struct GAME* g);
void clear(struct GAME* g);
void draw(struct GAME* g);
int collision(struct PLAYER* p, struct OBSTACLE* o);//p.h,p.y����ǂꂾ��������
