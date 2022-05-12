class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int freq[60005] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 30000]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i] + 30000] == 1)
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};