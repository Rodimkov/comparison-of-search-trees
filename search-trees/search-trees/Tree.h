#pragma once
#include "Node.h"
class Tree {
public:
	virtual Node_splay* Find(int key) = 0;
	virtual void Insert(int key) = 0;
	virtual void Remove(int key) = 0;
};