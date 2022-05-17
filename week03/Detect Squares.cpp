class DetectSquares {
public:
    unordered_map<long long, int>pointFreq;
    DetectSquares() {
        pointFreq.clear();
    }
    
    void add(vector<int> point) {
        long long coOrd=(long long)point[0]*10000000+(long long)point[1];
        pointFreq[coOrd]++;
        return;
    }
    bool checkSqr(int x1, int y1, int x2, int y2){
        return x1!=x2&&y1!=y2&&abs(x1-x2)==abs(y1-y2);
    }
    int getArea(int x1, int x2, int y1,  int y2){
        return abs(x2-x1)*(y2-y1);
    }
    int count(vector<int> point) {
        int x1=point[0], y1=point[1], totalSqrs=0;
        long long pointA=(long long)x1*10000000+(long long)y1;
        for(auto it:pointFreq){
            long long pointC=it.first;
            int val=it.second;
            int x2=(int)(pointC/10000000);
            int y2=(int)(pointC%10000000);
            if(checkSqr(x1,y1,x2,y2)){
                long long pointB=(long long)x1*10000000+(long long)y2;
                long long pointD=(long long)x2*10000000+(long long)y1;
                if(pointFreq.find(pointB)!=pointFreq.end()
                  &&pointFreq.find(pointD)!=pointFreq.end()){
                    totalSqrs+=pointFreq[pointB]*pointFreq[pointC]*pointFreq[pointD];
                }
            }
        }
        return totalSqrs;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */