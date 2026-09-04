#include <bits/stdc++.h>
#include "../headers/OS/LRUCache.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	LRUCache<int> C(4);
	C.Refer(1);
	C.PrintCache();
	C.Refer(2);
	C.PrintCache();
	C.Refer(4);
	C.PrintCache();
	C.Refer(6);
	C.PrintCache();
	C.Refer(1);
	C.PrintCache();
	C.Refer(7);
	C.PrintCache();
	C.Refer(2);
	C.PrintCache();
	C.Refer(6);
	C.PrintCache();
	C.Refer(9);
	C.PrintCache();
	return 0;
}