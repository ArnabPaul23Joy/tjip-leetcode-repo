class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long>coOrdinates;
        for(int i=0;i<points.size();i++){
            long long coOrd=points[i][0]*10000000000+points[i][1];
            coOrdinates.insert(coOrd);
        }
        int minArea=1000000000;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                long long pointA=points[i][0]*10000000000+points[i][1];
                long long pointC=points[j][0]*10000000000+points[j][1];
                long long pointB=points[i][0]*10000000000+points[j][1];
                long long pointD=points[j][0]*10000000000+points[i][1];
                
                if(points[i][0]!=points[j][0]
                   &&points[i][1]-points[j][1]
                   &&coOrdinates.find(pointB)!=coOrdinates.end()
                   &&coOrdinates.find(pointD)!=coOrdinates.end()){
                    
                    int area=abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]);
                    minArea=min(minArea,area);
                }
            }
        }
        if(minArea==1000000000) return 0;
        return minArea;
    }
};