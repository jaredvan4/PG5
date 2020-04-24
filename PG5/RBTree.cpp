#include "RBTree.h"

RBTree::RBTree()
{
	root = nullptr;
}

RBTree::~RBTree()
{
	delete root;
}

void RBTree::setroot(RBTreeNode* r)
{
	root = r;
}

string RBTree::first()
{
	if (!root) {
		return "";
	}
	else {
		return root->first()->getk();
	}
}

string RBTree::last()
{
	if (!root) {
		return "";
	}
	else {
		return root->last()->getk();
	}
}
