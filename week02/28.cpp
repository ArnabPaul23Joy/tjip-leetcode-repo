class Solution
{
public:
    long long getPowVal(long long a, long long b, long long m)
    {
        long long aPow = 1;
        for (long long i = 0; i < b; i++)
        {
            aPow = (aPow * a) % m;
        }
        return aPow;
    }
    long long getLeftShift(long long a, long long leftVal, long long m)
    {
        for (long long i = 0; i < leftVal; i++)
        {
            a = (a * 26) % m;
        }
        return a;
    }
    int strStr(string haystack, string needle)
    {
        long long hashVal[10007] = {0};
        long long MOD = (long long)pow(10, 9) + 7;
        hashVal[1] = (haystack[0] - 97) % MOD;
        for (long long i = 2; i <= haystack.length(); i++)
        {
            hashVal[i] = ((hashVal[i - 1] * 26) % MOD + haystack[i - 1] - 97) % MOD;
        }
        long long needleHash = 0;
        for (long long i = 0; i < needle.length(); i++)
        {
            needleHash = (needleHash + (getPowVal(26, needle.length() - 1 - i, MOD) * (needle[i] - 97)) % MOD) % MOD;
        }
        int strtIndx = 0, endIndx = needle.length();
        for (; endIndx <= haystack.length(); strtIndx++, endIndx++)
        {
            long long leftHashVal = getLeftShift(hashVal[endIndx - needle.length()], needle.length(), MOD);
            if (((hashVal[endIndx] - leftHashVal) % MOD + MOD) % MOD == needleHash)
            {
                return endIndx - needle.length();
            }
        }
        return -1;
    }
};