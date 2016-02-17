#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) 
    {
    	timestamp = 0;
    	maxCapacity = capacity;
    }
    
    int get(int key)
    {
    	auto found = kvCache.find(key);
    	if (found == kvCache.end())
    	    return -1;
    	else
    	{
    	    ktCache.find(key)->second = timestamp;
    	    timestampHisory.push(timestamp);
		    keyHistory.push(key);
    	    timestamp++;
    	    return found->second;
    	}
    }
    
    void set(int key, int value)
    {
    	auto found = kvCache.find(key);
    	if (found == kvCache.end())
    	{
    		if (kvCache.size() >= maxCapacity)
	    	{
	    		while (true)
	    		{
	    			int lruKey = keyHistory.front();
	    			keyHistory.pop();
		    		int lruTime = timestampHisory.front();
		    		timestampHisory.pop();
	
		    		auto got = ktCache.find(lruKey);
		    		if (got->second != lruTime)
		    			continue;
		    		else
		    		{
		    			kvCache.erase(lruKey);
		    			ktCache.erase(lruKey);
		    			break;
		    		}
	    		}
	    	}

	    	kvCache.insert(make_pair(key, value));
    		ktCache.insert(make_pair(key, timestamp));
    	}
    	else
    	{
    		found->second = value;
    		ktCache.find(key)->second = timestamp;
    	}

    	timestampHisory.push(timestamp);
		keyHistory.push(key);
		timestamp++;
    }

private:
	unordered_map<long long, long long> kvCache;
	unordered_map<long long, long long> ktCache;
	queue<long long> timestampHisory;
	queue<int> keyHistory;
	long long timestamp;
	int maxCapacity;
};

int main(int argc, char const *argv[])
{
	LRUCache lruCache(2);
	lruCache.set(2,1);
	lruCache.set(1,1);
	cout << lruCache.get(2) << endl;
	lruCache.set(4,1);
	cout << lruCache.get(1) << endl;
	cout << lruCache.get(2) << endl;
	
	return 0;
}