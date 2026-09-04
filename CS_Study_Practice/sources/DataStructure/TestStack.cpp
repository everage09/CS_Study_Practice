#include <iostream>
#include "../headers/DataStructure/myStack.h"

using namespace std;

int main()
{
	myStack<int> st;
	st.push(10000);
	for (int i = 0; i < 10; i++)
	{
		st.push(i);
	}
	myStack<int> st2(st);
	st2.setLimit(15);
	st2.push(1234);
	myStack<int> st3 = st2;
	cout << "3 is " << st.find(3) << "th (/st/nd) item in stack.\n";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << '\n';
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << '\n';
	while (!st3.empty())
	{
		cout << st3.top() << " ";
		st3.pop();
	}
	cout << '\n';
	return 0;
}