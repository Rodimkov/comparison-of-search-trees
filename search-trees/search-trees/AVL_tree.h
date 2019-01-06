#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;

struct Node
{
	int key;
	Node *right;
	Node *left;
	int height;

	Node(int key) : key(key), left(NULL), right(NULL), height(1) {}; // единица?)
};

class AVL_tree
{
private:
	Node *root;

	Node* insert_node(Node *n, int key);
	Node* search(Node* n, int key);
	Node * turn_left(Node * n);
	Node * turn_right(Node * n);
	Node * rebalance(Node * n);
	Node * remove_min(Node * n, Node * iter);
	Node * remove(Node * n, int key);
	void tree_delete(Node* n);
	int height(const Node* n)
	{
		if (n != NULL)
			return n->height;
		else
			0;
		/*return n ? n->height : 0; */
	}
	int balance(const Node* n)
	{
		if (n != NULL && n->left != NULL && n->right != NULL)
			return height(n->right) - height(n->left);
		else return 0;
	}
	void reheight(Node* n)
	{
		if (n != NULL && n->left != NULL && n->right != NULL)

		{
			int k = height(n->left);
			if (k  < height(n->right))
				k = height(n->right);
			k++;
			n->height = k;
			//n->height = std::max(height(n->left), height(n->right)) + 1;
		}
	}
public:
	AVL_tree();
	~AVL_tree();

	//---------------------------------------------------------------------
	int find(int key)
	{
		//auto begin = chrono::high_resolution_clock::now();
		Node* n = nullptr;
		n = search(root, key);
		//auto end = chrono::high_resolution_clock::now();
		//cout << "     time find = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << endl;
		if (n->key == key)
			return n->key;
		else
			return NULL;
	}
	void add(int key)
	{
		if (search(root, key))
		{
			//cout << "repeat" << endl;
			return;
		}
		root = insert_node(root, key);
	}

	void del(int key) { root = remove(root, key); }
};

