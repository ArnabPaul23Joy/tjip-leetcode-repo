class Solution
{
public:
    int compareStringPrefix(string a, string b, int aEnd)
    {
        for (int i = 0; i <= aEnd; i++)
        {
            if (a[i] != b[i])
            {
                return i - 1;
            }
        }
        return aEnd;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        int minVal = 1000;
        string minString = "";
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].length() < minVal)
            {
                minVal = strs[i].length();
                minString = strs[i];
            }
        }
        int minStringEnd = minString.length() - 1;
        for (int i = 0; i < strs.size(); i++)
        {
            if (minStringEnd < 0)
            {
                return "";
            }
            minStringEnd = compareStringPrefix(minString, strs[i], minStringEnd);
        }
        string lcp = "";
        for (int i = 0; i <= minStringEnd; i++)
        {
            lcp += minString[i];
        }
        return lcp;
    }
};