class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int allLetters[26] = {0}, totChar = 0;
        for (int i = 0; i < s.size(); i++)
        {
            allLetters[s[i] - 'a']++;
            allLetters[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (allLetters[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};