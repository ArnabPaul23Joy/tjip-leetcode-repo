class Solution
{
public:
    static bool comparefn(int a, int b)
    {
        if (a == 0)
            return false;
        if (b == 0)
            return true;
        int aDig = 0, bDig = 0;
        int tempA = a, tempB = b;
        while (tempA > 0)
        {
            tempA = tempA / 10;
            aDig++;
        }
        while (tempB > 0)
        {
            tempB = tempB / 10;
            bDig++;
        }
        int i = 0;
        for (; i < max(aDig, bDig); i++)
        {
            int aFront = 0, bFront = 0;
            if (aDig >= bDig)
            {
                aFront = a / ((int)pow(10, aDig - i - 1));
                aFront = aFront % 10;
                bFront = b / ((int)pow(10, bDig - (i % bDig) - 1));
                bFront = bFront % 10;
            }
            else
            {
                aFront = a / ((int)pow(10, aDig - (i % aDig) - 1));
                aFront = aFront % 10;
                bFront = b / ((int)pow(10, bDig - i - 1));
                bFront = bFront % 10;
            }
            if (aFront < bFront)
            {
                return false;
            }
            else if (aFront > bFront)
            {
                return true;
            }
        }
        if (aDig < bDig)
        {
            for (int i = bDig - 1; i >= 0; i--)
            {
                int frontDig = b / ((int)pow(10, i));
                frontDig = frontDig % 10;

                int backDig = b / ((int)pow(10, (i - aDig + bDig) % bDig));
                backDig = backDig % 10;
                if (frontDig > backDig)
                {
                    return true;
                }
                if (frontDig < backDig)
                {
                    return false;
                }
            }
            return false;
        }
        if (aDig > bDig)
        {
            for (int i = aDig - 1; i >= 0; i--)
            {
                int frontDig = a / ((int)pow(10, i));
                frontDig = frontDig % 10;

                int backDig = a / ((int)pow(10, (i - bDig + aDig) % aDig));
                backDig = backDig % 10;
                if (frontDig > backDig)
                {
                    return false;
                }
                if (frontDig < backDig)
                {
                    return true;
                }
            }
            return true;
        }
        return true;
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comparefn);
        string largeNum = "";
        for (int i = 0; i < nums.size(); i++)
        {
            largeNum += to_string(nums[i]);
        }
        string tempString = "";
        bool flg = false;
        for (int i = 0; i < largeNum.size() - 1; i++)
        {
            if (largeNum[i] != '0' || flg)
            {
                flg = true;
                tempString += largeNum[i];
            }
        }
        tempString += largeNum[largeNum.size() - 1];
        return tempString;
    }
};