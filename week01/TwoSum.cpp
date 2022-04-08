class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int total)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == total - nums[j])
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};