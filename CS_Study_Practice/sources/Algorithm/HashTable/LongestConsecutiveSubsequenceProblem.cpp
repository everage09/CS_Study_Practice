#include <iostream>
#include <unordered_map>

using namespace std;
// 수열 내에서 가장 길게 찾을 수 있는 정수 수열(의 길이) 찾기
int main()
{
	int S[16] = {7, 1, 4, 3, 5, 5, 9, 4, 10, 25, 11, 12, 33, 2, 13, 6};
	//int S[6] = { 1, 2, 3, 2, 3, 4 };
	int maxLen = 0;
	int endNum = 0;
	unordered_map<int, int> hashTable;
	for (int elem : S)
	{
		int currentLen = 1;
		auto it = hashTable.find(elem - 1);
		if (it != hashTable.end())
		{
			currentLen = it->second + 1;
		}
		if (hashTable.find(elem) == hashTable.end() || hashTable[elem] < currentLen)
		{
			hashTable[elem] = currentLen;
		}
		if (currentLen > maxLen)
		{
			maxLen = currentLen;
			endNum = elem;
		}
	}
	cout << maxLen << '\n';
	for (int i = 0; i < maxLen; i++)
	{
		cout << endNum - maxLen + 1 + i << " ";
	}
	return 0;
}