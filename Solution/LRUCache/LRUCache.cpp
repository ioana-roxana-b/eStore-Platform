#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
	lru.resize(capacity);
	size = 0;
	//throw("undefined");
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	for (it1 = requestsNo.begin(); it1 != requestsNo.end(); it1++)
	{
		it2 = find(lru.begin(), lru.end(), (*it1));
		if (lru.size() < lru.capacity())
		{
			if (it2 != lru.end())
				lru.erase(it2);
			lru.insert(lru.begin(), (*it1));
		}
		if (lru.size() >= lru.capacity())
		{
			if (it2 != lru.end())
			{
				lru.erase(it2);
				lru.insert(lru.begin(), (*it1));
			}
			else
			{
				lru.erase(lru.end() - 1);
				lru.insert(lru.begin(), (*it1));
			}
		}
	}
	return lru;
	//throw("undefined");
}

int LRUCache::getCapacity()
{
	return capacity;
	//throw("undefined");
}

int LRUCache::getSize()
{
	return size;
	//throw("undefined");
}

vector<int> LRUCache::getLRU()
{
	return lru;
	//throw("undefined");
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
	//throw("undefined");
}

void LRUCache::setCapacity(int capacity)
{
	lru.reserve(capacity);
	//throw("undefined");
}

void LRUCache::setLRU(vector<int> aux)
{
	lru = aux;
	//throw("undefined");
}
