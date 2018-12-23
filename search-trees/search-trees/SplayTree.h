#pragma once
#include "Tree.h"
#include  <stack>
#include <iostream>

using namespace std;

class SplayTree : Tree {
	Node_splay* root;
	std::stack<Node_splay*> stack;
public:
	SplayTree(Node_splay* node) : root(node) {
	};
	Node_splay* getRoot() {
		return root;
	}
	/***********************************************************/
	virtual int Find(int key);
	virtual void Insert(int key);
	virtual void Remove(int key);
	Node_splay* find_node(Node_splay* node, int key);
	void Splay(Node_splay* u);
	SplayTree Split(int k);
	void Merge(SplayTree u);
	int RoundTree();
	/***********************************************************/
private:
	void Zig(Node_splay* u);
	void ZigZig(Node_splay* u);
	void ZigZag(Node_splay* u);
	void Zag(Node_splay* u);
	void ZagZag(Node_splay* u);
	void ZagZig(Node_splay* u);
};