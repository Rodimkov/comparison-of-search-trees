#include "AVL_tree.h"
#include "SplayTree.h"
#include <chrono>

void main()
{
	AVL_tree tr;
	int n = 200000;
	//------------------------------------------------------------------------------------------------

	auto begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		tr.add(i);
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "time add = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		tr.find(i);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		tr.del(i);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	system("pause");

	//-------------------------------------------------------------------------------------------------

	Node_splay* node = new Node_splay(1);
	SplayTree* sp = new SplayTree(node);

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		sp->Insert(i);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time add = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;
	system("pause");

	begin = chrono::high_resolution_clock::now();
	for (int i = 3; i < n; i++)
	{
		sp->Find(i);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		sp->Remove(i);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	system("pause");
	return;
}