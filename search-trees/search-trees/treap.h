#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

struct TreapNode
{
	int x, y;
	TreapNode *l, *r;
	TreapNode(int tmp) : x(tmp), y(rand()), l(NULL), r(NULL) {};
};

class treap
{
private:
	TreapNode* root;
public:
	treap();
	~treap();

	TreapNode* merge(TreapNode* left, TreapNode* right);

	pair<TreapNode*, TreapNode*> split(TreapNode * t, int x);

	void insert(int x);

	void remove(int key);

	//void add(TreapNode * t, TreapNode * tmp);

	//TreapNode *rightRotate(TreapNode *y);
	//TreapNode *leftRotate(TreapNode *x);

	/*TreapNode* newNode(int key);

	TreapNode* search(TreapNode* root, int key);
	TreapNode* insert(TreapNode* root, int key);

	TreapNode* deleteNode(TreapNode* root, int key);
	void inorder(TreapNode* root);*/

	//CTree() {};
};


