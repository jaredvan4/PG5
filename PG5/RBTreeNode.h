#ifndef _RBTREENODE_
#define _RBTREENODE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "RBTree.h"
#include "DRT.h"
using namespace std;

class DRT;
class RBTree;
class RBTreeNode {
private:
	string k; string d;
	RBTreeNode* left, * right, * parent;
	bool black;
	RBTree* t;
public:
	RBTreeNode(string key, string data, RBTreeNode* l, RBTreeNode* r, RBTreeNode* p, RBTree* T); //constructor
	~RBTreeNode(); //destructor
	DRT* add(string key, string data, string n, string p);
	//similar to search; keeps nsf and psf
	DRT* searchnode(string key, string n, string p);
	//utilizes keeping track of next-so-far and prev-so-far
	RBTreeNode* first(); //left all the down
	RBTreeNode* last(); //right all the way down
	string getk(); //get
	string getd(); //get
	RBTreeNode* getright(); //get
	RBTreeNode* getleft(); //get
	string next(); //right once, left all the way down (makes use of first ())
	string prev(); //left once, right all the way down (makes use of last ())
	DRT* remove(string key, string n, string p);
	void removeRoot();
	//similar to search; keeps track of nsf and psf
	//just works its down to the RBTree to find the node to remove
	//then calls remove ()
	void remove(); //the physical removal (decides whether it's 0, 1, or 2-child case and possibly copies key and data values and physically removes the deleted node
	void setparent(RBTreeNode* p); //set
	void setleft(RBTreeNode* l); //set
	void setright(RBTreeNode* r); //set
	RBTreeNode* getparent();
	bool isblack();
	void setblack(bool b);
	RBTreeNode* getdirect();
	bool isdirect();
	void rotate();
	void AddProcess();
	int ValidNode();
};

#endif