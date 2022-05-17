class Solution {
public:
    bool checkIsoMorph(string s, string t){
        unordered_map<char, char>charMapping;
        for(int i=0;i<s.size();i++){
            if(charMapping.count(t[i])==0){
                charMapping[t[i]]=s[i];
                continue;
            }
            if(charMapping[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return checkIsoMorph(s,t)&&checkIsoMorph(t,s);
    }
};