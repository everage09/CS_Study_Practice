#pragma once

template<typename T>
int findIdx(T arr[], int start, int end, bool reverse)
{
	int index = start;
	for (int i = start+1; i < end; i++)
	{
		if (!reverse)
		{
			if (arr[i] < arr[index])
			{
				index = i;
			}
		}
		else
		{
			if (arr[i] > arr[index])
			{
				index = i;
			}
		}
	}
	return index;
}

template<typename T>
void SelectionSort(T arr[], size_t size, bool reverse = false)
{
	for (int i = 0; i < size - 1; i++)
	{
		T temp;
		int Idx = findIdx(arr, i, size, reverse);
		temp = arr[i];
		arr[i] = arr[Idx];
		arr[Idx] = temp;
	}
}