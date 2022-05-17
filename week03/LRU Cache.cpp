class LRUCache
{
public:
    int capct;
    list<int> cacheLRU;
    unordered_map<int, list<int>::iterator> cachMap;
    unordered_map<int, int> cachVal;
    LRUCache(int capacity)
    {
        capct = capacity;
    }

    int get(int key)
    {
        if (cachMap.find(key) != cachMap.end())
        {
            cacheLRU.erase(cachMap[key]);
            cacheLRU.push_front(key);
            cachMap[key] = cacheLRU.begin();
            return cachVal[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cachMap.find(key) != cachMap.end())
        {
            updateCaches(key);
            cachVal[key] = value;
            return;
        }
        updateCaches(key);
        cachVal[key] = value;
        return;
    }
    void updateCaches(int key)
    {
        if (cachMap.find(key) != cachMap.end())
        {
            cacheLRU.erase(cachMap[key]);
        }
        else if (cacheLRU.size() >= capct)
        {
            int lruKey = cacheLRU.back();
            cachVal.erase(lruKey);
            cacheLRU.erase(cachMap[lruKey]);
            cachMap.erase(lruKey);
        }
        cacheLRU.push_front(key);
        cachMap[key] = cacheLRU.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */