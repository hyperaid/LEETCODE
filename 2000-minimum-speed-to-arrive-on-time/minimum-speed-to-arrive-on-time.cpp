class Solution {
public:
    
   bool isposs(vector<int>& dist, double hour,int mid){
       double a=0;
       for(int i=0;i<dist.size();i++){
           double ans=dist[i]*1.0/mid;
           if(i<dist.size()-1){
               a=a+ceil(ans);
           }
           else a+=ans;
           if(ans>hour) return false;
        }
        if(a<=hour) return true;
        return false;
   }
    int minSpeedOnTime(vector<int>& dist, double hour) {
            int i=0;
            int j=1e7;
            int mid;
            while(i<=j){
                mid=(i+j)/2;
                if(isposs(dist,hour,mid)){
                    j=mid-1;
                }
                else i=mid+1;
            }
            if(i>1e7) return -1;
            return i;
        
    }
};