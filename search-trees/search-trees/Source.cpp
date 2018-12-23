#include "SplayTree.h"
#include "AVL_Tree.h"
#include <time.h>
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#define SIZE 1000000
const int good = 100;
using namespace std;

void main() {
	srand(100);
	Node_splay* n = new Node_splay(0);
	SplayTree* sp = new SplayTree(n);
	AVL_tree tr;
	//auto begin, end;
	int *test = new int[SIZE];
	int *test_t = new int[good];

	for (int i = 0; i < SIZE; i++)
	{
		test[i] =  rand();
	}

	for (int i = 0; i < good; i++)
	{
		test_t[i] = test[rand() % SIZE];
		//cout << test_t[i] << endl;
	}
	auto begin = chrono::high_resolution_clock::now();

	for (int i = 0; i < SIZE; i++)
	{
		tr.add(test[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "time add = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;
	int k = 0;
	begin = chrono::high_resolution_clock::now();
	/*for (int i = 0; i < SIZE; i++)
	{
		tr.find(test_t[i%good]);
	}*/
	for (int i = 0; i < SIZE; i++)
	{
		tr.find(test_t[i%good]);
		tr.find(test_t[i%good]);
		tr.find(test_t[i%good]);
		tr.find(test_t[i%good]);
		tr.find(test_t[i%good]);


		//tr.find(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		tr.del(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	system("pause");

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		sp->Insert(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time add = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	/*for (int i = 0; i < SIZE; i++)
	{
		sp->Find(test_t[i%good]);
	}*/
	for (int i = 0; i < SIZE; i++)
	{
		sp->Find(test_t[i%good]);
		sp->Find(test_t[i%good]);
		sp->Find(test_t[i%good]);
		sp->Find(test_t[i%good]);
		sp->Find(test_t[i%good]);


		//sp->Find(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		sp->Remove(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;
	//-------------------------------------------------------------------------------------------------//
	cout << endl << endl;
	system("pause");

	/*begin = chrono::high_resolution_clock::now();

	for (int i = 0; i < SIZE; i++)
	{
		tr.add(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time add = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		tr.find(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;


	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		tr.del(test[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;

	system("pause");
	cout << endl << endl;
	system("pause");

	for (int i = 0; i < SIZE; i++)
	{
		sp->Insert(test[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		tr.add(test[i]);
	}

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		sp->Find(test[150]);
		sp->Find(test[160]);

	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;


	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++)
	{
		tr.find(test[150]);
		tr.find(test[160]);

	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;*/
	system("pause");

	return;
}