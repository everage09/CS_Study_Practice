#pragma once
#include "myLinkedList.h"

template<typename T>
class myQueue
{
public:
	// Constructor
	inline myQueue() { limit = INT_MAX; size = 0; head = nullptr; tail = nullptr; };
	inline ~myQueue() { while (!empty()) pop(); };
	inline myQueue(int h) {
		limit = h;
		size = 0;
		head = nullptr;
		tail = nullptr;
	};
	myQueue(const myQueue& Q);
	myQueue& operator=(const myQueue& Q);
	
	// Memeber function
	void push(T item);
	void pop();
	bool empty() { return size == 0; };
	T front() { if (head) return head->data;};
	T back() { if (tail) return tail->data;};
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

template<typename T>
inline myQueue<T>::myQueue(const myQueue& Q)
{
	limit = Q.getLimit();
	size = 0;
	head = nullptr;
	tail = nullptr;
	
	Node<T>* cur = Q.head;
	while (cur != nullptr)
	{
		push(cur->data);
		cur = cur->next;
	}
}

template<typename T>
inline myQueue<T>& myQueue<T>::operator=(const myQueue& Q)
{
	if (this == &Q) return *this;
	while (!empty())
	{
		pop();
	}
	limit = Q.getLimit();
	Node<T>* cur = Q.head;
	while (cur != nullptr)
	{
		push(cur->data);
		cur = cur->next;
	}
	return *this;
}

template <typename T>
inline void myQueue<T>::push(T item)
{
	if (size >= limit) return;
	Node<T>* newNode = new Node<T>(item, tail, nullptr);
	if (size > 0)
	{
		tail->next = newNode;
	}
	else
	{
		head = newNode;
	}
	tail = newNode;
	size++;
}

template <typename T>
inline void myQueue<T>::pop()
{
	if (empty()) return;
	Node<T>* temp = head;
	head = head->next;
	if (head != nullptr)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}
	delete temp;
	size--;
}

template <typename T>
inline int myQueue<T>::find(T target)
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