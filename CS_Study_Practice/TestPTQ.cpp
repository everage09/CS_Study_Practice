#include <iostream>
#include <random>
#include "MyPriorityQueue.h"

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);

	myPTQ<int> pq(100, true);
	int num;
	cout << "Enqueuing : ";
	for (int i = 0; i < 10; i++)
	{
		num = dist(rd);
		pq.Enqueue(num);
		cout << num << " ";
	}
	cout << '\n';
	int item;
	cout << "Dequeueing : ";
	for (int i = 0; i < 10; i++)
	{
		pq.Dequeue(item);
		cout << item << " ";
	}
	return 0;
}