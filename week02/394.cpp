class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> stckStr;
        bool strtDig = false;
        string freq = "";
        string repStr = "";
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] >= '0' && s[i] <= '9')
            {
                freq += s[i];
                if (i > 0)
                {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
                    {
                        stckStr.push(repStr);
                        repStr = "";
                    }
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                repStr += s[i];
            }
            else if (s[i] == '[')
            {
                stckStr.push(freq);
                freq = "";
            }
            else if (s[i] == ']')
            {
                if (repStr != "")
                    stckStr.push(repStr);
                repStr = "";

                string tempStcTop = "";
                while (true)
                {
                    string tempStr = stckStr.top();
                    stckStr.pop();
                    if (tempStr[0] >= 'a' && tempStr[0] <= 'z')
                    {
                        tempStcTop = tempStr + tempStcTop;
                    }
                    else
                    {
                        int strFreq = stoi(tempStr);
                        string tempAddStr = tempStcTop;
                        for (int f = 0; f < strFreq - 1; f++)
                        {
                            tempStcTop += tempAddStr;
                        }
                        stckStr.push(tempStcTop);
                        tempStcTop = "";
                        break;
                    }
                }
            }
        }
        if (repStr.length() > 0)
        {
            stckStr.push(repStr);
        }
        string ansStr = "";

        while (!stckStr.empty())
        {
            ansStr = stckStr.top() + ansStr;
            stckStr.pop();
        }
        return ansStr;
    }
};