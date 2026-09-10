#pragma once

template <typename T>
void BubbleSort(T arr[], size_t size, bool reverse = false)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (!reverse)
			{
				if (arr[i] > arr[j])
				{
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			else
			{
				if (arr[i] < arr[j])
				{
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}
