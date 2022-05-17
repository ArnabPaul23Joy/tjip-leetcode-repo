class Solution
{
public:
    unordered_map<string, int> initRomMap(unordered_map<string, int> romToNum)
    {
        romToNum["I"] = 1;
        romToNum["V"] = 5;
        romToNum["IV"] = 4;
        romToNum["X"] = 10;
        romToNum["IX"] = 9;
        romToNum["L"] = 50;
        romToNum["XL"] = 40;
        romToNum["C"] = 100;
        romToNum["XC"] = 90;
        romToNum["D"] = 500;
        romToNum["CD"] = 400;
        romToNum["M"] = 1000;
        romToNum["CM"] = 900;
        return romToNum;
    }
    unordered_map<char, char> initChkPrev(unordered_map<char, char>
                                              chkPrev)
    {
        chkPrev['V'] = 'I';
        chkPrev['X'] = 'I';
        chkPrev['L'] = 'X';
        chkPrev['C'] = 'X';
        chkPrev['D'] = 'C';
        chkPrev['M'] = 'C';
        return chkPrev;
    }
    bool checkPrev(char prevChar, char curChar,
                   unordered_map<char, char> chkPrev)
    {
        if (chkPrev.find(curChar) != chkPrev.end() &&
            chkPrev[curChar] == prevChar)
            return true;
        return false;
    }
    int romanToInt(string s)
    {
        unordered_map<string, int> romToNum;
        unordered_map<char, char> chkPrev;
        romToNum = initRomMap(romToNum);
        chkPrev = initChkPrev(chkPrev);
        int numVal = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            string romNum = "";
            if (i - 1 >= 0 && checkPrev(s[i - 1], s[i], chkPrev))
            {
                romNum += s[i - 1];
                romNum += s[i];
                numVal += romToNum[romNum];
                i--;
                continue;
            }
            romNum += s[i];
            numVal += romToNum[romNum];
        }
        return numVal;
    }
};