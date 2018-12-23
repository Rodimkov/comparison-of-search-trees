#include "treap.h"



treap::treap()
{
	root = NULL;
}


treap::~treap()
{
}

TreapNode* treap::merge(TreapNode* t1, TreapNode* t2)
{
	if (t1 == nullptr) { return t2; }
	if (t2 == nullptr) { return t1; }
	if (t1->y > t2->y)
	{
		t1->r = merge(t1->r, t2);
		return t1;
	}
	else
	{
		t2->l = merge(t1, t2->l);
		return t2;
	}
}


pair<TreapNode*,TreapNode*> treap::split(TreapNode* t, int x)
{
	if (t == nullptr)
	{
		TreapNode* t1 = nullptr;
		TreapNode* t2 = nullptr;
		pair<TreapNode*, TreapNode*> tmp = { t1,t2 };
		return{ nullptr,nullptr };
	}
	if (x > t->x)
	{
		pair <TreapNode*, TreapNode*> tmp = split(t->r, x);
		t->r = tmp.first;
		return{ t,tmp.second };
	}
	else
	{
		pair <TreapNode*, TreapNode*> tmp = split(t->r, x);
		t->l = tmp.second;
		return{ t,tmp.first };
	}

}

void treap::insert(int x)
{
	pair<TreapNode*, TreapNode*> q = split(root, x);
	TreapNode* t = new TreapNode(x);
	root = merge(q.first, merge(t, q.second));
}

void treap::remove(int key) {
	TreapNode *t1, *t2, *t3;
	pair<TreapNode*, TreapNode*> q = split(root, key);
	pair<TreapNode*, TreapNode*> q1 = split(q.second, key + 1);
	root = merge(q.first, q1.first);
}

/*void treap::add(TreapNode* t, TreapNode* tmp)
{
	if (!t)
		t = tmp;
	else if (tmp->y > t->y)
	{
		split(t, t->x);
		t = tmp;
	}
	else
		add(tmp->x < t->x ? t->l : t->r, tmp);
}*/

// --- ��������, ���������� � �������

// ���������� ������ �������� x � ������ t. ������ ������ ����� ����������!
/*void add(Node *&t, int x)
{
	Node *t1, *t2;
	// ��� ���������� ������ ���������:
	// - ��������� �������� ������ �� ����� x. � ����� ��������� ��� �������� ������ x,
	//   � ������ - �� ������.
	split(t, x, t1, t2);
	// - ������ ����� ������ �� ����� ������� - ����������, x.
	Node* new_tree = new Node(x);
	// - ���������� ������� ������ ��������� � �����, ����� ������� ���������� � ������
	//   ��������� ������� - ����� ������ ������.
	t = merge(merge(t1, new_tree), t2);
}
*/
// �������� ������� �� ������. � ������ ������ �������� ����� ������ � ������ �������!
/*void remove(Node *&t, int x)
{
	Node *t1, *t2, *t3, *t4;
	// ��� �������� ������ ���������:
	// - ��������� �������� ������ �� ����� x.
	split(t, x, t1, t2);
	// - ��������� ������ ��������� �� ����� x + 1 (��� ����� ����� ���� ����� �����!)
	split(t2, x + 1, t3, t4);
	// - ��������� ������� t1 � t4, ������� ������ �� �������� ����� x
	//   (�� ������� � ������ t3)
	t = merge(t1, t4);
	// - ������� ������, ���������� ������� t3 (���� �� ����� ������)
	delete t3;
}*/