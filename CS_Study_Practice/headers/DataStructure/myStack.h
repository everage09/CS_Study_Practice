#pragma once
#include <iostream>
#include "myLinkedList.h"
using namespace std;

template <typename T>
class myStack
{
public:
	// Constructor
	inline myStack()
	{
		limit = 10;
		size = 0;
		head = nullptr;
		tail = nullptr;
	};
	inline ~myStack();
	inline myStack(int h)
	{
		limit = h;
		size = 0;
		head = nullptr;
		tail = nullptr;
	};
	myStack(const myStack& rhs);
	myStack& operator=(const myStack& rhs);

	// Member function
	void push(T item);
	void pop();
	inline bool empty() { return size == 0; };
	inline void clear() {
		while (!empty())
		{
			pop();
		}
	};
	inline T top() 
	{ 
		if (empty()) throw std::out_of_range("Reffering top of an empty");
		return tail->data; 
	};
	int find(T target);

	// Iterator
	typedef myIterator<T> iterator;
	iterator begin() { return iterator(head); };
	iterator end() { return iterator(nullptr); };

	// Getter
	int getLimit() const { return limit; };
	int getSize() const { return size; };

	// Setter
	inline void setLimit(int l) { limit = l; };
private:
	int limit;
	int size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
inline myStack<T>::~myStack()
{
	clear();
}

template<typename T>
inline myStack<T>::myStack(const myStack& rhs)
{
	limit = rhs.limit;
	size = 0;
	head = nullptr;
	tail = nullptr;
	Node<T>* cur = rhs.head;
	while (cur != nullptr)
	{
		push(cur->data);
		cur = cur->next;
	}
}

template<typename T>
inline myStack<T>& myStack<T>::operator=(const myStack& rhs)
{
	if (this == &rhs) return *this;
	clear();
	limit = rhs.getLimit();
	Node<T>* cur = rhs.head;
	while (cur != nullptr)
	{
		push(cur->data);
		cur = cur->next;
	}
	return *this;
}

template <typename T>
inline void myStack<T>::push(T item)
{
	if (size >= limit) return;
	Node<T>* newNode = new Node<T>(item, tail, nullptr);
	if (empty())
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}

template <typename T>
inline void myStack<T>::pop()
{
	if (empty()) return;
	Node<T>* temp = tail;
	tail = tail->prev;
	if (tail != nullptr)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}
	delete temp;
	temp = nullptr;
	size--;
}

template <typename T>
inline int myStack<T>::find(T target)
{
	Node<T>* cur = head;
	if (empty()) return -1;
	for (int i = 0; i < size; i++)
	{
		if (cur->data == target) return i;
		cur = cur->next;
	}
	return -1;
}