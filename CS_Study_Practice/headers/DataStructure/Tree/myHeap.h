#pragma once

template <typename T>
struct myHeap
{
	void ReHeapDown(int root, int bottom);
	void ReHeapUp(int root, int bottom);
	void HeapPop(T& Item);
	void InsertItem(T item);

	T* elements;
	int numElements;
	bool isMaxHeap = true;
};

template <typename T>
void Swap(T& item1, T& item2)
{
	T temp;
	temp = item2;
	item2 = item1;
	item1 = temp;
}

template<typename T>
inline void myHeap<T>::ReHeapDown(int root, int bottom)
{
	// recursive swapping of root towards bottom

	int maxChild;
	int minChild;
	int leftChild;
	int rightChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		// find larger child of root (current position)
		if (leftChild == bottom)
		{
			maxChild = leftChild;
			minChild = leftChild;
		}
		else
		{
			if (elements[leftChild] <= elements[rightChild])
			{
				maxChild = rightChild;
				minChild = leftChild;
			}
			else
			{
				maxChild = leftChild;
				minChild = rightChild;
			}
		}
		// swap larger child with root (current position)
		if (isMaxHeap)
		{
			if (elements[root] < elements[maxChild])
			{
				Swap(elements[root], elements[maxChild]);
				ReHeapDown(maxChild, bottom);
			}
		}
		else
		{
			if (elements[root] > elements[minChild])
			{
				Swap(elements[root], elements[minChild]);
				ReHeapDown(minChild, bottom);
			}
		}
	}
}

template<typename T>
inline void myHeap<T>::ReHeapUp(int root, int bottom)
{
	int parent;
	if (root < bottom)
	{
		parent = (bottom - 1) / 2;
		if (isMaxHeap)
		{
			if (elements[parent] < elements[bottom])
			{
				Swap(elements[parent], elements[bottom]);
				ReHeapUp(root, parent);
			}
		}
		else
		{
			if (elements[parent] > elements[bottom])
			{
				Swap(elements[parent], elements[bottom]);
				ReHeapUp(root, parent);
			}
		}
	}
}

template<typename T>
inline void myHeap<T>::HeapPop(T& Item)
{
	if (numElements <= 0) return;
	Item = elements[0];
	elements[0] = elements[numElements - 1];
	numElements--;
	if (numElements > 0)
	{
		ReHeapDown(0, numElements - 1);
	}
}

template<typename T>
inline void myHeap<T>::InsertItem(T item)
{
	elements[numElements] = item;
	ReHeapUp(0, numElements);
	numElements++;
}