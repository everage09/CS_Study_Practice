#pragma once

template<typename T>
void Split(T values[], int first, int last, int& splitpoint)
{
	// case of selecting first item of array to key value (pivot)
	T key = values[first];
	int low = first+1;
	int high = last;
	while (low < high)
	{
		while (low < last && values[low] < key)
		{
			low++;
		}
		while (high > first && values[high] > key)
		{
			high--;
		}
		if (low < high)
		{
			T temp = values[low];
			values[low] = values[high];
			values[high] = temp;
		}
	}
	T temp = values[high];
	values[high] = key;
	values[first] = temp;

	splitpoint = high;
}

template <typename T>
void QuickSort(T values[], int first, int last)
{
	if (first < last)
	{
		int splitpoint;
		Split(values, first, last, splitpoint);
		QuickSort(values, first, splitpoint-1);
		QuickSort(values, splitpoint+1, last);
	}
}