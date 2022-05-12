class Solution
{
public:
    string getJstifiedString(vector<string> words, int strtIndx, int endIndx, int maxWidth)
    {
        int noSpaceWidth = 0;
        for (int i = strtIndx; i <= endIndx; i++)
        {
            noSpaceWidth += words[i].length();
        }
        int totSpaces = maxWidth - noSpaceWidth;
        string justifiedString = words[strtIndx];
        if (endIndx - strtIndx != 0)
        {
            int spaceDist = totSpaces / (endIndx - strtIndx);
            int extraSpaces = totSpaces % (endIndx - strtIndx);
            for (int i = strtIndx + 1; i <= endIndx; i++)
            {
                string spaces = "";
                for (int j = 0; j < spaceDist; j++)
                {
                    spaces += ' ';
                }
                if (extraSpaces > 0)
                {
                    extraSpaces--;
                    spaces += ' ';
                }
                justifiedString += (spaces + words[i]);
            }
        }
        else
        {
            string spaces = "";
            for (int j = 0; j < totSpaces; j++)
            {
                spaces += ' ';
            }
            justifiedString += spaces;
        }
        return justifiedString;
    }
    string getLastString(string lastString, int maxWidth)
    {
        stringstream strStream(lastString);
        string str;
        string rightJustified = "";
        vector<string> allLastStrings;
        while (getline(strStream, str, ' '))
        {
            if (str != "" && str != " " && str != "\n")
                allLastStrings.push_back(str);
        }
        rightJustified += allLastStrings[0];
        for (int i = 1; i < allLastStrings.size(); i++)
        {
            rightJustified += " " + allLastStrings[i];
        }
        int extraSpaces = maxWidth - rightJustified.length();
        for (int i = 1; i <= extraSpaces; i++)
        {
            rightJustified += " ";
        }
        return rightJustified;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int tempLen = words[0].length();
        int strtIndx = 0, endIndx = 0;
        vector<string> justifiedString;
        bool stringCreated = false;
        for (int i = 1; i < words.size(); i++)
        {

            if (tempLen + 1 + words[i].length() < maxWidth)
            {
                tempLen += words[i].length() + 1;
                endIndx = i;
            }
            else if (tempLen + 1 + words[i].length() == maxWidth)
            {
                tempLen += words[i].length() + 1;
                endIndx = i;
                justifiedString.push_back(getJstifiedString(words, strtIndx, endIndx, maxWidth));
                stringCreated = true;
                if (i + 1 < words.size())
                {
                    strtIndx = i + 1;
                    endIndx = i + 1;
                    tempLen = words[i + 1].length();
                    i++;
                    stringCreated = false;
                }
                else
                {
                    break;
                }
            }
            else
            {
                stringCreated = true;
                justifiedString.push_back(getJstifiedString(words, strtIndx, endIndx, maxWidth));
                stringCreated = false;\
                strtIndx = i;
                endIndx = i;
                tempLen = words[i].length();
            }
        }
        if (!stringCreated)
            justifiedString.push_back(getJstifiedString(words, strtIndx, endIndx, maxWidth));
        justifiedString[justifiedString.size() - 1] = getLastString(justifiedString[justifiedString.size() - 1], maxWidth);
        return justifiedString;
    }
};