#include <iostream>
#include <bits/stdc++.h>
#include "Singleton.h"
using namespace std;

int main()
{
	const Singleton& instanceA = Singleton::getInstance();
	const Singleton& instanceB = Singleton::getInstance();
	cout << &instanceA << " " << instanceA.value << '\n';
	cout << &instanceB << " " << instanceB.value << '\n';
	Singleton& instanceC = Singleton::getInstance();
	cout << &instanceC << " " << instanceC.value << '\n';
}