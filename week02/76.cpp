class Solution
{
public:
    string minWindow(string s, string t)
    {
        int freq[256] = {0};
        int l = 0, r = 0, nonZeres = t.size();
        for (int i = 0; i < t.length(); i++)
        {
            freq[t[i]]++;
        }
        int minLength = 100000000, strtIndx = -1;
        while (r < s.length())
        {
            if (freq[s[r]] > 0)
            {
                nonZeres--;
            }
            freq[s[r]]--;
            r++;
            while (nonZeres == 0)
            {
                if (r - l <= minLength)
                {
                    minLength = r - l;
                    strtIndx = l;
                }
                if (freq[s[l]] == 0)
                {
                    nonZeres++;
                }
                freq[s[l]]++;
                l++;
            }
        }
        return strtIndx == -1 ? "" : s.substr(strtIndx, minLength);
    }
};