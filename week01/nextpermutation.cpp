class Solution
{
public:
    void reversePortion(vector<int> &nums, int strtIndx)
    {
        int l = strtIndx;
        int r = nums.size() - 1;
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return;
    }
    void nextPermutation(vector<int> &nums)
    {
        int leftSwapIndx = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                leftSwapIndx = i - 1;
            }
        }
        int rightSwapIndx = leftSwapIndx + 1;
        for (int i = rightSwapIndx + 1; i < nums.size() && leftSwapIndx >= 0; i++)
        {
            if (nums[i] > nums[leftSwapIndx])
            {
                rightSwapIndx = i;
                // break;
            }
        }
        if (leftSwapIndx >= 0)
        {
            swap(nums[rightSwapIndx], nums[leftSwapIndx]);
        }
        reversePortion(nums, leftSwapIndx + 1);
        return;
    }
};