class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int profit = 0;
        int leftIndx = prices.size() - 2, rightIndx = prices.size() - 1;
        while (leftIndx >= 0)
        {
            int tempProfit = prices[rightIndx] - prices[leftIndx];

            if (tempProfit < 0)
            {
                rightIndx = leftIndx;
            }
            if (tempProfit >= 0)
            {
                ans = ans + tempProfit;
                rightIndx--;
            }

            leftIndx--;
        }
        return ans;
    }
};