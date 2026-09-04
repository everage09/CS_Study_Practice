#pragma once
#include <fstream>
#include "../myQueue.h"
#include "myHeap.h"

enum class OrderType {PreOrder, InOrder, PostOrder};

template <typename T>
struct TreeNode
{
	T info;
	TreeNode* left;
	TreeNode* right;
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(const BinaryTree<T>& Tree);
	void operator= (const BinaryTree<T>& Tree);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int Length() const;
	void Find(T& target, bool& found);
	void Insert(T Item);
	void DeleteItem(T Item);
	void ResetTree(OrderType order);
	void GetNextItem(T& Item, OrderType order, bool& finsihed);
	void Print(std::ostream& os) const;
private:
	TreeNode<T>* root;
	myQueue<T> preQueue;
	myQueue<T> inQueue;
	myQueue<T> postQueue;
};

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	Destroy(root);
}

template<typename T>
void Destroy(TreeNode<T>*& tree)
{
	if (tree != nullptr)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

template<typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& Tree)
{
	CopyNode(root, Tree.root);
}

template <typename T>
void CopyNode(TreeNode<T>*& dest, const TreeNode<T>* tree)
{
	if (tree == nullptr)
	{
		dest = nullptr;
	}
	else
	{
		dest = new TreeNode<T>;
		dest->info = tree->info;
		dest->left = tree->left;
		dest->right = tree->right;
		CopyNode(dest->left, tree->left);
		CopyNode(dest->right, tree->right);
	}
}

template<typename T>
inline void BinaryTree<T>::operator=(const BinaryTree<T>& Tree)
{
	if (this == &Tree) return;
	Destroy(root);
	CopyNode(root, Tree.root);
}

template<typename T>
inline void BinaryTree<T>::MakeEmpty()
{
	Destroy(root);
	root = nullptr;
}

template<typename T>
inline bool BinaryTree<T>::IsEmpty() const
{ 
	return root == nullptr;
}

template<typename T>
inline bool BinaryTree<T>::IsFull() const
{
	TreeNode<T>* location;
	try
	{
		location = new TreeNode<T>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<typename T>
inline int BinaryTree<T>::Length() const
{
	return CountNode(root);
}

template <typename T>
int CountNode(TreeNode<T>* Tree)
{
	if (Tree == nullptr)
	{
		return 0;
	}
	else
	{
		return CountNode(Tree->left) + CountNode(Tree->right) + 1;
	}
}

template<typename T>
inline void BinaryTree<T>::Find(T& target, bool& found)
{
	FindItem(root, target, found);
}

template <typename T>
void FindItem(TreeNode<T>* root, T& target, bool& found)
{
	if (root == nullptr)
	{
		found = false;
	}
	else if (root->info < target)
	{
		FindItem(root->right, target, found);
	}
	else if (root->info > target)
	{
		FindItem(root->left, target, found);
	}
	else
	{
		target = root->info;
		found = true;
	}
}

template<typename T>
inline void BinaryTree<T>::Insert(T Item)
{
	InsertItem(root, Item);
}

template<typename T>
void InsertItem(TreeNode<T>*& tree, T Item)
{
	if (tree == nullptr)
	{
		tree = new TreeNode<T>;
		tree->info = Item;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (tree->info < Item)
	{
		InsertItem(tree->right, Item);
	}
	else if (tree->info > Item)
	{
		InsertItem(tree->left, Item);
	}
	else
	{
		return;
	}
}

template<typename T>
inline void BinaryTree<T>::DeleteItem(T Item)
{
	Delete(root, Item);
}

template<typename T>
void Delete(TreeNode<T>*& tree, T Item)
{
	if (tree->info < Item)
	{
		Delete(tree->right, Item);
	}
	else if (tree->info > Item)
	{
		Delete(tree->left, Item);
	}
	else
	{
		DeleteNode(tree);
	}
}

template <typename T>
void DeleteNode(TreeNode<T>*& tree)
{
	T data;
	TreeNode<T>* temp = tree;
	if (tree->left == nullptr)
	{
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == nullptr)
	{
		tree = tree->left;
		delete tree->left;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

template <typename T>
void GetPredecessor(TreeNode<T>*& tree, T& Item)
{
	while (tree->right != nullptr)
	{
		tree = tree->right;
	}
	Item = tree->info;
}

template<typename T>
inline void BinaryTree<T>::ResetTree(OrderType order)
{
	switch (order)
	{
	case OrderType::PreOrder :
		PreOrder(root, preQueue);
		break;
	case OrderType::InOrder :
		InOrder(root, inQueue);
		break;
	case OrderType::PostOrder:
		PostOrder(root, postQueue);
		break;
	}
}

template<typename T>
inline void BinaryTree<T>::GetNextItem(T& Item, OrderType order, bool& finished)
{
	finished = false;
	switch (order)
	{
	case OrderType::PreOrder:
		Item = preQueue.front();
		preQueue.pop();
		if (preQueue.empty())
		{
			finished = true;
		}
		break;
	case OrderType::InOrder:
		Item = inQueue.front();
		inQueue.pop();
		if (inQueue.empty())
		{
			finished = true;
		}
		break;
	case OrderType::PostOrder:
		Item = postQueue.front();
		postQueue.pop();
		if (postQueue.empty())
		{
			finished = true;
		}
		break;
	}
}

template<typename T>
inline void BinaryTree<T>::Print(std::ostream& os) const
{
	PrintTree(root, os);
	os << '\n';
}

template<typename T>
void PrintTree(TreeNode<T>* tree, std::ostream& os)
{
	if (tree != nullptr)
	{
		PrintTree(tree->left, os);
		os << tree->info << " ";
		PrintTree(tree->right, os);
	}
}

template <typename T>
void InOrder(TreeNode<T>*& tree, myQueue<T>& queue)
{
	if (tree != nullptr)
	{
		InOrder(tree->left, queue);
		queue.push(tree->info);
		InOrder(tree->right, queue);
	}
}

template <typename T>
void PreOrder(TreeNode<T>*& tree, myQueue<T>& queue)
{
	if (tree != nullptr)
	{
		queue.push(tree->info);
		PreOrder(tree->left, queue);
		PreOrder(tree->right, queue);
	}
}

template <typename T>
void PostOrder(TreeNode<T>*& tree, myQueue<T>& queue)
{
	if (tree != nullptr)
	{
		PostOrder(tree->left, queue);
		PostOrder(tree->right, queue);
		queue.push(tree->info);
	}
}