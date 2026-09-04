#include "../headers//DataStructure/mySet.h"
#include <iostream>

using namespace std;

int main()
{
	mySet<int> s;
	s.Add(10);
	s.Add(10);
	s.Add(5);
	s.Add(2);
	s.Add(100);
	cout << "TEST ADD\n";
	s.PrintItems();
	cout << '\n';

	s.Delete(1);
	s.Delete(5);
	cout << "TEST DELETE\n";
	s.PrintItems();
	cout << '\n';

	s.MakeEmpty();
	cout << "TEST MAKE EMPTY\n";
	s.PrintItems();
	cout << '\n';

	s.Add(23);
	s.Add(45);
	s.Add(876);
	s.Add(346);
	s.Add(315);
	cout << "TEST ADD AGAIN\n";
	s.PrintItems();
	cout << '\n';

	mySet<int> other;
	other.Add(765);
	other.Add(961);
	other.Add(23);
	other.Add(45);
	cout << "TEST ANOTHER SET\n";
	other.PrintItems();
	cout << '\n';

	mySet<int> I = s.Intersection(other);
	mySet<int> U = s.Union(other);
	mySet<int> D1 = s.Difference(other);
	mySet<int> D2 = other.Difference(s);

	cout << "TEST A INTERSECTION B\n";
	I.PrintItems();
	cout << '\n';
	cout << "TEST A UNION B\n";
	U.PrintItems();
	cout << '\n';
	cout << "TEST A DIFF B\n";
	D1.PrintItems();
	cout << '\n';
	cout << "TEST B DIFF A\n";
	D2.PrintItems();
	cout << '\n';
	return 0;
}