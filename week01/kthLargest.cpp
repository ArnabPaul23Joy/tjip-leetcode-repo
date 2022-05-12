class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        int minVal = nums[0], maxVal = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (minVal > nums[i])
            {
                minVal = nums[i];
            }
            if (maxVal < nums[i])
            {
                maxVal = nums[i];
            }
        }
        unordered_multiset<int> allNums(nums.begin(), nums.end());
        int xthVal = 0;
        for (int i = maxVal; i >= minVal; i--)
        {
            int tempCount = allNums.count(i);
            if (tempCount > 0)
            {
                xthVal += tempCount;
                if (xthVal >= k)
                {
                    return i;
                }
            }
        }
        return minVal;
    }
};