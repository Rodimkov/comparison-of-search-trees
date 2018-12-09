#pragma once
#include "Tree.h"
class SplayTree: Tree {
	Node_splay* root;
public:
	SplayTree(Node_splay* node): root(node) {
	};
	Node_splay* getRoot() {
		return root;
	}
	/***********************************************************/
	virtual  Node_splay* Find(int key);
	virtual void Insert(int key);
	virtual void Remove(int key);
	void Splay(Node_splay* u);
	SplayTree Split(int k);
	void Merge(SplayTree u);
	/***********************************************************/
private:
	void Zig(Node_splay* u);
	void ZigZig(Node_splay* u);
	void ZigZag(Node_splay* u);
	void Zag(Node_splay* u);
	void ZagZag(Node_splay* u);
	void ZagZig(Node_splay* u);
};