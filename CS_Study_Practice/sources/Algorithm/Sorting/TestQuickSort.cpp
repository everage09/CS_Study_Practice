#include <iostream>
#include <random>
#include "../headers/Algorithm/Sorting/QuickSort.h"
using namespace std;

int main()
{
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> distrib(1, 100);
	int vals[10];
	for (int i = 0; i < sizeof(vals) / sizeof(int); ++i)
	{
		vals[i] = distrib(gen);
	}
	for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); ++i)
	{
		cout << vals[i] << " ";
	}
	cout << '\n';
	QuickSort(vals, 0, 9);
	for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); ++i)
	{
		cout << vals[i] << " ";
	}
	cout << '\n';
	string st[6] = { "asdb", "qwrjsda", "agndv", "cghweug", "etfdfp", "mgdfg" };
	QuickSort(st, 0, 5);
	for (int i = 0; i < 6; ++i)
	{
		cout << st[i] << " ";
	}
	return 0;
}