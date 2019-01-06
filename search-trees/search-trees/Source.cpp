#include "SplayTree.h"
#include "AVL_Tree.h"
#include <time.h>
#include <iostream>
#include <set>
#include <chrono>
#include <vector>
#include <map>
const int temp = 500;
const int ins = 1000 * 5 * 5 * 5 * 5 * 5;
//const int ins = 100000;
using namespace std;

void main() {
	srand(100);
	/*Node_splay* n = new Node_splay(-1);
	SplayTree* sp = new SplayTree(n);
	set<int> set;
	map<int, int> map;
	int *test = new int[ins];
	int *test_t = new int[temp];
	vector<int> v(ins + temp);
	AVL_tree tr;
	vector<pair<int, int>> revenue(ins);
	vector<pair<int, int>> revenue_t(temp);
	/*cout << "AVL" << endl << endl;

	for (int i = 0; i < temp; i++)
	{
		test_t[i] = 31 + rand() << 15 + rand();
	}

	for (int i = 0; i < ins; i++)
	{
		test[i] = 31 + rand() << 15 + rand();
	}
	for (int i = 0; i < temp; i++)
	{
		revenue_t[i] = { 31 + rand() << 15 + rand(), 31 + rand() << 15 + rand() };
	}
	for (int i = 0; i < ins; i++)
	{

		revenue[i] = { 31 + rand() << 15 + rand(), 31 + rand() << 15 + rand() };
	}


	for (int i = 0; i < ins; i++)
	{
		tr.add(test[i]);
	}
	for (int i = 0; i < ins; i++)
	{
		sp->Insert(test[i]);
	}
	for (int i = 0; i < ins; i++)
	{
		map.insert(revenue[i]);
	}

	cout << "AVL" << endl << endl;
	auto begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		tr.add(test_t[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	//cout << "time add = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

	cout << "splay" << endl << endl;
	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		sp->Insert(test_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	//cout << "time add = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

	cout << "map" << endl << endl;
	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		map.insert(revenue_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	//cout << "time add = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

	int t = 0;
	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		t = tr.find(test_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	if (t == 0)
	{
		cout << endl;
	}

	begin = chrono::high_resolution_clock::now();
	t = 0;
	for (int i = 0; i < temp; i++)
	{
		t = sp->Find(test_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	if (t == 0)
	{
		cout << endl;
	}


	begin = chrono::high_resolution_clock::now();
	t = 0;
	for (int i = 0; i < temp; i++)
	{
		map.find(revenue_t[i].first);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;


	/*begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		tr.del(test_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		sp->Remove(test_t[i]);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

	begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		map.erase(revenue_t[i].first);
	}
	end = chrono::high_resolution_clock::now();
	cout << "time del = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	*/
	vector<int> test(temp);
	vector<int> mas(ins);

	for (int i = 0; i < temp; i++)
	{
		test[i] = 31 + rand() << 15 + rand();
	}
	for (int i = 0; i < ins; i++)
	{
		mas[i] = 31 + rand() << 15 + rand();
	}
	std::sort(mas.begin(), mas.end());
	int t = 0;
	auto begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < temp; i++)
	{
		t = std::binary_search(mas.begin(), mas.end(), test[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "time find = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	if (t == 0)
	{
		cout << endl;
	}
	system("pause");

	return;
}