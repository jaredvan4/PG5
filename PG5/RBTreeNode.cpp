#include "RBTreeNode.h"
#include "DRT.h"
RBTreeNode::RBTreeNode(string key, string data, RBTreeNode* l, RBTreeNode* r, RBTreeNode* p, RBTree* T)
{
	k = key; d = data; left = l; right = r; parent = p; t = T;
}
RBTreeNode::~RBTreeNode()
{
	delete left;
	delete right;
}
DRT* RBTreeNode::searchnode(string key, string n, string p)
{
	return nullptr;
}
//left all the way down 
RBTreeNode* RBTreeNode::first(){
	if (left) {
		return left->first();
	}
	else {
		return this;
	}
}
//right all the way down
RBTreeNode* RBTreeNode::last(){
	if (right) {
		return right->last();
	}
	else {
		return this;
	}
}

string RBTreeNode::getk()
{
	return k;
}

string RBTreeNode::getd()
{
	return d;
}

RBTreeNode* RBTreeNode::getright()
{
	return right;
}

RBTreeNode* RBTreeNode::getleft()
{
	return left;
}

string RBTreeNode::next(){
	//right once, left all the way down
	if (right) {
		return right->first()->getk();
	}
	else {
		return this->getk();
	}
}

string RBTreeNode::prev(){
	//left once, right all the way down
	if (left) {
		return left->last()->getk();
	}
	else {
		return this->getk();
	}
}

void RBTreeNode::setparent(RBTreeNode* p)
{
	parent = p;
}

void RBTreeNode::setleft(RBTreeNode* l)
{
	left = l;
}

void RBTreeNode::setright(RBTreeNode* r)
{
	right = r;
}

RBTreeNode* RBTreeNode::getparent()
{
	return parent;
}
