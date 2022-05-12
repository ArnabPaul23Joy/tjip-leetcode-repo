class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allTriplets;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int L = i + 1;
            int R = (int)nums.size() - 1;
            while (L < R)
            {
                int a = nums[i], b = nums[L], c = nums[R];
                if (nums[L] + nums[R] > -nums[i])
                {
                    R--;
                }
                else if (nums[L] + nums[R] < -nums[i])
                {
                    L++;
                }
                else if (nums[L] + nums[R] == -nums[i])
                {
                    allTriplets.push_back({a, b, c});
                    while (L + 1 < R && nums[L + 1] == b)
                    {
                        L++;
                    }
                    while (L < R - 1 && nums[R - 1] == c)
                    {
                        R--;
                    }
                    L++;
                    R--;
                }
            }

            while (i + 1 < (int)nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return allTriplets;
    }
};