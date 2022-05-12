#include <list>

class Solution {
public:
    /**
     * @param strings: a string array
     * @return: return a list of string array
     */

    long long getHash(string &a){
        long long m=1000000000+7;
        long long hashVal=0;
        for(long long i=0;i+1<a.size();i++){
            long long dif=(a[i+1]-a[i]+26)%26+1;
            long long twentySixPow=1;
            twentySixPow=(((twentySixPow*26)%m)*dif)%m;
            hashVal+=twentySixPow;
            hashVal=hashVal%m;
        }
        return hashVal;
    }
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<long long, vector<string>>hashedStrs;

        for(auto str: strings){
            int hashVal=getHash(str);
            hashedStrs[hashVal].push_back(str);
        }
        vector<vector<string>>strGroups;

        for(auto it: hashedStrs){
            strGroups.push_back(it.second);
        }
        return strGroups;
    }
};