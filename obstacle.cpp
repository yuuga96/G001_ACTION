#include"libOne.h"
#include"obstacle.h"
void load(struct OBSTACLE* o) {
	o->imgIdx = loadImage("assets/pumpkin.png");
	o->imgW = 364;
	o->imgH = 300;
}
void init(struct OBSTACLE* o) {
	o->p.x = width;				//0
	o->p.y = height - o->imgH;	//‰æ‘œ‚Ì•\Ž¦‚©‚çÚ×•\Ž¦‚Å‚‚³
	o->vx = -10;
	o->r.dx = 30;
	o->r.dy = 50;
	o->r.w = o->imgW - o->r.dx * 2;
	o->r.h = o->imgH - o->r.dy;
}
void move(struct OBSTACLE* o) {
	o->p.x += o->vx;			//10‚Å¶‚©‚ç‰E
	if (o->p.x < -o->imgW) {
		o->p.x = width;
	}
}
void draw(struct OBSTACLE* o) {
	image(o->imgIdx, o->p.x, o->p.y);
}