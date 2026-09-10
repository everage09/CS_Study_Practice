#pragma once

template <typename T>
void Merge(T arr[], int leftStart, int leftEnd, int rightStart, int rightEnd, bool reverse)
{
	int leftIdx = leftStart;
	int rightIdx = rightStart;
	int tempIdx = 0;
	T* temp = new T[rightEnd - leftStart + 1];
	while (leftIdx <= leftEnd && rightIdx <= rightEnd)
	{
		if (!reverse)
		{
			if (arr[leftIdx] < arr[rightIdx])
			{
				temp[tempIdx] = arr[leftIdx];
				leftIdx++;
			}
			else
			{
				temp[tempIdx] = arr[rightIdx];
				rightIdx++;
			}
		}
		else
		{
			if (arr[leftIdx] > arr[rightIdx])
			{
				temp[tempIdx] = arr[leftIdx];
				leftIdx++;
			}
			else
			{
				temp[tempIdx] = arr[rightIdx];
				rightIdx++;
			}
		}
		tempIdx++;
	}
	while (leftIdx <= leftEnd)
	{
		
		temp[tempIdx] = arr[leftIdx];
		leftIdx++;
		tempIdx++;
	}
	while (rightIdx <= rightEnd)
	{
		temp[tempIdx] = arr[rightIdx];
		rightIdx++;
		tempIdx++;
	}
	for (int i = leftStart; i <= rightEnd; i++)
	{
		arr[i] = temp[i-leftStart];
	}
	delete[] temp;
}

template <typename T>
void MergeSort(T arr[], int start, int end, bool reverse = false)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid, reverse);
		MergeSort(arr, mid+1, end, reverse);
		Merge(arr, start, mid, mid+1, end, reverse);
	}
}