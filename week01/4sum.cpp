class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> uniqueQuadruplets;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                int b = nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int rightHandSide = target - nums[i] - nums[j];
                    int leftHandSide = nums[l] + nums[r];
                    int c = nums[l];
                    int d = nums[r];
                    if (l < r - 1 && leftHandSide > rightHandSide)
                    {
                        r--;
                    }
                    else if (l + 1 < r && leftHandSide < rightHandSide)
                    {
                        l++;
                    }
                    else
                    {
                        if (leftHandSide == rightHandSide)
                        {
                            uniqueQuadruplets.push_back({a, b, c, d});
                        }
                        while (l + 1 < r && nums[l + 1] == nums[l])
                        {
                            l++;
                        }
                        while (r - 1 < nums.size() && nums[r] == nums[r - 1])
                        {
                            r--;
                        }
                        l++;
                        r--;
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return uniqueQuadruplets;
    }
};