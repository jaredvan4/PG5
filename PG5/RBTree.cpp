#include "RBTree.h"
#include "DRT.h"
#include "RBTreeNode.h"

RBTree::RBTree()
{
	root = nullptr;
}

RBTree::~RBTree()
{
	delete root;
}

DRT* RBTree::add(string key, string data)
{
	return nullptr;
}

void RBTree::setroot(RBTreeNode* r)
{
	root = r;
}

DRT* RBTree::searchnode(string key){
	if (root) {
		return root->searchnode(key, "", "");
	}
	else {
		return new DRT("", "", "");
	}
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

DRT* RBTree::remove(string key)
{
	return nullptr;
}

DRT* RBTree::search(string key){
	if (key.empty()) {
		return new DRT(key, first(), last());
	}
	else {
		return searchnode(key);
	}
	
}

DRT* RBTree::modify(string key, string data)
{
	return nullptr;
}

int RBTree::Valid()
{
	return 0;
}
