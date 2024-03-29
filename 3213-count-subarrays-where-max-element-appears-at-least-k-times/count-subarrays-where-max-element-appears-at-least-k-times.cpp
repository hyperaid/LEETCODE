class Solution {
public:
    long long countSubarrays(vector<int>& nums,int k) {
        long long max_ele=LLONG_MIN;
        unordered_map<long long,long long> mpp;
        for(auto it:nums){
            max_ele=max(max_ele,(long long)it);
        }
        cout<<max_ele<<endl;
        long long occurance=-1;
        long long i=0,j=0;
        long long count=0;
        long long n=nums.size();
        while(i<n  && j<n){
            mpp[nums[j]]++;
            
            if(mpp[max_ele]>=k){
                while(mpp[max_ele]>=k){
                    count+=n-j;
                    mpp[nums[i]]--;
                    i++;
                }
                 
            }
             j++;
            
        }
        return count;
        

    }
};
