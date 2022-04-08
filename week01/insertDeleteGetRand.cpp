class RandomizedSet
{
public:
    unordered_map<int, int> numFreq;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (numFreq.find(val) == numFreq.end())
        {
            numFreq[val] = 1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (numFreq.find(val) == numFreq.end())
        {
            return false;
        }
        numFreq[val] = 0;
        if (numFreq[val] == 0)
            numFreq.erase(val);
        return true;
    }

    int getRandom()
    {
        int rndVal = rand() % numFreq.size();
        auto item = numFreq.begin();
        advance(item, rndVal);
        return item->first;
    }
};