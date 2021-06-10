#include"player.h"
#include"libOne.h"
void load(struct PLAYER* p) {
	p->imgIdx = loadImage("assets/witch.png");
	p->imgW = 223;
	p->imgH = 500;
}
void init(struct PLAYER* p) {
	p->p.x = 400;
	p->p.y = height - p->imgH;
	p->limmitPy = p->p.y;
	p->vx = 2;
	p->initVy = -50;		//��ɍs�������Ȃ�}�C�i�X
	p->gravity = 2;
	p->jumpFlag = 0;
	p->r.dx = 83;
	p->r.dy = 0;
	p->r.w = p->imgW - p->r.dx * 2 + 6;
	p->r.h = p->imgH;
}
void move(struct PLAYER* p) {
	p->p.x += p->vx;
	if (p->jumpFlag == 0) { // �W�����v���͂P������A���W�����v�ł��Ȃ�
		if (isTrigger(KEY_SPACE)) {
			p->vy = p->initVy;
			p->jumpFlag = 1;  //�W�����v
		}
	}
	if (p->jumpFlag == 1) {
		p->p.y+= p->vy;
		p->vy += p->gravity;   //y���v���X�����Ɖ��ɉ�����
		if (p->p.y > p->limmitPy) {
			p->p.y= p->limmitPy;
			p->jumpFlag = 0;
		}
	}
}
void draw(struct PLAYER* p) {
	image(p->imgIdx, p->p.x, p->p.y);
}

