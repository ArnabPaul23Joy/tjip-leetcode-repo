class Solution {
public:
    int getAllUglys(int n){
        vector<int>allUglies;
        long long arr2[33], temp2=1;
        for(int i=0;i<33;i++){
            arr2[i]=temp2;
            temp2=temp2*2;
        }
        long long arr3[23], temp3=1;
        for(int i=0;i<23;i++){
            arr3[i]=temp3;
            temp3=temp3*3;
        }
        long long arr5[15], temp5=1;
        for(int i=0;i<15;i++){
            arr5[i]=temp5;
            temp5=temp5*5;
        }
        for(int i=0;i<33;i++){
            long long ugly2=arr2[i];
            if(ugly2>INT_MAX){
                break;
            }
            for(int j=0;j<24;j++){
                long long ugly3=ugly2*arr3[j];
                if(ugly3>INT_MAX){
                    break;
                }
                for(int k=0;k<15;k++){                    
                    long long ugly5=ugly3*arr5[k];
                    if(ugly5>INT_MAX){
                        break;
                    }
                    allUglies.push_back(ugly5);
                }
            }
        }
        sort(allUglies.begin(),allUglies.end());
        
        return allUglies[n-1];
        
    }
    int nthUglyNumber(int n) {
        return getAllUglys(n);
    }
};