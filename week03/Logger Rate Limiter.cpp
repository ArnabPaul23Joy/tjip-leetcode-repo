class Logger
{
public:
    unordered_map<string, long long> strTimeStmp;
    Logger()
    {
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (strTimeStmp.count(message) == 0)
        {
            strTimeStmp[message] = timestamp + 10;
            return true;
        }
        if (timestamp < strTimeStmp[message])
        {
            return false;
        }
        strTimeStmp[message] = timestamp + 10;
        return true;
    }
};