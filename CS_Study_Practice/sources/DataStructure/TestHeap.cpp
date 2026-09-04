#include <iostream>
#include "../headers/DataStructure/Tree/myHeap.h"
#include <random>

using namespace std;

int main()
{
	myHeap<int> hp, minhp;
	hp.elements = new int[100];
	hp.numElements = 0;
	hp.isMaxHeap = true;

	minhp.elements = new int[100];
	minhp.numElements = 0;
	minhp.isMaxHeap = false;
	// insert random values to heaps
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 15);
	for (int i = 0; i < 9; i++)
	{
		int num = dist(gen);
		hp.InsertItem(num);
		minhp.InsertItem(num);
		cout << num << " ";
	}
	// print heap
	cout << '\n';
	cout << "Heap size : " << hp.numElements << '\n';
	for (int i = 0; i < hp.numElements; i++)
	{
		cout << hp.elements[i] << " ";
	}
	cout << '\n';

	// insert new item
	hp.InsertItem(10);
	hp.InsertItem(5);
	minhp.InsertItem(10);
	minhp.InsertItem(5);

	// print
	cout << "Heap size : " << hp.numElements << '\n';
	for (int i = 0; i < hp.numElements; i++)
	{
		cout << hp.elements[i] << " ";
	}
	cout << '\n';

	cout << "minHeap size : " << minhp.numElements << '\n';
	for (int i = 0; i < minhp.numElements; i++)
	{
		cout << minhp.elements[i] << " ";
	}
	cout << '\n';

	// pop 
	int top;
	hp.HeapPop(top);
	cout << top << '\n';
	cout << "Heap size : " << hp.numElements << '\n';
	for (int i = 0; i < hp.numElements; i++)
	{
		cout << hp.elements[i] << " ";
	}
	cout << '\n';
	
	delete[] hp.elements;
	return 0;
}