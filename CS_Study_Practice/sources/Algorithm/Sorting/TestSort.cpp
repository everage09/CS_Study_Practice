#include <iostream>
#include <random>
#include "../headers/Algorithm/Sorting/QuickSort.h"
#include "../headers/Algorithm/Sorting/SelectionSort.h"
#include "../headers/Algorithm/Sorting/BubbleSort.h"
#include "../headers/Algorithm/Sorting/InsertionSort.h"
#include "../headers/Algorithm/Sorting/MergeSort.h"
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
	//QuickSort(vals, 0, 9, true);
	//SelectionSort(vals, 10, true);
	//BubbleSort(vals, 10);
	//InsertionSort(vals, 10, true);
	MergeSort(vals, 0, 9, true);
	for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); ++i)
	{
		cout << vals[i] << " ";
	}
	cout << '\n';
	string st[6] = { "asdb", "qwrjsda", "agndv", "cghweug", "etfdfp", "mgdfg" };
	//QuickSort(st, 0, 5, true);
	//SelectionSort(st, 6);
	//BubbleSort(st, 6);
	//InsertionSort(st, 6);
	MergeSort(st, 0, 5, true);
	for (int i = 0; i < 6; ++i)
	{
		cout << st[i] << " ";
	}
	return 0;
}