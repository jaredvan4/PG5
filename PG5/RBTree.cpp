//Jared VanEnkevort
//contains all the function definitions for the prototypes present in RBtree.h
#include "RBTree.h"
#include "DRT.h"
#include "RBTreeNode.h"

RBTree::RBTree() {
	root = nullptr;
}

RBTree::~RBTree() {
	delete root;
}

DRT* RBTree::add(string key, string data) {
	if (!root) {
		root = new RBTreeNode(key, data, NULL, NULL, NULL, this);
		root->AddProcess();
		return new DRT("", "", "");
	}
	else {
		return root->add(key, data, "", "");
	}
}

void RBTree::setroot(RBTreeNode* r) {
	root = r;
}

DRT* RBTree::searchnode(string key) {
	if (root) {
		return root->searchnode(key, "", "");
	}
	else {
		return new DRT("", "", "");
	}
}

string RBTree::first() {
	if (!root) {
		return "";
	}
	else {
		return root->first()->getk();
	}
}

string RBTree::last() {
	if (!root) {
		return "";
	}
	else {
		return root->last()->getk();
	}
}

DRT* RBTree::remove(string key) {
	if (!root) {
		return new DRT("", "", "");
	}
	return root->remove(key, "", "");
}

DRT* RBTree::search(string key) {
	if (key.empty()) {
		return new DRT(key, first(), last());
	}
	else {
		return searchnode(key);
	}

}

DRT* RBTree::modify(string key, string data) {
	if (key == "") return new DRT("", first(), last());
	if (data == "") return remove(key);
	return add(key, data);
}

int RBTree::Valid() {
	int r;
	if (!root) {
		r = 1;
	}
	else {
		if (!root->isblack()|| root->getparent()) {
			r = 0;
		}
		else {
			r = root->ValidNode() != -1;
		}
	}
	return r;
}

