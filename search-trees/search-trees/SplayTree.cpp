#include "SplayTree.h"

//Left
//            y
//           / \
//          /    o
//         x
//       /   \
//      o     o
//
void SplayTree::Zig(Node_splay* u) {
	Node_splay* parent = u->parent;
	Node_splay* grandparent = parent->parent;

	if (grandparent != nullptr)
	{
		if (grandparent->left_child == parent) {
			grandparent->left_child = u;
		}
		else {
			grandparent->right_child = u;
		}
	}

	u->parent = grandparent;

	parent->left_child = u->right_child;
	if (u->right_child != nullptr)
		u->right_child->parent = parent;// забавно
	parent->parent = u;

	u->right_child = parent;
}
//LeftLeft
void SplayTree::ZigZig(Node_splay* u) {
	Zig(u->parent);
	Zig(u);
}
//LeftRight
void SplayTree::ZigZag(Node_splay* u) {
	Zag(u);
	Zig(u);

}
//Right
//      y
//    /  \
//   o    \
//         x
//        /  \
//       /    \
//      o      o
//
void SplayTree::Zag(Node_splay* u) {
	Node_splay* parent = u->parent;
	Node_splay* grandparent = parent->parent;

	if (grandparent != nullptr)
	{
		if (grandparent->left_child == parent) {
			grandparent->left_child = u;
		}
		else {
			grandparent->right_child = u;
		}
	}

	u->parent = grandparent;

	parent->right_child = u->left_child;
	if (u->left_child != nullptr)
		u->left_child->parent = parent; //забавно

	parent->parent = u;

	u->left_child = parent;
}
//RightRight
void SplayTree::ZagZag(Node_splay* u) {

	Zag(u->parent);
	Zag(u);
}
//RightLeft
void SplayTree::ZagZig(Node_splay* u) {
	Zig(u);
	Zag(u);
}



void SplayTree::Splay(Node_splay* u) {
	Node_splay* parent = nullptr;
	Node_splay* grandparent = nullptr;
	if (u->parent == nullptr) {
		root = u;
		return;
	}
	parent = u->parent;
	grandparent = parent->parent;

	if (grandparent == nullptr) {
		if (parent->right_child == u) {
			Zag(u);
		}
		else {
			Zig(u);
		}
	}
	else {
		if (grandparent->right_child == parent) {
			if (parent->right_child== u) {
				ZagZag(u);
			}
			else {
				ZagZig(u);
			}

		}
		else {
			if (parent->right_child == u) {
				ZigZag(u);
			}
			else {
				ZigZig(u);
			}
		}
	}
	Splay(u);
}

Node_splay* SplayTree::find_node(Node_splay* node, int key) {
	if (node == nullptr) {
		return node;
	}

	if (node->key == key) {
		return node;
	}
	Node_splay* res = nullptr;
	if (node->key > key) {
		if (node->left_child == nullptr)
			return node;
		if ((node->left_child)->key > key) {
			res = find_node(node->left_child->left_child, key);
		}
		else {
			if ((node->left_child)->key < key) {
				res = find_node(node->left_child->right_child, key);
			}
		}
		return (res == nullptr) ? node->left_child : res;

	}
	else {
		if (node->right_child == nullptr)
			return node;
		if ((node->right_child)->key > key) {
			res = find_node(node->right_child->left_child, key);
		}
		else {
			if ((node->right_child)->key < key) {
				res = find_node(node->right_child->right_child, key);
			}
		}
		return (res == nullptr) ? node->right_child : res;
	}

	/*if (node == nullptr)
		return node;

	if (node->key == key)
		return node;

	else if (node->key < key)
	{
		if (node->right_child == nullptr)
			return node;

		node = find_node(node->right_child, key);
	}
	else if ((node->key > key))
	{
		if (node->left_child == nullptr)
			return node;

		node = find_node(node->left_child, key);
	}*/
}

int SplayTree::Find(int key) {
	Node_splay* res = find_node(root, key);
	Splay(res);
	return res->key;
}

SplayTree SplayTree::Split(int k) {
	Node_splay* res = find_node(root,k);
	Node_splay* right = res->right_child;
	if (right != nullptr)
		right->parent = nullptr;

	root->right_child = nullptr;
	return SplayTree(right);
}

void SplayTree::Merge(SplayTree u) {
	Node_splay* curr = root;
	while (curr->right_child != nullptr) {
		curr = curr->right_child;
	}
	Splay(curr);
	(root)->setRight(u.getRoot());
	if (u.getRoot() != nullptr)
		u.getRoot()->setParent(getRoot());
}

void SplayTree::Remove(int k) {
	if (root == nullptr) {
		return;
	}
	Node_splay* curr = find_node(root, k);
	if (curr->key != k) {
		return;
	}
	Splay(curr);
	Node_splay* left = nullptr;
	Node_splay* right = nullptr;
	left = curr->left_child;
	right = curr->right_child;

	if (curr->existLeft() && curr->existRight()) {
		left->parent = nullptr;
		if (right != nullptr)
			right->parent =  nullptr;
		root = left;
		Merge(SplayTree(right));
	}
	else {
		if (curr->existLeft() && !curr->existRight()) {
			root = left;
		}
		else {

			if (!curr->existLeft() && curr->existRight()) {
				root = right;
			}
			else {

				root = nullptr;
			}
		}
	}
	delete curr;
	if (root != nullptr)
		root->parent = nullptr;
}
void SplayTree::Insert(int key) {
	Node_splay* curr = find_node(root, key);
	Node_splay* node = new Node_splay(key);
	if (curr->key == key) {
		return;
	}

	if (key > curr->key) {
		Node_splay* right = curr->right_child;
		node->parent = curr;
		curr->right_child = node;
		node->right_child = right;
		if (right != nullptr)
		{
			right->parent = node;
		}
	}
	else {
		Node_splay* left = curr->left_child;
		node->parent = curr;
		curr->left_child = node;
		node->left_child = left;
		if (left != nullptr)
		{
			left->parent = node;
		}
	}
	Splay(node);


	/*SplayTree res = Split(key);

	if (root->getKey() != key) {
	Node_splay* node = new Node_splay(key);
	node->setParent(nullptr);
	node->setLeft(root);
	root->setParent(node);
	root = node;
	}
	root->setRight(res.getRoot());
	if (res.getRoot() != nullptr)
	res.getRoot()->setParent(root);*/

}

int SplayTree::RoundTree() {
	if (root == nullptr) {
		return 0;
	}
	stack.push(root);
	int res = 0;
	while (!stack.empty()) {
		Node_splay* curr = stack.top();
		stack.pop();
		res++;
		if (curr->getRight() != nullptr) {
			stack.push(curr->getRight());
		}
		if (curr->getLeft() != nullptr) {
			stack.push(curr->getLeft());
		}
	}
	return res;

}