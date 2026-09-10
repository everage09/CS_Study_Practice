#pragma once
#include <vector>
#include "../headers/DataStructure/Tree/myHeap.h"
using namespace std;

template <typename T>
void HeapSort(T* items, size_t count, bool reverse = false)
{
	myHeap<T> hp;
	hp.elements = items;
	hp.numElements = static_cast<int>(count);
	hp.isMaxHeap = !reverse;
	// Heapify
	for (int i = hp.numElements / 2 - 1; i >= 0; i--)
	{
		hp.ReHeapDown(i, hp.numElements - 1);
	}
	// Sort
	for (int i = hp.numElements - 1; i > 0; i--)
	{
		Swap(hp.elements[0], hp.elements[i]);
		hp.ReHeapDown(0, i - 1);
	}
}

template <typename T, size_t N>
void HeapSort(T(&items)[N], bool reverse = false)
{
	HeapSort(items, N, reverse);
}

template <typename T>
void HeapSort(vector<T>& vec, bool reverse = false)
{
	if (vec.empty()) return;
	HeapSort(vec.data(), vec.size(), reverse);
}