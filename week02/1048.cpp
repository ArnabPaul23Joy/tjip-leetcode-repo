class Solution {
public:
    string getSubStr(string s, int strt, int len){
        return len<=0?"":s.substr(strt,len);
    }
    bool static compare(string a, string b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), compare);
        unordered_map<string,int>dp;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            int maxVal=1;
            for(int j=1;j<=word.size();j++){
                string key="";
                key+=getSubStr(word, 0, j-1);
                key+=getSubStr(word, j, word.size()-j);
                if(dp.find(key)!=dp.end()){
                    maxVal=max(maxVal, dp[key]+1);
                }
            }
            dp[word]=maxVal;
        }
        int maxVal=-1;
        for(int i=0;i<words.size();i++){
            maxVal=max(maxVal,dp[words[i]]);
        }
        return maxVal;
    }
};