class Solution
{
public:
    struct StrRplc
    {
        int indx;
        string trg, src;
        bool operator<(StrRplc b) const
        {
            return indx < b.indx;
        }
    };
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        string replcedStr = "";
        vector<StrRplc> allstrrplc;
        for (int i = 0; i < indices.size(); i++)
        {
            StrRplc aStr;
            aStr.indx = indices[i];
            aStr.trg = targets[i];
            aStr.src = sources[i];
            allstrrplc.push_back(aStr);
        }
        sort(allstrrplc.begin(), allstrrplc.end());
        for (int i = 0, trgInd = 0; i < s.length(); i++)
        {
            if (trgInd < allstrrplc.size() && i == allstrrplc[trgInd].indx)
            {
                int srcInd = 0, chckS = i;
                string source = allstrrplc[trgInd].src;
                string target = allstrrplc[trgInd].trg;
                for (; srcInd < source.size(); srcInd++, chckS++)
                {
                    if (source[srcInd] != s[chckS])
                        break;
                }
                if (srcInd != source.size())
                {
                    replcedStr += s[i];
                    trgInd++;
                    continue;
                }
                replcedStr += target;
                for (int srcInd = 0; srcInd < source.size() - 1; srcInd++)
                {
                    i++;
                }
                trgInd++;
            }
            else
            {
                replcedStr += s[i];
            }
        }
        return replcedStr;
    }
};