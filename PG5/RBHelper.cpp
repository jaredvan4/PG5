#include "RBHelper.h"

bool getcolor(RBTreeNode* n) {
	if (!n) {
		return true;
	}
	return n->isblack();
}

RBTreeNode* getsibling(RBTreeNode* n, RBTreeNode* p) {
	if (p->getleft() == n) {
		return p->getright();
	}
	else {
		return p->getleft();
	}
}

void DelProcess(RBTreeNode* x, RBTreeNode* p) {
	RBTreeNode* Z;
	RBTreeNode* W = getsibling(x, p);
	if (getcolor(x) == false) {
		x->setblack(true);
		return;
	}
	if (!p) {
		return;
	}
	if (getcolor(W) == false) {
		W->rotate();
		DelProcess(x,p);
		return;
	}
	if (getcolor(W->getleft()) == true && getcolor(W->getright()) == true) {
		W->setblack(false);
		x = p;
		p = p->getparent();
		DelProcess(x, p);
		return;
	}
	if (getcolor(W->getdirect()) == false) {
		W->getdirect()->setblack(true);
		W->rotate();
		return;
	}
	if (W->getparent()->getright() == W) {
		Z = W->getleft();
	}
	else {
		Z = W->getright();
	}
	Z->rotate();
	Z->rotate();
	W->setblack(true);
	return;
}
