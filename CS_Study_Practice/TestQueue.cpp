#include <iostream>
#include "MyQueue.h"

using namespace std;

int main()
{
	myQueue<int> q;
	q.push(1);
	if(!q.empty()) cout << q.front() << '\n';
	q.pop();
	if(!q.empty()) cout << q.back() << '\n';
	for (int i = 0; i < 10; i++)
	{
		q.push(i+10);
	}
	cout << q.find(10) << '\n';
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}