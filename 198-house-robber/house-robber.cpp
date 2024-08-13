class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==0){
            return nums[0]; 
        }
        if(i==1) return max(nums[1],nums[0]);
        if(dp[i]!=-1) return dp[i];
        int take=INT_MIN;
        if(i-2>=0){
            take=nums[i]+solve(i-2,nums,dp);
        }
        int n_take=solve(i-1,nums,dp);
        return dp[i]=max(take,n_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        // if((n+1)==2) return max(nums[0],nums[1])
        vector<int>dp(n+1,-1);
        return solve(n,nums,dp);
    }
};