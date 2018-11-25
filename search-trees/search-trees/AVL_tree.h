#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int key;
	int value;
	Node *right;
	Node *left;
	int height;

	Node(int key, int val) : key(key), value(val), left(NULL), right(NULL), height(1) {};
};

class AVL_tree
{
private:
	Node *root;
	Node* insert_node(Node *n, int key, int value);
	Node* search(Node* n, int key);
	Node * turn_left(Node * n);
	Node * turn_right(Node * n);
	Node * rebalance(Node * n);
	Node * remove_min(Node * n, Node * iter);
	Node * remove(Node * n, int key);
	void tree_delete(Node* n);
	int height(const Node* n) { return n ? n->height : 0; }
	int balance(const Node* n) { return height(n->right) - height(n->left); }
	void reheight(Node* n) { n->height = std::max(height(n->left), height(n->right)) + 1; }
public:
	AVL_tree();
	~AVL_tree();

	//---------------------------------------------------------------------
	int find(int key)
	{
		Node* n = search(root, key);
		if (n)
			return n->value;
		else
			return 0;
	}
	void add(int key, int value) 
	{ 
		if (search(root, key))
		{
			cout << "repeat" << endl;
			return;
		}
		root = insert_node(root, key, value);
	}

	void del(int key) { root = remove(root, key); }
};

