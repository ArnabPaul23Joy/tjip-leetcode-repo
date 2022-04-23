class Solution {
public:
    int longestSubstring(string s, int k) {
        
        stack<pair<int,int>>stckStr;
        stckStr.push({0,s.size()-1});
        int longLen=0;
        while(!stckStr.empty()){
            pair<int,int> interval=stckStr.top();
            stckStr.pop();
            int freq[26]={0};
            for(int i=interval.first;i<=interval.second;i++){
                freq[s[i]-'a']++;
            }
            int i=interval.first;
            bool flg=true;
            for(;i<=interval.second;i++){
                if(freq[s[i]-'a']<k){
                    if(i-1>=interval.first)
                        stckStr.push({interval.first, i-1});
                    while(i<=interval.second && freq[s[i]-'a']<k){
                        i++;
                    }
                    
                    if(i<=interval.second){
                        stckStr.push({i, interval.second});
                    }
                    else{
                        flg=false;
                    }
                    break;
                }
            }
            if(i>interval.second && flg){
                longLen=max(longLen,interval.second+1-interval.first);
            }
        }
        return longLen;
    }
};