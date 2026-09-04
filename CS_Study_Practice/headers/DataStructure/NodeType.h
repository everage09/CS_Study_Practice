#pragma once
template<typename T>
struct Node
{
	struct Node<T>* prev, * next;
	T data;
	Node(const T& a = T(), Node<T>* pr = nullptr, Node<T>* nx = nullptr)
	{
		data = a;
		prev = pr;
		next = nx;
	}
};