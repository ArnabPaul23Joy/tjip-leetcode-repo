class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<int> arr[26];
        for (int i = 0; i < 26; i++)
        {
            arr[i] = {};
        }
        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a'].push_back(i);
        }
        int totSubSeq = 0;
        vector<int>::iterator upperBnd;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int charIndx[26] = {0};
            int latestIndx = -1;
            int strIn = 0;
            for (; strIn < word.length(); strIn++)
            {
                char ch = word[strIn];
                if (arr[ch - 'a'].empty())
                {
                    break;
                }
                upperBnd = upper_bound(arr[ch - 'a'].begin(), arr[ch - 'a'].end(), latestIndx);
                latestIndx = upperBnd - arr[ch - 'a'].begin();
                if (latestIndx == arr[ch - 'a'].size())
                {
                    break;
                }
                latestIndx = arr[ch - 'a'][latestIndx];
            }
            if (strIn == word.length())
            {
                totSubSeq++;
            }
        }
        return totSubSeq;
    }
};