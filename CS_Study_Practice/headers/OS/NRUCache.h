#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

template<typename T>
class NRUCache
{
public:
	NRUCache();
	NRUCache(int size);
	void Refer(int n);
	void PrintCache();

private:
	void ResetReferenceBits();

	vector<T> keys;
	unordered_map<T, bool> cache;

	int cacheSize;
	int timer;
	const int RESET_PERIOD = 3;
};

template<typename T>
inline NRUCache<T>::NRUCache()
{
	cacheSize = 3;
	timer = 0;
}

template<typename T>
inline NRUCache<T>::NRUCache(int size)
{
	cacheSize = size;
	timer = 0;
}

template<typename T>
inline void NRUCache<T>::ResetReferenceBits()
{
	for (auto& pair : cache)
	{
		pair.second = false;
	}
	timer = 0;
}


template<typename T>
inline void NRUCache<T>::Refer(int n)
{
	/*
	* Find if page presents in cache.
	* Reference bit resetting only if cache is full : second chance / clock algorithm
	*/
	if (cache.size() == cacheSize)
	{
		timer++;
	}
	if (timer >= RESET_PERIOD)
	{
		ResetReferenceBits();
	}

	// Cache Hit
	if (cache.find(n) != cache.end())
	{
		cache[n] = true;
		return;
	}
	// Cache Miss or Cache Full
	if (cache.size() == cacheSize)
	{
		typename vector<T>::iterator eraseTarget = keys.end();
		// Find first not recently used page
		for (auto key = keys.begin(); key < keys.end(); key++)
		{
			if (cache[*key])
			{
				eraseTarget = key;
				break;
			}
		}
		// If every Reference bit is true, reset all to false then erase first page
		if (eraseTarget == keys.end() && cache.size() == cacheSize)
		{
			ResetReferenceBits();
			eraseTarget = keys.begin();
		}
		// Erase target page
		T targetKey = *eraseTarget;
		cache.erase(targetKey);
		keys.erase(eraseTarget);
	}
	// Push new page
	cache[n] = true;
	keys.emplace_back(n);
}

template<typename T>
inline void NRUCache<T>::PrintCache()
{
	/*
	* Print out all elements in the cache.
	*/
	for (auto& key : keys)
	{
		cout << "[" << key << "(R:" << cache[key] << ")] ";
	}
	cout << '\n';
}
