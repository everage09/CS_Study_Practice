#include "../headers/DataStructure/myLinkedList.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	LinkedList<int> a(false);
	for (int i = 0; i < 10; i++) a.push_back(i);
	for (int i = 0; i < 10; i++) a.push_front(i);
	LinkedList<int> b(a);
	LinkedList<int> c = a;
	b.push_back(1234);
	c.push_front(9876);
	a.insert(10, 100);
	a.print();
	a.pop_front();
	a.pop_back();
	a.print();
	
	for (LinkedList<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << '\n';
	for (LinkedList<int>::iterator iter = b.begin(); iter != b.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << '\n';
	for (LinkedList<int>::iterator iter = c.begin(); iter != c.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << '\n';
	b.remove(1234);
	c.erase(3);
	b.print();
	c.print();
	return 0;
}