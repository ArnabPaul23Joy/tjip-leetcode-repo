class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int nums1i = 0, nums2i = 0;
        vector<int> nums;
        for (; nums1i < m && nums2i < n;)
        {
            if (nums1[nums1i] < nums2[nums2i])
            {
                nums.push_back(nums1[nums1i]);
                nums1i++;
            }
            else
            {
                nums.push_back(nums2[nums2i]);
                nums2i++;
            }
        }
        while (nums1i < m)
        {
            nums.push_back(nums1[nums1i]);
            nums1i++;
        }

        while (nums2i < n)
        {
            nums.push_back(nums2[nums2i]);
            nums2i++;
        }
        nums1 = nums;
        return;
    }
};