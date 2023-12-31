class Solution {
public:
    int rob(vector<int>& nums) {
     
   
        int n= nums.size();
        vector<int> sum(n);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        sum[0]=nums[0];
        sum[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            sum[i]=max(sum[i-1],sum[i-2]+nums[i]);
        }
        return sum[n-1];
    }
    
};