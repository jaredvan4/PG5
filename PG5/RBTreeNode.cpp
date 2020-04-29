#include "RBTreeNode.h"
#include "DRT.h"
#include "RBHelper.h"
RBTreeNode::RBTreeNode(string key, string data, RBTreeNode* l, RBTreeNode* r, RBTreeNode* p, RBTree* T) {
	k = key; d = data; left = l; right = r; parent = p; t = T;
	setblack(false);
}
RBTreeNode::~RBTreeNode() {
	delete left;
	delete right;
}
DRT* RBTreeNode::add(string key, string data, string n, string p) {
	//call AddProcess() somewhere?
	if (k == key) {
		DRT* temp = new DRT(d, n, p);
		d = data;
		string next;
		string prev;
		if (!right)
			next = n;
		else next = right->first()->getk();
		if (!left)
			prev = p;
		else prev = left->last()->getk();
		return temp;
	}
	if (k < key) {
		if (right) {
			return right->add(key, data, n, k);
		}
		else {
			right = new RBTreeNode(key, data, NULL, NULL, this, t);
			//color red
			right->setblack(false);
			right->AddProcess();
			if (t->Valid()){
				cout << "Tree is valid!\n";
			}
			else {
				cout << "Tree isn't valid!!!\n";
				exit(0);
			}
			if (ValidNode()) {
				cout << "Valid node!\n";
			}
			else {
				cout << "invalid node !!!\n";
				exit(0);
			}

			return new DRT("", n, k);
		}

	}
	if (left) {
		return left->add(key, data, k, p);
	}
	else {
		left = new RBTreeNode(key, data, NULL, NULL, this, t);
		//color red
		left->setblack(false);
		left->AddProcess();
		if (t->Valid()) {
			cout << "Tree is valid!\n";
		}
		else {
			cout << "Tree isn't valid!!!\n";
			exit(0);
		}
		if (ValidNode()) {
			cout << "Valid node!\n";
		}
		else {
			cout << "invalid node !!!\n";
			exit(0);
		}
		return new DRT("", k, p);
	}
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
		DelProcess(NULL, parent);
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
		left = nullptr;
		right = nullptr;
	if (getcolor(this) == false) {
		DelProcess(nullptr, parent);
		delete this;
		return;
	}
	else {
		
		delete this;
		return;
	}
	return;
	
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
		RBTreeNode* temp;
		if (parent->getleft() == this) {
			//set my single child as left node of my parent
			if (left) {
				temp = left;
				left->setparent(parent);
				parent->setleft(left);

			}
			else {
				temp = right;
				right->setparent(parent);
				parent->setleft(right);
			}
				left = nullptr;
				right = nullptr;
			if (getcolor(this) == false) {
				DelProcess(temp, parent);
				delete this;
				return;
			}
			else {
				
				delete this;
				return;
			}
		}
		else {
			//if  node to be delted is right child
			if (left) {
				temp = left;
				left->setparent(parent);
				parent->setright(left);

			}
			else {
				temp = right;
				right->setparent(parent);
				parent->setright(right);
			}
			if (getcolor(this) == false) {
				DelProcess(temp, parent);
				delete this;
				return;
			}
			else {

				delete this;
				return;
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
	return black;
}

void RBTreeNode::setblack(bool b) {
	black = b;
}

RBTreeNode* RBTreeNode::getdirect() {
	if (parent->getright() == this) {
		return right;
	}
	else {
		return left;
	}
}

bool RBTreeNode::isdirect() {
	//if I'm  a left child
	if (this == parent->getleft()) {
		if (parent == parent->getparent()->getleft()) {
			return true;
		}
		else {
			return false;
		}

	}
	else {
		//I'm right child
		if (parent == parent->getparent()->getright()) {
			return true;
		}
		else {
			return false;
		}

	}

}
//NOT DONE
void RBTreeNode::rotate() {
	bool temp = black;
	black = getcolor(parent);
	parent->setblack(temp);
	RBTreeNode* GP = parent->getparent();
	RBTreeNode* Z;
	if (parent->getright() == this) {
		Z = left;
	}
	else {
		Z = right;
	}
	//x's parent needs to point to GP?
	parent = GP;

	// if no grandparent
	if (!GP) {
		//root needs to point to this
		t->setroot(this);
	}
	else {
		//if parent is a right child gp's right needs to point to this
		if (GP->getright() == parent) {
			parent->getparent()->setright(this);
		}
		//if parent is a left child of GP, GP's left needs to point to this? 
		if (GP->getleft() == parent) {
			parent->getparent()->setleft(this);
		}
	}
	//#3
	parent->setparent(this);
	//if im a left child of P 
	if (parent->getleft() == this) {
		//my right needs to point to p
		right = parent;
		parent->setleft(Z);
	}
	//If I'm a right child of P
	if (parent->getright() == this) {
		left = parent;
		parent->setright(Z);
	}
	if (Z) {
		Z->setparent(parent);
	}
}
void RBTreeNode::AddProcess() {
	//applies rules 3-7
	//if I'm root
	if (parent == nullptr) {
		black = true;
		return;
	}
	//if parent is black
	if (getcolor(parent) == true) {
		return;
	}
	//if uncle is red
	if (getcolor(getSibling(parent, parent->getparent())) == false) {
		//color my parent and uncle black
		parent->setblack(true);
		getSibling(parent, parent->getparent())->setblack(true);
		//set my grandparent to be red
		parent->getparent()->setblack(false);
		parent->getparent()->AddProcess();
		return;
	}
	if (this->isdirect()) {
		//if x is a direct grandchild?
		parent->rotate();
		return;
	}

	rotate();
	rotate();
	return;

}

RBTreeNode* RBTreeNode::getSibling(RBTreeNode* n, RBTreeNode* p) {
	//returns the child of p that isn't n
	if (p->getleft() == n) {
		return p->getright();
	}
	else {
		return p->getleft();
	}
}
int RBTreeNode::ValidNode() {
	int lc, rc, r;

	if (!black && parent && !parent->isblack()) {
		r = -1;
	}
	else {
		if (left && left->getparent() != this) {
			r = -1;
		}
		else {
			if (left && left->getk() >= k) {
				r = -1;
			}
			else {
				if (right && right->getparent() != this) {
					r = -1;
				}
				else {
					if (right && right->getk() <= k) {
						r = -1;
					}
					else {
						if (left) {
							lc = left->ValidNode();
						}
						else {
							lc = 0;
						}
						if (lc == -1) {
							r = -1;
						}
						else {
							if (right) {
								rc = right->ValidNode();
							}
							else {
								rc = 0;
							}
							if (rc == -1) {
								r = -1;
							}
							else {
								if (lc != rc) {
									r = -1;
								}
								else {
									if (black) {
										r = lc + 1;
									}
									else {
										r = lc;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return r;
}