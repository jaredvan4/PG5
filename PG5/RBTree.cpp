//Jared VanEnkevort
//contains all the function definitions for the prototypes present in RBtree.h
#include "RBTree.h"
#include "DRT.h"
#include "RBTreeNode.h"
//constructor
RBTree::RBTree() {
	root = nullptr;
}
//decontructor
RBTree::~RBTree() {
	delete root;
}
//adds a node to the tree
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
//sets the root
void RBTree::setroot(RBTreeNode* r) {
	root = r;
}
//searches for node with the given key
DRT* RBTree::searchnode(string key) {
	if (root) {
		return root->searchnode(key, "", "");
	}
	else {
		return new DRT("", "", "");
	}
}
//returns first node in tree
string RBTree::first() {
	if (!root) {
		return "";
	}
	else {
		return root->first()->getk();
	}
}
//returns last node in tree
string RBTree::last() {
	if (!root) {
		return "";
	}
	else {
		return root->last()->getk();
	}
}
//removes a node from the tree
DRT* RBTree::remove(string key) {
	if (!root) {
		return new DRT("", "", "");
	}
	return root->remove(key, "", "");
}
//searches for a node in the tree
DRT* RBTree::search(string key) {
	if (key.empty()) {
		return new DRT(key, first(), last());
	}
	else {
		return searchnode(key);
	}

}
//modifies a node matching the key with the given data
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

