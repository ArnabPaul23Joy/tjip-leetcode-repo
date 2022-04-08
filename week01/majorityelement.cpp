class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorElement;
        int majorFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (majorFreq == 0)
            {
                majorFreq++;
                majorElement = nums[i];
            }
            else
            {
                if (majorElement != nums[i])
                {
                    majorFreq--;
                }
                else
                {
                    majorFreq++;
                }
            }
        }
        return majorElement;
    }
};