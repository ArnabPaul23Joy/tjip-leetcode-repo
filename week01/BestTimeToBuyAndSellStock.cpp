class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int leftIndx = prices.size() - 2, rightIndx = prices.size() - 1;
        while (leftIndx >= 0)
        {
            int tempProfit = prices[rightIndx] - prices[leftIndx];
            if (tempProfit < 0)
            {
                rightIndx = leftIndx;
            }
            if (tempProfit > profit)
            {
                profit = tempProfit;
            }
            leftIndx--;
        }
        return profit;
    }
};