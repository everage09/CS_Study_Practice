#pragma once

template <typename T>
void InsertItem(T arr[], int start, int end, bool reverse)
{
	int current = end;
	bool InsertDone = false;
	bool foundIndex = (current != start);

	while (foundIndex && !InsertDone)
	{
		if (!reverse)
		{
			if (arr[current] < arr[current - 1])
			{
				T temp = arr[current];
				arr[current] = arr[current - 1];
				arr[current - 1] = temp;
				current--;
				foundIndex = (current != start);
			}
			else
			{
				InsertDone = true;
			}
		}
		else
		{
			if (arr[current] > arr[current - 1])
			{
				T temp = arr[current];
				arr[current] = arr[current - 1];
				arr[current - 1] = temp;
				current--;
				foundIndex = (current != start);
			}
			else
			{
				InsertDone = true;
			}
		}
	}
}

template <typename T>
void InsertionSort(T arr[], size_t size, bool reverse = false)
{
	int insertIdx = 0;
	for (int i = 0; i < size; i++)
	{
		InsertItem(arr, 0, i, reverse);
	}
}