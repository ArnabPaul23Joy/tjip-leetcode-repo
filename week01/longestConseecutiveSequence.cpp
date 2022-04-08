class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> allNums(nums.begin(), nums.end());
        int maxSeqLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (allNums.count(nums[i] - 1) == 0)
            {
                int seqLength = 0;
                for (int j = nums[i]; allNums.count(j) > 0; j++)
                {
                    seqLength++;
                }
                maxSeqLength = max(maxSeqLength, seqLength);
            }
        }
        return maxSeqLength;
    }
};