class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>a;
        for(int i=0;i<wage.size();i++){
            a.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(a.begin(),a.end());
        priority_queue<int>pq;
        double b=0;
        double ans=100000000000;

       for(auto work:a){
            double ratio=work.first;
            b+=work.second;
            pq.push(work.second);
            if(pq.size()>k){
                b-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=min(ans,b*ratio);
            }
       }
       return ans;
    }
};


 