#pragma once
class Node_splay {

public:
	Node_splay *parent;
	Node_splay *right_child;
	Node_splay *left_child;
	int key;
public:
	Node_splay(Node_splay* par, Node_splay* right, Node_splay* left, int nkey) {
		parent = par;
		right_child = right;
		left_child = left;
		key = nkey;
	}

	Node_splay(int nkey) {
		parent = nullptr;
		right_child = nullptr;
		left_child = nullptr;
		key = nkey;
	}

	Node_splay* getParent() {
		return parent;
	}
	Node_splay* getRight() {
		return right_child;
	}
	Node_splay* getLeft() {
		return left_child;
	}

	int getKey() {
		return key;
	}

	bool existRight() {
		if (getRight() != nullptr) {
			return true;
		}
		return false;
	}

	bool existLeft() {
		if (getLeft() != nullptr) {
			return true;
		}
		return false;
	}

	void setParent(Node_splay* node) {
		parent = node;
	}
	void setRight(Node_splay* node) {
		right_child = node;
	}
	void setLeft(Node_splay* node) {
		left_child = node;
	}

};