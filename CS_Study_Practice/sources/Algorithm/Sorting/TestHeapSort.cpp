#include <iostream>
#include <random>
#include "../headers/Algorithm/Sorting/HeapSort.h"
using namespace std;

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