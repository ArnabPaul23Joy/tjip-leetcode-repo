class Solution{
public:
    void moveZeroes(vector<int> &nums)
    {
        int totalZero = 0;
        vector<int> tempNums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                totalZero++;
            }
            else
            {
                tempNums.push_back(nums[i]);
            }
        }
        for (int i = 0; i < totalZero; i++)
        {
            tempNums.push_back(0);
        }
        nums = tempNums;
    }
};