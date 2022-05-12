class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=s.size()-1;
        int r=s.size()-1;
        int allChars[256]={0};
        int maxVal=0;
        while(l>=0){
            allChars[s[l]]++;
            if(allChars[s[l]]>1){
                
                while(true){
                    allChars[s[r]]--;
                    if(s[r]==s[l]){
                        r--;
                        break;
                    }
                    r--;
                }
            }
            maxVal=max(maxVal,r-l+1);
            l--;
        }
        return maxVal;
    }
};