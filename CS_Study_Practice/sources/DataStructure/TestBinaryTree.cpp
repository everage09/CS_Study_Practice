#include "../headers/DataStructure/Tree/myBinarytTree.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
	BinaryTree<int> BT;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);

	// TREE INIT : RANDOM INT INSERTION 
	int delTarget;
	for (int i = 0; i < 5; i++)
	{
		int num = dist(gen);
		BT.Insert(num);
		if (i == 3) delTarget = num;
	}
	cout << "TARGET : " << delTarget << '\n';
	cout << "BT : ";
	BT.Print(cout);
	
	// TEST COPY CONSTRUCTOR
	BinaryTree<int> BT2(BT);
	BT.Insert(10);
	BT.Insert(123);
	BT.Insert(83);
	BT.DeleteItem(delTarget);

	// TEST COPY ASSIGNMENT
	BinaryTree<int> BT3 = BT;

	cout << "BT : ";
	BT.Print(cout);
	cout << "BT2 : ";
	BT2.Print(cout);
	cout << "BT3 : ";
	BT3.Print(cout);

	// TEST FIND
	bool found;
	BT.Find(delTarget, found);
	if (found) cout << delTarget << " is found.\n" ;
	else cout << delTarget << " is not found.\n";
	BT2.Find(delTarget, found);
	if (found) cout << delTarget << " is found.\n";
	else cout << delTarget << " is not found.\n";
	BT3.Find(delTarget, found);
	if (found) cout << delTarget << " is found.\n";
	else cout << delTarget << " is not found.\n";

	// TEST LENGTH
	cout << "BT length : " << BT.Length() << '\n';
	cout << "BT2 length : " << BT2.Length() << '\n';
	cout << "BT3 length : " << BT3.Length() << '\n';

	// TEST EMPTY + FULL
	BinaryTree<int> BT4;
	cout << BT.IsEmpty() << " : " << BT.IsFull() << '\n';
	cout << BT2.IsEmpty() << " : " << BT2.IsFull() << '\n';
	cout << BT3.IsEmpty() << " : " << BT3.IsFull() << '\n';
	cout << BT4.IsEmpty() << " : " << BT4.IsFull() << '\n';

	// TEST MAKE EMPTY
	BT3.MakeEmpty();
	cout << BT3.IsEmpty() << '\n';
	BT3.Print(cout);
	cout << BT.IsEmpty() << '\n';
	BT.Print(cout);
	cout << '\n';
	// TEST RESETTREE + GETNEXTITEM
	bool finished = false;
	int num;
	BT.ResetTree(OrderType::PreOrder);
	BT.ResetTree(OrderType::InOrder);
	BT.ResetTree(OrderType::PostOrder);
	while (!finished)
	{
		BT.GetNextItem(num, OrderType::PreOrder, finished);
		cout << num << " ";
	}
	cout << '\n';
	finished = false;
	while (!finished)
	{
		BT.GetNextItem(num, OrderType::InOrder, finished);
		cout << num << " ";
	}
	cout << '\n';
	finished = false;
	while (!finished)
	{
		BT.GetNextItem(num, OrderType::PostOrder, finished);
		cout << num << " ";
	}
	cout << '\n';
	return 0;
}