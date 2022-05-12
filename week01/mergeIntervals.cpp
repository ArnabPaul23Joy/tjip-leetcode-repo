class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        unordered_multiset<int> begining;
        unordered_multiset<int> ending;
        int minVal = 100000000, maxVal = -100000000;
        for (int i = 0; i < intervals.size(); i++)
        {
            begining.insert(intervals[i][0]);
            ending.insert(intervals[i][1]);

            maxVal = max(maxVal, intervals[i][0]);
            maxVal = max(maxVal, intervals[i][1]);

            minVal = min(minVal, intervals[i][0]);
            minVal = min(minVal, intervals[i][1]);
        }
        int flgBegin = 1, beginInterval = 100000000, endInterval = -100000000;
        int countLeft = 0, countRight = 0;
        vector<vector<int>> ans;
        for (int i = minVal; i <= maxVal; i++)
        {
            if (begining.count(i) > 0)
            {
                countLeft += begining.count(i);
                beginInterval = min(i, beginInterval);
            }
            if (ending.count(i) > 0)
            {
                countRight += ending.count(i);
                endInterval = max(i, endInterval);
                if (countLeft == countRight)
                {
                    countRight = 0;
                    countLeft = 0;
                    vector<int> intervalPair;
                    intervalPair.push_back(beginInterval);
                    intervalPair.push_back(endInterval);
                    ans.push_back(intervalPair);
                    beginInterval = 100000000;
                    endInterval = -100000000;
                }
            }
        }
        return ans;
    }
};