#pragma once
#include <iostream>
#include "NodeType.h"
using namespace std;

template<typename T>
class myIterator
{
public:
	myIterator(Node<T>* p = nullptr) : cur(p) {};
	inline myIterator& operator++()
	{
		cur = cur->next;
		return *this;
	}
	inline myIterator operator++(int)
	{
		myIterator temp = *this;
		if (cur != nullptr) cur = cur->next;
		return temp;
	}
	inline bool operator ==(const myIterator &rhs)
	{
		return cur == rhs.cur;
	}
	inline bool operator !=(const myIterator& rhs)
	{
		return cur != rhs.cur;
	}
	inline T& operator *()
	{
		if (cur != nullptr) return cur->data;
		else throw std::out_of_range("Referring empty list or reached end of list");
	}
private:
	Node<T>* cur;
};

template<typename T>
class LinkedList
{
public:
	// Constructor
	LinkedList();
	~LinkedList();
	LinkedList(bool toSort);
	LinkedList(const LinkedList& rhs);
	LinkedList& operator=(const LinkedList& rhs);

	// Member function
	void push_front(T item);
	void push_back(T item);
	void insert(T item);
	void insert(int index, T item);
	void insert(Node<T>* target, T item);
	void pop_front();
	void pop_back();
	void remove(T item);
	void erase(int index);
	int find(const T& item, bool& found);
	void print();

	// Getter
	inline Node<T>* getHead() const { return head; }
	inline Node<T>* getTail() const { return tail; }
	inline int getSize() const { return size; }
	inline bool getIsSorted() const { return isSorted; }
	inline bool isEmpty() const { return size == 0; }

	// Iterator
	typedef myIterator<T> iterator;
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }

private:
	int size;
	bool isSorted;
	Node<T>* head;
	Node<T>* tail;

	inline void link_front(T item) {
		Node<T>* newNode = new Node<T>(item, nullptr, head);
		if (size > 0) head->prev = newNode;
		else tail = newNode;
		head = newNode;
		size++;
	};

	inline void link_back(T item) {
		Node<T>* newNode = new Node<T>(item, tail, nullptr);
		if (size > 0) tail->next = newNode;
		else head = newNode;
		tail = newNode;
		size++;
	};
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	size = 0;
	isSorted = false;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	while (size > 0)
	{
		pop_front();
	}
}

template<typename T>
inline LinkedList<T>::LinkedList(bool toSort)
{
	size = 0;
	isSorted = toSort;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& rhs)
{
	size = 0;
	isSorted = false; // temporarily false;
	head = nullptr;
	tail = nullptr;

	Node<T>* cur = rhs.getHead();
	while (cur != nullptr)
	{
		push_back(cur->data);
		cur = cur->next;
	}
	isSorted = rhs.getIsSorted();
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
	if (this == &rhs) return *this;
	while (size > 0)
	{
		pop_front();
	}
	isSorted = false;
	head = nullptr;
	tail = nullptr;

	Node<T>* cur = rhs.getHead();
	while (cur != nullptr)
	{
		push_back(cur->data);
		cur = cur->next;
	}
	isSorted = rhs.getIsSorted();
	return *this;
}

template<typename T>
inline void LinkedList<T>::push_front(T item)
{
	if (isSorted)
	{
		insert(item);
		return;
	}
	link_front(item);
}

template<typename T>
inline void LinkedList<T>::push_back(T item)
{
	if (isSorted)
	{
		insert(item);
		return;
	}
	link_back(item);
}

template<typename T>
inline void LinkedList<T>::insert(T item)
{
	// If the list is unsorted, push back the new item to this list.
	// If the list is sorted, insert the item to the right spot.
	if (!isSorted || size == 0)
	{
		link_back(item);
		return;
	}
	else
	{
		Node<T>* cur = head;
		while (cur != nullptr && cur->data < item)
		{
			cur = cur->next;
		}
		if (cur == nullptr) // inserting at the end of list
		{
			link_back(item);
		}
		else if (cur == head)
		{
			link_front(item);
		}
		else
		{
			insert(cur, item);
		}
	}
}

template<typename T>
inline void LinkedList<T>::insert(int index, T item)
{
	if (isSorted)
	{
		insert(item);
		return;
	}
	if (index < 0 || index > size) return;
	if (index == 0)
	{
		link_front(item);
		return;
	}
	if (index == size)
	{
		link_back(item);
		return;
	}

	Node<T>* target = head;
	for(int i = 0; i < index; i++)
	{
		target = target->next;
	}
	insert(target, item);
}

template<typename T>
inline void LinkedList<T>::insert(Node<T>* target, T item)
{
	if (target == nullptr) return;
	if (target == head)
	{
		link_front(item);
		return;
	}
	else if (target == tail)
	{
		link_back(item);
		return;
	}
	else
	{
		Node<T>* newNode = new Node<T>(item, target->prev, target);
		if (target->prev != nullptr)
		{
			target->prev->next = newNode;
		}
		target->prev = newNode;
		size++;
		return;
	}
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	if (size == 0) return;

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
	delete(temp);
	temp = nullptr;
	size--;
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	if (size == 0) return;

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
	delete(temp);
	temp = nullptr;
	size--;
}

template<typename T>
inline void LinkedList<T>::remove(T item)
{
	// Remove specific item if item exists in the list.
	Node<T>* cur = head;
	if (isSorted)
	{
		while (cur != nullptr && cur->data < item)
		{
			cur = cur->next;
		}
		if (cur != nullptr && cur->data == item)
		{
			if (cur == head) pop_front();
			else if (cur == tail) pop_back();
			else
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				cur = nullptr;
				size--;
			}
		}
	}
	else
	{
		while (cur != nullptr)
		{
			if (cur->data == item)
			{
				if (cur == head) pop_front();
				else if (cur == tail) pop_back();
				else
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					delete cur;
					cur = nullptr;
					size--;
				}
				return;
			}
			cur = cur->next;
		}
	}
}

template<typename T>
inline void LinkedList<T>::erase(int index)
{
	// Remove item at index
	if (index < 0 || index >= size) return;
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == size - 1)
	{
		pop_back();
		return;
	}
	Node<T>* cur = head;
	for (int i = 0; i < index; i++)
	{
		cur = cur->next;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
	cur = nullptr;
	size--;
}

template<typename T>
inline int LinkedList<T>::find(const T& item, bool& found)
{
	Node<T>* cur = head;
	for (int i = 0; i < size; i++)
	{
		if (cur->data == item)
		{
			found = true;
			return i;
		}
		cur = cur->next;
	}
	found = false;
	return -1;
}

template<typename T>
inline void LinkedList<T>::print()
{
	Node<T> *cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
}
