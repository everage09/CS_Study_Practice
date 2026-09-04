#pragma once
#include <iostream>
#include "myLinkedList.h"

template <typename T>
class mySet
{
public:
	mySet() : mySet<T>(100) {};
	mySet(int maxSize);
	~mySet();
	mySet<T>& operator = (const mySet<T>& other);
	void MakeEmpty();
	void Add(T item);
	void Delete(T item);

	inline bool IsFull() const {
		return Size() == maxElements;
	}
	inline bool IsEmpty() const { return Size() == 0; }
	inline int Size() const { return L.getSize(); }
	inline Node<T>* getHead() const { return L.getHead(); }
	void PrintItems();

	mySet<T> Intersection(const mySet<T>& other);
	mySet<T> Union(const mySet<T>& other);
	mySet<T> Difference(const mySet<T>& other);
	

private:
	LinkedList<T> L;
	int maxElements;
};

template<typename T>
inline mySet<T>::mySet(int maxSize) : L(true), maxElements(maxSize)
{}

template<typename T>
inline mySet<T>::~mySet()
{
	MakeEmpty();
}

template<typename T>
inline mySet<T>& mySet<T>::operator=(const mySet<T>& other)
{
	if (this == &other) return *this;
	MakeEmpty();
	Node<T>* cur = other.getHead();
	while (cur != nullptr)
	{
		Add(cur->data);
		cur = cur->next;
	}
	return *this;
}

template <typename T>
void inline mySet<T>::MakeEmpty()
{
	while (!L.isEmpty())
	{
		L.pop_front();
	}
}

template<typename T>
inline void mySet<T>::Add(T item)
{
	// Retrieve item before add
	bool found;
	int idx = L.find(item, found);
	if (!found)
	{
		L.push_back(item);
	}
}

template<typename T>
inline void mySet<T>::Delete(T item)
{
	// Retrieve item before delete
	bool found;
	int idx = L.find(item, found);
	if (found)
	{
		L.erase(idx);
	}
}

template<typename T>
inline mySet<T> mySet<T>::Intersection(const mySet<T>& other)
{
	mySet<T> inter;
	Node<T>* myCur = getHead();
	Node<T>* otherCur = other.getHead();
	while (myCur != nullptr && otherCur != nullptr)
	{
		if (myCur->data == otherCur->data)
		{
			inter.Add(myCur->data);
			myCur = myCur->next;
			otherCur = otherCur->next;
		}
		else if (myCur->data < otherCur->data)
		{
			myCur = myCur->next;
		}
		else
		{
			otherCur = otherCur->next;
		}
	}
	return inter;
}

template<typename T>
inline mySet<T> mySet<T>::Union(const mySet<T>& other)
{
	mySet<T> uni;
	Node<T>* myCur = getHead();
	Node<T>* otherCur = other.getHead();
	while (myCur != nullptr && otherCur != nullptr)
	{
		if (myCur->data == otherCur->data)
		{
			uni.Add(myCur->data);
			myCur = myCur->next;
			otherCur = otherCur->next;

		}
		else if (myCur->data < otherCur->data)
		{
			uni.Add(myCur->data);
			myCur = myCur->next;
		}
		else
		{
			uni.Add(otherCur->data);
			otherCur = otherCur->next;
		}
	}
	while (myCur != nullptr)
	{
		uni.Add(myCur->data);
		myCur = myCur->next;
	}
	while (otherCur != nullptr)
	{
		uni.Add(otherCur->data);
		otherCur = otherCur->next;
	}
	return uni;
}

template<typename T>
inline mySet<T> mySet<T>::Difference(const mySet<T>& other)
{
	mySet<T> diff;
	Node<T>* myCur = getHead();
	Node<T>* otherCur = other.getHead();
	while (myCur != nullptr && otherCur != nullptr)
	{
		if (myCur->data == otherCur->data)
		{
			myCur = myCur->next;
			otherCur = otherCur->next;
		}
		else if (myCur->data < otherCur->data)
		{
			diff.Add(myCur->data);
			myCur = myCur->next;
		}
		else
		{
			otherCur = otherCur->next;
		}
	}
	while (myCur != nullptr)
	{
		diff.Add(myCur->data);
		myCur = myCur->next;
	}
	return diff;
}

template<typename T>
inline void mySet<T>::PrintItems()
{
	L.print();
}
