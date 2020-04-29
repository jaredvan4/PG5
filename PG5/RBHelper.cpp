//Jared VanEnkevort
//contains all the function definitions for the prototypes present in RBHelper.h
#include "RBHelper.h"

bool getcolor(RBTreeNode* n) {
	if (!n) {
		return true;
	}
	return n->isblack();
}
//gets child of p that isn't n 
RBTreeNode* getsibling(RBTreeNode* n, RBTreeNode* p) {
	if (p->getleft() == n) {
		return p->getright();
	}
	else {
		return p->getleft();
	}
}
//handle del rules 4 -10
//x is child of node being deleted, p is parent of node being deleted
void DelProcess(RBTreeNode* x, RBTreeNode* p) {
	RBTreeNode* Z;
	if (getcolor(x) == false) {
		/*cout << "IN RULE 4 OF DEL\n";*/
		x->setblack(true);
		return;
	}
	if (!p) {
		/*cout << "IN RULE 5 OF DEL\n";*/
		return;
	}
	/*cout << "IN RULE 6 OF DEL\n";*/
	RBTreeNode* W = getsibling(x, p);
	if (getcolor(W) == false) {
		/*cout << "IN RULE 7 OF DEL\n";*/
		W->rotate();
		DelProcess(x,p);
		return;
	}
	if (getcolor(W->getleft()) == true && getcolor(W->getright()) == true) {
		/*cout << "IN RULE 8 OF DEL\n";*/
		W->setblack(false);
		x = p;
		p = p->getparent();
		DelProcess(x, p);
		return;
	}
	if (getcolor(W->getdirect()) == false) {
		/*cout << "IN RULE 9 OF DEL\n";*/
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
	/*cout << "IN RULE 10 OF DEL\n";*/
	Z->rotate();
	Z->rotate();
	W->setblack(true);
	return;
}
