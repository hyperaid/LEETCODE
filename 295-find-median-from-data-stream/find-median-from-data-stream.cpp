class MedianFinder {
public:
    priority_queue<double>inc;
    priority_queue<double,vector<double>,greater<double>>dec;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(inc.empty() ||inc.top()>=num) inc.push(num);
        else dec.push(num);
        int n=inc.size();
        int m=dec.size();
        if(abs(n-m)>1){
            if(inc.size()>dec.size()){
                dec.push(inc.top());
                inc.pop();
            }
            else{
                inc.push(dec.top());
                dec.pop();
            }
        }
    }
    
    double findMedian() {
        int n=inc.size();
        int m=dec.size();
        if((n+m)%2==0){
            return (inc.top()+dec.top())/2;
        }
        else{
            if(n>m) return inc.top();
            else return dec.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */