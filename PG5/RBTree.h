#ifndef _RBTREE_
#define _RBTREE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "RBTreeNode.h"
#include "DRT.h"
#include "Database.h"
using namespace std;

class DRT;
class RBTreeNode;
class Database;
class RBTree : public Database {
private:
	RBTreeNode* root;
public:
	RBTree(); //constructor
	~RBTree(); //destructor
	DRT* add(string key, string data); //very similar to sample code
	void setroot(RBTreeNode* r); //get method
	DRT* searchnode(string key); //searches the RBTree for the given key
	string first(); //first key in the RBTree (left all the way down)
	string last(); //last key in the RBTree (right all the way down)
	DRT* remove(string key); //removes an item from the list
	DRT* search(string key); //Database search method
	  //checks to see if we're searching on the empty string, if so builds a DRT with first() and last (), otherwise calls searchnode
	DRT* modify(string key, string data); //Database modify method
	int Valid();
};

#endif