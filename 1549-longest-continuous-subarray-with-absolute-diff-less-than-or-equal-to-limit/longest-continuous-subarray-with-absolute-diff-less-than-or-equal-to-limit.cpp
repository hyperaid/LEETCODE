class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int i=0;
        // int j=0;
        // int maxlen=0;
        // int maxdiff=0;
        // pair<int,int> maxele={nums[j],0};
        // // priority_queue<int>pq;
        // // set<int>
        // while(i<=j &&j<nums.size()){
        //     maxdiff=max(maxdiff,abs(nums[j]-maxele.first));
        //     maxele=max(maxele,{nums[j],j});
        //     if(maxdiff<=limit){
        //         maxlen=max(maxlen,j-i+1);
        //         if(nums[j]>maxele.first) maxele={nums[j],j};
        //         j++;
        //     }
        //     else{
        //         // while(maxdiff>limit && i<=j){
        //         //     maxdiff=nums[maxele.second+1]
        //         //     i=maxele.second+1;
        //         //     if(abs(nums[i]-nums[j])<=limit){
        //         //         maxdiff=abs(nums[i]-nums[j]);
        //         //     }
        //         //     // maxdiff=max(maxdiff,abs(nums[j]-nums[i])); 

        //         // }
        //         i=maxele.second+1;
        //         j=i;
        //         maxele={nums[i],i};
        //         maxdiff=0;

        //     }
        int i=0;
        int j=0;
        int maxlen=0;
        int n= nums.size();
        multiset<int>s;
        while(j<n){
            s.insert(nums[j]);
            int diff=*s.rbegin()-*s.begin();
            while(i<j && diff>limit){
                auto it=s.find(nums[i]);
                s.erase(it);
                diff=*s.rbegin()-*s.begin();
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }


        
        return maxlen;
    }
};