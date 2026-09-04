#pragma once
#include <list>
#include <unordered_map>

using namespace std;

template<typename T>
class LRUCache
{
public:
	LRUCache();
	LRUCache(int size);
	void Refer(int n);
	void PrintCache();
	
private:
	unordered_map<T, typename list<T>::iterator> hash;
	int cacheSize;
};

template<typename T>
inline LRUCache<T>::LRUCache()
{
	cacheSize = 3;
}

template<typename T>
inline LRUCache<T>::LRUCache(int size)
{
	cacheSize = size;
}

template<typename T>
inline void LRUCache<T>::Refer(int n)
{
	/*
	*  Find if 'n' is in the cache
	*  If present, make it front of the cache.
	*  Else delete the last item of cache and push front 'n' to the cache.
	*/
	if (hash.find(n) == hash.end())
	{
		if (li.size() == cacheSize)
		{
			T last = li.back();
			li.pop_back();
			hash.erase(last);
		}
	}
	else
	{
		li.erase(hash[n]);
	}
	li.push_front(n);
	hash[n] = li.begin();
}

template<typename T>
inline void LRUCache<T>::PrintCache()
{
	/*
	* Print out all elements in the cache.
	*/
	for (auto it = li.begin(); it != li.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\n';
}
