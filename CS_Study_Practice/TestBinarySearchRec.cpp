#include <iostream>
#include "BinarySearchRecursive.h"
#include "QuickSort.h"

using namespace std;

int main()
{
	float L[10] = { 1.f, 3.f, -1.f, 0, 12.f, 233.f, -53.f, -0.5f, 1234, 9.f };
	QuickSort(L, 0, 9);
	cout << BinarySearchRec(L, 0.f, 0, 9) << '\n';
	cout << BinarySearchRec(L, 233.f, 0, 9) << '\n';
	for (float elem : L)
	{
		cout << elem << " ";
	}
}