#include "RBTreeNode.h"
#include "DRT.h"
RBTreeNode::RBTreeNode(string key, string data, RBTreeNode* l, RBTreeNode* r, RBTreeNode* p, RBTree* T) {
	k = key; d = data; left = l; right = r; parent = p; t = T;
}
RBTreeNode::~RBTreeNode() {
	delete left;
	delete right;
}
DRT* RBTreeNode::searchnode(string key, string n, string p) {
	if (k == key) {
		string next, prev;
		if (!right) next = n;
		else next = right->first()->getk();
		if (!left) prev = p;
		else prev = left->last()->getk();
		return new DRT(d, next, prev);
	}
	if (k < key) {
		if (right) return right->searchnode(key, n, k); //k is now the psf
		return new DRT("", n, k);
	}
	if (left) return left->searchnode(key, k, p);
	return new DRT("", k, p);

}
//left all the way down 
RBTreeNode* RBTreeNode::first() {
	if (left) {
		return left->first();
	}
	else {
		return this;
	}
}
//right all the way down
RBTreeNode* RBTreeNode::last() {
	if (right) {
		return right->last();
	}
	else {
		return this;
	}
}

string RBTreeNode::getk() {
	return k;
}

string RBTreeNode::getd() {
	return d;
}

RBTreeNode* RBTreeNode::getright() {
	return right;
}

RBTreeNode* RBTreeNode::getleft() {
	return left;
}

string RBTreeNode::next() {
	//right once, left all the way down
	if (right) {
		return right->first()->getk();
	}
	else {
		return this->getk();
	}
}

string RBTreeNode::prev() {
	//left once, right all the way down
	if (left) {
		return left->last()->getk();
	}
	else {
		return this->getk();
	}
}

DRT* RBTreeNode::remove(string key, string n, string p) {
	if (this->k == key) {
		if (!parent) {
			//if root
			DRT* tempD = new DRT(this->getd(), n, p);
			this->removeRoot();
			return tempD;
		}
		DRT* tempD = new DRT(this->getd(), n, p);
		this->remove();
		return tempD;
	}
	else {
		if (k < key) {
			if (right) {
				return right->remove(key, n, k);
				//k is now the psf
			}
			else {
				return new DRT("", n, k);
			}
		}
		if (left) return left->remove(key, n, p);
		return new DRT("", k, p);
	}
	//NOT DONE !
	//similar to search; keeps track of nsf and psf
	 //just works its down to the tree to find the node to remove
	 //then calls remove ()
}
void RBTreeNode::removeRoot() {
	//the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node

	// 0 child case
	if (!left && !right) {
		t->setroot(nullptr);
	}
	//one child case
	else if (left != NULL && right == NULL || right != NULL && left == NULL) {
		if (left) {
			left->setparent(nullptr);
			t->setroot(left);
		}
		else {
			right->setparent(nullptr);
			t->setroot(right);
		}
	}
	//2 child case
	else if (left && right) {
		// go right once, then left all the way down to find next node
		//then copy all info from next node into "this" node (the one to be deleted)
		RBTreeNode* next = right->first();
		k = next->getk();
		d = next->getd();
		next->remove();
	}
}

void RBTreeNode::remove() {
	//the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node

	// 0 child case
	if (!left && !right) {
		if (parent->getleft() == this) {
			parent->setleft(nullptr);
		}
		else if (parent->getright() == this) {
			parent->setright(nullptr);
		}
		delete this;
	}
	//one child case
	else if (left != NULL && right == NULL || right != NULL && left == NULL) {
		//if node to be deleted is left child of parent
		if (parent->getleft() == this) {
			//set my single child as left node of my parent
			if (left) {
				left->setparent(parent);
				parent->setleft(left);

			}
			else {
				right->setparent(parent);
				parent->setleft(right);
			}
		}
		else {
			//if  node to be delted is right child
			if (left) {
				left->setparent(parent);
				parent->setright(left);

			}
			else {
				right->setparent(parent);
				parent->setright(right);
			}
		}
	}
	//2 child case
	else if (left && right) {
		// go right once, then left all the way down to find next node
		//then copy all info from next node into "this" node (the one to be deleted)
		RBTreeNode* next = right->first();
		k = next->getk();
		d = next->getd();
		/*left = next->getleft();
		right = next->getright();*/
		next->remove();
	}
}

void RBTreeNode::setparent(RBTreeNode* p) {
	parent = p;
}

void RBTreeNode::setleft(RBTreeNode* l) {
	left = l;
}

void RBTreeNode::setright(RBTreeNode* r) {
	right = r;
}

RBTreeNode* RBTreeNode::getparent() {
	return parent;
}

bool RBTreeNode::isblack() {
	return false;
}

void RBTreeNode::setblack(bool b) {
}

RBTreeNode* RBTreeNode::getdirect() {
	return nullptr;
}

bool RBTreeNode::isdirect() {
	return false;
}

void RBTreeNode::rotate() {
}

void RBTreeNode::AddProcess() {
}

int RBTreeNode::ValidNode() {
	return 0;
}
