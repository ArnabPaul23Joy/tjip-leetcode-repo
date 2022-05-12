class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_set<int> allNums(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {
            if (allNums.count(i) == 0)
            {
                return i;
            }
        }
        return nums.size() + 1;
    }
};