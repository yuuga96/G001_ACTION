#include"game.h"
#include"libOne.h"
void load(struct GAME* g) {
	load(&g->obstacle);
	load(&g->player);
}
void init(struct GAME* g) {
	init(&g->obstacle);
	init(&g->player);
	g->state = g->PLAY;	//init���I�������state��PLAY��
}
void play(struct GAME* g) {
	move(&g->obstacle);
	move(&g->player);
	clear(70, 0, 70);
	draw(g);
	if (collision(&g->player, &g->obstacle)) {
		g->state = g->OVER;
	}
	if (g->player.p.x + g->player.imgW > width) {
		g->state == g->CLEAR;
	}
}
int collision(struct PLAYER* p, struct OBSTACLE* o) {	//p.h,p.y����ǂꂾ��������
	float pLeft = p->p.x + p->r.dx;		//rectarea�̍���
	float pRight = pLeft + p->r.w;		//rectarea�̉E��
	float pTop = p->p.y + p->r.dy;		//rectarea�̏�
	float pBottom = pTop + p->r.h;		//rectarea�̉�
	float oLeft = o->p.x + o->r.dx;		//rectarea�̍���
	float oRight = oLeft + o->r.w;		//rectarea�̉E��
	float oTop = o->p.y + o->r.dy;		//rectarea�̏�
	float oBottom = oTop + o->r.h;		//rectarea�̉�
	if (pRight < oLeft || oRight < pLeft ||
		pBottom < oTop || oBottom < pTop) {
		return 0;
	}
	return 1;
}
void over(GAME* g) {
	draw(g);
	fill(180);
	textSize(300);
	text("Game Over", 100, 200);
	if (isTrigger(KEY_SPACE)) {
		g->state = g->INIT;
	}
}
void clear(struct GAME* g) {
	fill(180);
	textSize(300);
	text("Game Clear", 100, 400);
}
void draw(struct GAME* g) {
	clear(70, 0, 70);
	draw(&g->obstacle);
	draw(&g->player);
	drawRectArea(&g->obstacle.p, &g->obstacle.r);
	drawRectArea(&g->player.p, &g->player.r);
}
