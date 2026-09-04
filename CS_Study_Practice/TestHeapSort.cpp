#include <iostream>
#include <random>
#include "myHeap.h"
#include <vector>
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
	for (int i = hp.numElements - 1; i >= 0; i--)
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

int main()
{
	int arr[10];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);
	for (int i = 0; i < 10; i++)
	{
		int num = dist(gen);
		arr[i] = num;
		cout << num << " ";
	}
	cout << '\n';
	// Sort in ascending order 
	HeapSort(arr, false);
	for (int elem : arr)
	{
		cout << elem << " ";
	}
	cout << '\n';
	// Sort in descending order
	HeapSort(arr, true);
	for (int elem : arr)
	{
		cout << elem << " ";
	}
	cout << "\n\n";

	// test vector
	vector<int> vec(5);
	for (int& val : vec) val = dist(gen);

	cout << "2. std::vector (내림차순)" << endl;
	HeapSort(vec, true); // reverse = true
	for (int val : vec) cout << val << " ";
	cout << "\n\n";

	// test dynamic array
	size_t dynamicSize = 5;
	int* dynamicArray = new int[dynamicSize];
	for (size_t i = 0; i < dynamicSize; i++) dynamicArray[i] = dist(gen);

	cout << "3. 동적 할당 배열 int* (오름차순)" << endl;
	HeapSort(dynamicArray, dynamicSize); // 포인터 + 크기 직접 전달
	for (size_t i = 0; i < dynamicSize; i++) cout << dynamicArray[i] << " ";
	cout << "\n\n";

	delete[] dynamicArray;

	return 0;
}