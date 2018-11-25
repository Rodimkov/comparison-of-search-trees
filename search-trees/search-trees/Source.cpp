#include "AVL_tree.h"
#include <time.h>

void main()
{
	AVL_tree tr;
	int n = 1000000,tmp;
	time_t start;
	start = time(NULL);
	for (int i = 0; i < n; i++)
	{
		tr.add(i, i);
	}
	cout << "time add = " << time(NULL) - start << endl;

	start = time(NULL);
	for (int i = 0; i < n; i++)
	{
		tmp = tr.find(i);
		if(tmp!=i)
			system("pause");
	}
	cout << "time find = " << time(NULL) - start << endl;

	start = time(NULL);
	for (int i = 0; i < n; i++)
	{
		tr.del(i);
	}
	cout << "time delete= " << time(NULL) - start << endl;

	system("pause");
	return;
}