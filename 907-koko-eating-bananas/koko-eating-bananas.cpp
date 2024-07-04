class Solution {
public:
    int minEatingSpeed(vector<int>& stalls, int h) {
        long long low=0;
        int high=0;
        int n=stalls.size();
        int ans;
        for(int i=0;i<n;i++){
            low+=stalls[i];
            high=max(high,stalls[i]);
        }
        low=low/h;
        if(low==0) low=1;
        while(low<=high){
            int mid=(low+high)>>1;
            int count=0;
            for(int i=0;i<n;i++){
                count+=stalls[i]/mid;
                if(stalls[i]%mid!=0){
                    count++;
                }
            }
            if(count>h){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};