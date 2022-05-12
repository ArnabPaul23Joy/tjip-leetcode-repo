class Solution
{
public:
    string removeSpaces(string s)
    {
        string str = "";
        bool checkLeadingSpace = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                str += s[i];
                checkLeadingSpace = true;
            }
            else
            {
                if (checkLeadingSpace)
                {
                    str += s[i];
                }
            }
        }

        s = "";
        if (str[0] == '+')
        {
            for (int i = 1; i < str.size(); i++)
            {
                if (str[i] >= (0 + '0') && str[i] <= (9 + '0'))
                {
                    s += str[i];
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (str[0] == '-')
            {
                s += str[0];
                for (int i = 1; i < str.size(); i++)
                {
                    if (str[i] >= (0 + '0') && str[i] <= (9 + '0'))
                    {
                        s += str[i];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] >= (0 + '0') && str[i] <= (9 + '0'))
                    {
                        s += str[i];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return s;
    }
    int myAtoi(string s)
    {
        long long longVal = 0;
        s = removeSpaces(s);
        if (s[0] == '-')
        {
            for (int i = s.size() - 1; i >= 1; i--)
            {
                long long digitVal = s[i] - '0';
                if (digitVal != 0)
                {
                    if (s.size() - 1 - i > 18)
                    {
                        int intVal = -(long long)pow(2, 31);
                        return intVal;
                    }
                    longVal = longVal + (long long)pow(10, s.size() - 1 - i) * digitVal;
                }
                // cout<<"longVal   "<<longVal<<endl;
                if (longVal != longVal % ((long long)pow(2, 31) + 1))
                {
                    int intVal = (-1) * (long long)pow(2, 31);
                    return intVal;
                }
            }
            int intVal = (-1) * longVal;
            return intVal;
        }
        else
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                long long digitVal = s[i] - '0';
                if (digitVal != 0)
                {
                    if (s.size() - 1 - i > 18)
                    {
                        return pow(2, 31) - 1;
                    }
                    longVal = longVal + (long long)pow(10, s.size() - 1 - i) * digitVal;
                }
                if (longVal != longVal % ((long long)pow(2, 31)))
                {
                    return pow(2, 31) - 1;
                }
            }
            int intVal = (int)longVal;
            return intVal;
        }
    }
};