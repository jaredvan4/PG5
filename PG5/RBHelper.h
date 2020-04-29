//Jared VanEnkevort
//contains the function prototypes for the definiotions present in RBHelper.cpp
#ifndef _RBHELPER_
#define _RBHELPER_

#include <iostream>
#include <string>
#include <cstdlib>
#include "RBTreeNode.h"
using namespace std;

bool getcolor(RBTreeNode* n);
RBTreeNode* getsibling(RBTreeNode* n, RBTreeNode* p);
void DelProcess(RBTreeNode* x, RBTreeNode* p);

#endif