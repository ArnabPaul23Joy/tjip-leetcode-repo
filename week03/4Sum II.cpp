class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_multiset<int>leftHand;
        unordered_map<int,int>leftHndFreq;
        
        int fourCount=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                leftHand.insert(nums1[i]+nums2[j]);
            }
        }
        for(auto it:leftHand){
            if(leftHndFreq.find(it)==leftHndFreq.end())
                leftHndFreq[it]=leftHand.count(it);
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int rightSide=nums3[i]+nums4[j];
                rightSide=(-1)*rightSide;
                fourCount+=leftHndFreq[rightSide];
            }
        }
        return fourCount;
    }
};n