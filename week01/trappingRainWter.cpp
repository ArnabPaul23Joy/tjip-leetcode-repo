class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, l_max = 0, r_max = 0;

        int areaVal = 0;
        while (l < r)
        {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if (height[l] < height[r])
            {
                if (height[l] < l_max)
                {
                    areaVal += l_max - height[l];
                }
                l++;
            }
            else if (height[l] > height[r])
            {
                if (height[r] < r_max)
                {
                    areaVal += r_max - height[r];
                }

                r--;
            }
            else
            {
                r--;
            }
        }
        return areaVal;
    }
};