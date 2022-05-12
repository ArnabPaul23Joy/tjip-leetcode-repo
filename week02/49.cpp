class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> stringGrpIndx;
        vector<vector<string>> allStrGrp;
        int charFreq[26] = {0};
        for (int i = 0, strIndx = 0; i < strs.size(); i++)
        {
            for (int l = 0; l < strs[i].length(); l++)
            {
                charFreq[strs[i][l] - 'a']++;
            }
            string keyString = "";
            for (int ch = 'a' + 0; ch <= 'z' + 0; ch++)
            {
                for (int l = 0; l < charFreq[ch - 'a']; l++)
                {
                    keyString += char(ch);
                }
                charFreq[ch - 'a'] = 0;
            }
            if (stringGrpIndx.find(keyString) != stringGrpIndx.end())
            {
                allStrGrp[stringGrpIndx[keyString]].push_back(strs[i]);
            }
            else
            {
                stringGrpIndx[keyString] = strIndx;
                vector<string> tempVc;
                tempVc.push_back(strs[i]);
                allStrGrp.push_back(tempVc);
                strIndx++;
            }
        }
        return allStrGrp;
    }
};