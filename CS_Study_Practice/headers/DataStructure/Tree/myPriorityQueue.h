#pragma once
#include "myHeap.h"

template <typename T>
class myPTQ
{
public:
	myPTQ();
	myPTQ(int size, bool isMax);
	~myPTQ();
	void MakeEmpty();
	void Enqueue(T item);
	void Dequeue(T& item);
	inline bool IsFull() const { return length == maxLength; };
	inline bool IsEmpty() const {
		return length == 0;
	};

private:
	myHeap<T> hp;
	int length;
	int maxLength;
	bool IsMaxPTQ;
};

template<typename T>
inline myPTQ<T>::myPTQ() : myPTQ(10, true) {}

template <typename T>
myPTQ<T>::myPTQ(int size, bool isMax)
{
	maxLength = size;
	length = 0;
	IsMaxPTQ = isMax;
	hp.elements = new T[size];
	hp.numElements = 0;
	hp.isMaxHeap = IsMaxPTQ;
}

template <typename T>
myPTQ<T>::~myPTQ()
{
	delete[] hp.elements;
}

template <typename T>
void myPTQ<T>::MakeEmpty()
{
	T item;
	while (!IsEmpty())
	{
		Dequeue(item);
	}
}

template<typename T>
inline void myPTQ<T>::Enqueue(T item)
{
	if (length < maxLength)
	{
		hp.InsertItem(item);
		length++;
	}
	return;
}

template<typename T>
inline void myPTQ<T>::Dequeue(T& item)
{
	if (length == 0) return;
	else
	{
		hp.HeapPop(item);
		length--;
	}
}
